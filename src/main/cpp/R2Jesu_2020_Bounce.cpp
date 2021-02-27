#include "Robot.h"

void Robot::R2Jesu_Bounce() 
{  
  ahrs -> ZeroYaw();
  m_encL.Reset();
  m_encR.Reset();
  double correction;
  while ((m_encL.GetDistance() < 50.0) && (m_encR.GetDistance() < 50.0)) 
  {
    m_robotDrive.ArcadeDrive(0.4, 0.0, true);
  } 
    
 
//2 was good center wise but went too far forward
 while (ahrs-> GetYaw() > -90) 
 {
    correction = .1 * (-90 - ahrs->GetYaw());
    
    if (correction > .25)
    {
      correction = .25;
    }
    if (correction < -.25)
    {
      correction = -.25; 
    }
    frc::SmartDashboard::PutNumber("IMU_Yaw", ahrs->GetYaw());
    m_robotDrive.ArcadeDrive(0.4, correction, true);
  }

   m_encL.Reset();
   m_encR.Reset();

  while ((m_encL.GetDistance() < 20.0) && (m_encR.GetDistance() < 20.0)) 
  {
      m_robotDrive.ArcadeDrive(0.4, 0.0, true);
  } 

//too much both in distance and in angle
  m_encL.Reset();
  m_encR.Reset();
  while ((m_encL.GetDistance() > -95.0) && (m_encR.GetDistance() > -95.0)) 
  {
    correction = .1 * (-115 - ahrs->GetYaw());
    
    if (correction > .3)
    {
     correction = .3;
    }
    if (correction < -.3)
    {
      correction = -.3; 
    }
    
    m_robotDrive.ArcadeDrive(-0.4, correction, true);
  }  
// 85 95
  while ((ahrs->GetYaw() > 95) || (ahrs->GetYaw() < 85)) 
  {
    m_robotDrive.ArcadeDrive(-0.4, -0.28, true);
    frc::SmartDashboard::PutNumber("IMU_Yaw", ahrs->GetYaw());
  }

  m_encL.Reset();
  m_encR.Reset();

while ((m_encL.GetDistance() > -78.0) && (m_encR.GetDistance() > -78.0)) 
{
    correction = .1 * (90 - ahrs->GetYaw());
     
    if (correction > .3)
    {
      correction = .3;
    }
    if (correction < -.3)
    {
      correction = -.3; 
    }
    frc::SmartDashboard::PutNumber("IMU_Yaw", ahrs->GetYaw());
    frc::SmartDashboard::PutNumber("Left Encoder Distance", m_encL.GetDistance());
    frc::SmartDashboard::PutNumber("Right Encoder Distance", m_encR.GetDistance());
    m_robotDrive.ArcadeDrive(-0.4, correction, true);
  }
    m_encL.Reset();
  m_encR.Reset();

    while ((m_encL.GetDistance() < 65.0) && (m_encR.GetDistance() < 65.0)) 
{
    correction = .1 * (90 - ahrs->GetYaw());
     
    if (correction > .3)
    {
      correction = .3;
    }
    if (correction < -.3)
    {
      correction = -.3; 
    }
    m_robotDrive.ArcadeDrive(0.4, correction, true);
  }
  //-95 -85
  while ((ahrs->GetYaw() < -95) || (ahrs->GetYaw() > -85)) 
  {
    m_robotDrive.ArcadeDrive(0.4, -0.25, true);
    frc::SmartDashboard::PutNumber("IMU_Yaw", ahrs->GetYaw());
  }
     m_encL.Reset();
  m_encR.Reset();

while ((m_encL.GetDistance() < 63.5) && (m_encR.GetDistance() < 63.5)) 
{
    correction = .1 * (-90 - ahrs->GetYaw());
     
    if (correction > .3)
    {
      correction = .3;
    }
    if (correction < -.3)
    {
      correction = -.3; 
    }
    m_robotDrive.ArcadeDrive(0.4, correction, true);
  }
  m_encL.Reset();
  m_encR.Reset();

  while ((m_encL.GetDistance() > -102) && (m_encR.GetDistance() > -102)) {
    correction = .1 * (180 - ahrs->GetAngle());
    if (correction == 36){
      correction = 0;
    }
    if ((correction < 36) && (correction > 18)){
      correction = -.25;
    }
    if (correction < -.25){
      correction = -.25;
    }
    if (correction > .25){
      correction = .25;
    }
      m_robotDrive.ArcadeDrive(-0.4, correction, true);
    } 


}