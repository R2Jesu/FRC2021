/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Robot.h"


double Robot::turning;
double Robot::currentDistance;

void Robot::AutonomousInit() 
{
  jaws.Set(frc::DoubleSolenoid::Value::kReverse);
  m_encL.Reset();
  m_encR.Reset();

  m_timer.Reset();
  m_timer.Start();  
  //R2Jesu_Slalom();
  //R2Jesu_Barrel();
  //R2Jesu_Bounce();

}

void Robot::AutonomousPeriodic() 
{  
  R2Jesu_Autonomous();
/*if ((frc::SmartDashboard::GetString("autonomous course", "0") == "1") 
  && (frc::SmartDashboard::GetString("has bounce run", "n") == "n")) {
  R2Jesu_Bounce(); 
  frc::SmartDashboard::PutString("has bounce run", "y");
}

if ((frc::SmartDashboard::GetString("autonomous course", "0") == "2") 
  && (frc::SmartDashboard::GetString("has slalom run", "n") == "n")) {
  R2Jesu_Slalom(); 
  frc::SmartDashboard::PutString("has slalom run", "y");
}

if ((frc::SmartDashboard::GetString("autonomous course", "0") == "3") 
  && (frc::SmartDashboard::GetString("has barrel run", "n") == "n")) {
  R2Jesu_Barrel(); 
  frc::SmartDashboard::PutString("has barrel run", "y");
}*/

}

void Robot::RobotInit()
{
  // Init Timer
  m_timer.Start();

  // Init Robot Drive
  m_robotDrive.SetExpiration(0.1);
  m_drvL = 0.0;
  m_drvR = 0.0;

// Init Shooter Drive
#if R2JESU_TURNON_SHOOTER
  m_ShooterMotorLeft.RestoreFactoryDefaults();
  m_ShooterMotorRight.RestoreFactoryDefaults();
  //  Invert the right motor
  m_ShooterMotorRight.SetInverted(true);
#endif

// Init Winch Drive
#if R2JESU_TURNON_WINCH
  m_winchMotor.Set(0.0);
#endif

// Init Intake Drive
#if R2JESU_TURNON_INTAKE
  snowMotor.Set(0.0);
#endif

  //  Init Color Sensor
  m_colorMatcher.AddColorMatch(kBlueTarget);
  m_colorMatcher.AddColorMatch(kGreenTarget);
  m_colorMatcher.AddColorMatch(kRedTarget);
  m_colorMatcher.AddColorMatch(kYellowTarget);
  m_colorMatcher.AddColorMatch(Default);

  // Run Pneumatics
#if R2JESU_TURNON_PNEUMATICS
  // Set Compressor Object for automatic closed loop control
  compressorObject.SetClosedLoopControl(true);
  // Set Solenoids to iniital stat
  ballPopper.Set(false);
  //double solenoid starts up   
  jaws.Set(frc::DoubleSolenoid::Value::kForward);
#endif

// NavX Sensor
#if R2JESU_TURNON_NAV
  ahrs = new AHRS(frc::SPI::Port::kMXP);
  ahrs->Reset();
#endif
m_encL.Reset();
m_encR.Reset();
m_encL.SetDistancePerPulse(1.0 / 2048.0 * 2.0 * wpi::math::pi * 3.0);
m_encR.SetDistancePerPulse(1.0 / 2048.0 * 2.0 * wpi::math::pi * 3.0);
  // Vision & Camera Init

  // Drive USB Camera - 1
  cs::UsbCamera drvCamera = frc::CameraServer::GetInstance()->StartAutomaticCapture(0);
  drvCamera.SetResolution(320, 240);
  drvCamera.SetExposureAuto();
  drvCamera.SetFPS(15);
  frc::SmartDashboard::PutString("has slalom run", "n");
  frc::SmartDashboard::PutString("has barrel run", "n");
  frc::SmartDashboard::PutString("has bounce run", "n");

  frc::SmartDashboard::PutString("autonomous course", "0");

  frc::SmartDashboard::PutNumber("manual power", 0.00);
}

void Robot::RobotPeriodic(){
  
/*
frc::SmartDashboard::PutNumber("IMU_Yaw", ahrs->GetYaw());
frc::SmartDashboard::PutNumber("IMU_Pitch", ahrs->GetPitch());
frc::SmartDashboard::PutNumber("IMU_Roll", ahrs->GetRoll());
frc::SmartDashboard::PutNumber("IMU_CompassHeading", ahrs->GetCompassHeading());
frc::SmartDashboard::PutNumber("IMU_Accel_X", ahrs->GetWorldLinearAccelX());
frc::SmartDashboard::PutNumber("IMU_Accel_Y", ahrs->GetWorldLinearAccelY());
frc::SmartDashboard::PutNumber("Displacement_X", ahrs->GetDisplacementX());
frc::SmartDashboard::PutNumber("Displacement_Y", ahrs->GetDisplacementY());
frc::SmartDashboard::PutNumber("RawGyro_X", ahrs->GetRawGyroX());
frc::SmartDashboard::PutNumber("RawGyro_Y", ahrs->GetRawGyroY());
frc::SmartDashboard::PutNumber("RawGyro_Z", ahrs->GetRawGyroZ());
frc::SmartDashboard::PutNumber("Angle", ahrs->GetAngle());


frc::SmartDashboard::PutNumber("Left Encoder Cout", m_encL.Get());
frc::SmartDashboard::PutNumber("Left Encoder Distance", m_encL.GetDistance());
frc::SmartDashboard::PutNumber("Right Encoder Distance", m_encR.GetDistance());
frc::SmartDashboard::PutNumber("Right Encoder Cout", m_encR.Get());
*/
R2Jesu_Limelight();

}

void Robot::TeleopInit()
{
  gameColor = nun;
  m_ShooterMotorLeft.Set(0.0);
  m_ShooterMotorRight.Set(0.0);
}

void Robot::TeleopPeriodic()
{

  // Set the target color
  R2Jesu_CheckGameTargetColor();

  // Process intake motor commands
  R2Jesu_ProcessIntake();

  // Process user control before drive control.
  R2Jesu_ProcessUserControl();

  // Note this needs to come last to merge other drive motor request.
  R2Jesu_ProcessDrive();
}

void Robot::TestPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main()
{
  return frc::StartRobot<Robot>();
}
#endif
