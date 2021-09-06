#include "Robot.h"
//right of left box

void Robot::R2Jesu_Bounce() 
{  
  ahrs -> ZeroYaw();
  m_encL.Reset();
  m_encR.Reset();
  double correction;
  while ((m_encL.GetDistance() < 36.0) && (m_encR.GetDistance() < 36.0)) 
  {
    m_robotDrive.ArcadeDrive(0.5, 0.0, true);
  } 
    
 
//2 was good center wise but went too far forward
 while (ahrs-> GetYaw() > -90) 
 {
    correction = .1 * (-90 - ahrs->GetYaw());
    
    if (correction > .3125)
    {
      correction = .3125;
    }
    if (correction < -.3125)
    {
      correction = -.3125; 
    }
    frc::SmartDashboard::PutNumber("IMU_Yaw", ahrs->GetYaw());
    m_robotDrive.ArcadeDrive(0.5, correction, true);
  }

   m_encL.Reset();
   m_encR.Reset();

  while ((m_encL.GetDistance() < 15.0) && (m_encR.GetDistance() < 15.0)) 
  {
      m_robotDrive.ArcadeDrive(0.5, 0.0, true);
  } 

//too much both in distance and in angle
  m_encL.Reset();
  m_encR.Reset();
  while ((m_encL.GetDistance() > -95.0) && (m_encR.GetDistance() > -95.0)) 
  {
    correction = .1 * (-110 - ahrs->GetYaw());
    
    if (correction > .375)
    {
     correction = .375;
    }
    if (correction < -.375)
    {
      correction = -.375; 
    }
    
    m_robotDrive.ArcadeDrive(-0.5, correction, true);
  }  
// 85 95
  while ((ahrs->GetYaw() > 95) || (ahrs->GetYaw() < 85)) 
  {
    m_robotDrive.ArcadeDrive(-0.5, -0.39, true);
    frc::SmartDashboard::PutNumber("IMU_Yaw", ahrs->GetYaw());
  }

  m_encL.Reset();
  m_encR.Reset();

while ((m_encL.GetDistance() > -92.0) && (m_encR.GetDistance() > -92.0)) 
{
    correction = .1 * (90 - ahrs->GetYaw());
     
    if (correction > .375)
    {
      correction = .375;
    }
    if (correction < -.375)
    {
      correction = -.375; 
    }
    frc::SmartDashboard::PutNumber("IMU_Yaw", ahrs->GetYaw());
    frc::SmartDashboard::PutNumber("Left Encoder Distance", m_encL.GetDistance());
    frc::SmartDashboard::PutNumber("Right Encoder Distance", m_encR.GetDistance());
    m_robotDrive.ArcadeDrive(-0.5, correction, true);
  }
    m_encL.Reset();
  m_encR.Reset();

    while ((m_encL.GetDistance() < 65.0) && (m_encR.GetDistance() < 65.0)) 
{
    correction = .1 * (90 - ahrs->GetYaw());
     
    if (correction > .375)
    {
      correction = .375;
    }
    if (correction < -.375)
    {
      correction = -.375; 
    }
    m_robotDrive.ArcadeDrive(0.5, correction, true);
  }
  //-95 -85
  while ((ahrs->GetYaw() < -95) || (ahrs->GetYaw() > -85)) 
  {
    m_robotDrive.ArcadeDrive(0.5, -0.275, true);
    frc::SmartDashboard::PutNumber("IMU_Yaw", ahrs->GetYaw());
  }
     m_encL.Reset();
  m_encR.Reset();

while ((m_encL.GetDistance() < 70.0) && (m_encR.GetDistance() < 70.0)) 
{
    correction = .1 * (-90 - ahrs->GetYaw());
     
    if (correction > .375)
    {
      correction = .375;
    }
    if (correction < -.375)
    {
      correction = -.375; 
    }
    m_robotDrive.ArcadeDrive(0.5, correction, true);
  }
  m_encL.Reset();
  m_encR.Reset();

  while ((m_encL.GetDistance() > -65) && (m_encR.GetDistance() > -65)) {
    correction = .1 * (180 - ahrs->GetAngle());
    if (correction == 36){
      correction = 0;
    }
    if ((correction < 36) && (correction > 18)){
      correction = -.32;
    }
    if (correction < -.32){
      correction = -.32;
    }
    if (correction > .32){
      correction = .32;
    }
      m_robotDrive.ArcadeDrive(-0.5, correction, true);
    } 

m_robotDrive.ArcadeDrive(0, 0, true);
}