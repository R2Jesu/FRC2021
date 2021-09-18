/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Robot.h"
double l_mtrPwr = -0.4;
double r_mtrPwr = -0.4;
double shooterPower = 0.0;
double trpm = -2000;

void Robot::R2Jesu_ProcessShooter()
{ 
  //trpm = frc::SmartDashboard::GetNumber("our rpm", trpm);
  //frc::SmartDashboard::PutNumber("our rpm", trpm); 
  //trpm = -1*((.0136*(currentDistance)*(currentDistance)) - (5.255*currentDistance) + 2709.6112);
  trpm = -1*((.02195*(currentDistance)*(currentDistance)) - (7.874 * currentDistance) + 2895);
if (m_OperatorStick.GetThrottle() > 0.3)
{
  // Control shooter
 // double shooterPower = ((12.6 - frc::DriverStation::GetInstance().GetBatteryVoltage()) / 100) + ((currentDistance * .0004761905) + .3057143);
 

  //shooterPower = frc::SmartDashboard::GetNumber("manual power", shooterPower);
  frc::SmartDashboard::PutNumber("target rpm", trpm);
  frc::SmartDashboard::PutNumber("current rpm", m_ShooterEncoderLeft.GetVelocity());
  frc::SmartDashboard::PutNumber("right rpm", m_ShooterEncoderRight.GetVelocity());
  if ((m_ShooterEncoderLeft.GetVelocity() < trpm) && ((trpm - m_ShooterEncoderLeft.GetVelocity()) >= 1))
  {
    l_mtrPwr = l_mtrPwr + .0001; 
    m_ShooterMotorLeft.Set(l_mtrPwr);
  }
  if ((m_ShooterEncoderLeft.GetVelocity() > trpm) && ((trpm - m_ShooterEncoderLeft.GetVelocity()) <= -1))
  {
    l_mtrPwr = l_mtrPwr - .0001; 
    m_ShooterMotorLeft.Set(l_mtrPwr);
  }
    if ((m_ShooterEncoderRight.GetVelocity() < trpm) && ((trpm - m_ShooterEncoderRight.GetVelocity()) >= 1))
  {
    r_mtrPwr = r_mtrPwr + .0001; 
    m_ShooterMotorRight.Set(r_mtrPwr);
  }
  if ((m_ShooterEncoderRight.GetVelocity() > trpm) && ((trpm - m_ShooterEncoderRight.GetVelocity()) <= -1))
  {
    r_mtrPwr = r_mtrPwr - .0001; 
    m_ShooterMotorRight.Set(r_mtrPwr);
  }
} else 
{
  m_ShooterMotorRight.Set(0);
  m_ShooterMotorLeft.Set(0);
}
frc::SmartDashboard::PutNumber("shooter power", shooterPower);  


// Shoot the ball
#if R2JESU_TURNON_PNEUMATICS

  if (m_OperatorStick.GetRawButton(2))
    ballPopper.Set(true);
  else
    ballPopper.Set(false);

#endif

#if R2JESU_TURNON_SMARTDASHBOARD
  frc::SmartDashboard::PutNumber("ShooterMtr", l_mtrPwr);
#endif
}
