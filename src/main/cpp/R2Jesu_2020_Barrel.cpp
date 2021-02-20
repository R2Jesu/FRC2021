#include "Robot.h"

void Robot::R2Jesu_Barrel() 
{
   double correction;
  ahrs -> ZeroYaw();
  m_encL.Reset();
  m_encR.Reset();
  while ((m_encL.GetDistance() < 130.0) && (m_encR.GetDistance() < 130.0)) {
     correction = .1 * (0 - ahrs->GetAngle());
    if (correction > .3){
      correction = .3;}
    if (correction < -.3){
      correction = -.3; 
    }
    frc::SmartDashboard::PutNumber("IMU_Yaw", ahrs->GetYaw());
    m_robotDrive.ArcadeDrive(0.4, correction, true);
  }  
   
    while ((ahrs->GetYaw() > -10) || (ahrs->GetYaw() < -20)) {
    m_robotDrive.ArcadeDrive(0.4, 0.3, true);
    frc::SmartDashboard::PutNumber("IMU_Yaw", ahrs->GetYaw());}
     m_robotDrive.ArcadeDrive(0, 0, true);

        m_encL.Reset();
        m_encR.Reset();

    while ((m_encL.GetDistance() < 95.0) && (m_encR.GetDistance() < 95.0)) {
     correction = .1 * (-5 - ahrs->GetAngle());
    if (correction > .3){
      correction = .3;}
    if (correction < -.3){
      correction = -.3; 
    }
    frc::SmartDashboard::PutNumber("IMU_Yaw", ahrs->GetYaw());
    m_robotDrive.ArcadeDrive(0.4, correction, true);
  }  
  
    while ((ahrs->GetYaw() > 50) || (ahrs->GetYaw() < 40)) {
    m_robotDrive.ArcadeDrive(0.4, -0.3, true);
    frc::SmartDashboard::PutNumber("IMU_Yaw", ahrs->GetYaw());}
     m_robotDrive.ArcadeDrive(0, 0, true);

       m_encL.Reset();
        m_encR.Reset();

    while ((m_encL.GetDistance() < 95.0) && (m_encR.GetDistance() < 95.0)) {
     correction = .1 * (45 - ahrs->GetAngle());
    if (correction > .3){
      correction = .3;}
    if (correction < -.3){
      correction = -.3; 
    }
    frc::SmartDashboard::PutNumber("IMU_Yaw", ahrs->GetYaw());
    m_robotDrive.ArcadeDrive(0.4, correction, true);
  }  
//-172 -178
  while ((ahrs->GetYaw() > -172 ) || (ahrs->GetYaw() < -178)) {
    m_robotDrive.ArcadeDrive(0.4, -0.3, true);
    frc::SmartDashboard::PutNumber("IMU_Yaw", ahrs->GetYaw());}
     m_robotDrive.ArcadeDrive(0, 0, true);

}