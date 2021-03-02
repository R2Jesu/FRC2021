#include "Robot.h"
//right of left box

void Robot::R2Jesu_Barrel() 
{
   double correction;
  ahrs -> ZeroYaw();
  m_encL.Reset();
  m_encR.Reset();
  while ((m_encL.GetDistance() < 125.0) && (m_encR.GetDistance() < 125.0)) {
     correction = .1 * (-5 - ahrs->GetYaw());
    if (correction > .375){
      correction = .375;}
    if (correction < -.375){
      correction = -.375; 
    }
    frc::SmartDashboard::PutNumber("IMU_Yaw", ahrs->GetYaw());
    m_robotDrive.ArcadeDrive(0.5, correction, true);
  }  
   
    while ((ahrs->GetYaw() > -10) || (ahrs->GetYaw() < -20)) {
    m_robotDrive.ArcadeDrive(0.5, 0.35, true);
    frc::SmartDashboard::PutNumber("IMU_Yaw", ahrs->GetYaw());}
     m_robotDrive.ArcadeDrive(0, 0, true);

        m_encL.Reset();
        m_encR.Reset();

    while ((m_encL.GetDistance() < 88.0) && (m_encR.GetDistance() < 88.0)) {
     correction = .1 * (0 - ahrs->GetYaw());
    if (correction > .375){
      correction = .375;}
    if (correction < -.375){
      correction = -.375; 
    }
    frc::SmartDashboard::PutNumber("IMU_Yaw", ahrs->GetYaw());
    m_robotDrive.ArcadeDrive(0.5, correction, true);
  }  
  
    while ((ahrs->GetYaw() > 55) || (ahrs->GetYaw() < 45)) {
    m_robotDrive.ArcadeDrive(0.5, -0.325, true);
    frc::SmartDashboard::PutNumber("IMU_Yaw", ahrs->GetYaw());}
     m_robotDrive.ArcadeDrive(0, 0, true);

       m_encL.Reset();
        m_encR.Reset();

    while ((m_encL.GetDistance() < 95.0) && (m_encR.GetDistance() < 95.0)) {
     correction = .1 * (45 - ahrs->GetYaw());
    if (correction > .375){
      correction = .375;}
    if (correction < -.375){
      correction = -.375; 
    }
    frc::SmartDashboard::PutNumber("IMU_Yaw", ahrs->GetYaw());
    m_robotDrive.ArcadeDrive(0.5, correction, true);
  }  
//-172 -178
  while ((ahrs->GetYaw() > -165 ) || (ahrs->GetYaw() < -170)) {
    m_robotDrive.ArcadeDrive(0.5, -0.325, true);
    frc::SmartDashboard::PutNumber("IMU_Yaw", ahrs->GetYaw());}
     m_robotDrive.ArcadeDrive(0, 0, true);

     m_encL.Reset();
     m_encR.Reset();

     while ((m_encL.GetDistance() < 228.0) && (m_encR.GetDistance() < 228.0)) {
    correction = .1 * (180 - ahrs->GetYaw());
    if (correction == 36){
      correction = 0;
    }
    if ((correction < 36) && (correction > 18)){
      correction = -.23;
    }
    if (correction < -.23){
      correction = -.23;
    }
    if (correction > .23){
      correction = .23;
    }
      m_robotDrive.ArcadeDrive(0.7, correction, true);
    } 

        m_robotDrive.ArcadeDrive(0, 0, true);

}