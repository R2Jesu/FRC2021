/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Robot.h"

void Robot::R2Jesu_Slalom() 
{
  double correction;
  ahrs -> ZeroYaw();
  while ((m_encL.GetDistance() < 48.0) && (m_encR.GetDistance() < 48.0)) {
    m_robotDrive.ArcadeDrive(0.4, 0.0, true);
  } 
  
   m_robotDrive.ArcadeDrive(0.0, 0.0);
  
  while (ahrs->GetYaw() > -65) {
    // Drive forwards half speed
    m_robotDrive.ArcadeDrive(0.4, -0.4, true);
  } 
   m_robotDrive.ArcadeDrive(0.0, 0.0, true);

  m_encL.Reset();
  m_encR.Reset();
   
     while ((m_encL.GetDistance() < 68.0) && (m_encR.GetDistance() < 68.0)) {
    // Drive forwards half speed
    m_robotDrive.ArcadeDrive(0.4, 0.0, true);
  } 
   while (ahrs->GetYaw() < -5) {
    // Drive forwards half speed
    m_robotDrive.ArcadeDrive(0.0, 0.4, true);
  } 

    m_encL.Reset();
    m_encR.Reset();

    while ((m_encL.GetDistance() < 155.0) && (m_encR.GetDistance() < 155.0)) {
    correction = .1 * (0 - ahrs->GetAngle());
    if (correction > .3){
      correction = .3;}
    if (correction < -.3){
      correction = -.3; 
    }
    frc::SmartDashboard::PutNumber("IMU_Yaw", ahrs->GetYaw());
    m_robotDrive.ArcadeDrive(0.4, correction, true);
    }

    while (ahrs->GetYaw() < 65) {
    m_robotDrive.ArcadeDrive(0.0, 0.4, true);}

    m_encL.Reset();
    m_encR.Reset();

    while ((m_encL.GetDistance() < 35.0) && (m_encR.GetDistance() < 35.0)) {
    m_robotDrive.ArcadeDrive(0.4, 0.0, true);}

    while ((ahrs->GetYaw() > 125) || (ahrs->GetYaw() < 115)) {
    m_robotDrive.ArcadeDrive(0.4, -0.3, true);
    frc::SmartDashboard::PutNumber("IMU_Yaw", ahrs->GetYaw());}
     m_robotDrive.ArcadeDrive(0, 0, true);

    m_encL.Reset();
    m_encR.Reset();

    while ((m_encL.GetDistance() < 40.0) && (m_encR.GetDistance() < 40.0)) {
    m_robotDrive.ArcadeDrive(0.4, 0.0, true);}

    while ((ahrs->GetYaw() < 180) && (ahrs->GetYaw() > -175)) {
    m_robotDrive.ArcadeDrive(0.0, 0.4, true);
    }

    while ((m_encL.GetDistance() < 195.0) && (m_encR.GetDistance() < 195.0)) {
    correction = .1 * (180 - ahrs->GetAngle());
    if (correction == 36){
      correction = 0;
    }
    if ((correction < 36) && (correction > 18)){
      correction = -.27;
    }
    if (correction < -.27){
      correction = -.27;
    }
    if (correction > .27){
      correction = .27;
    }
      m_robotDrive.ArcadeDrive(0.4, correction, true);
    } 

       m_robotDrive.ArcadeDrive(0, 0, true);
    
    while ((ahrs->GetYaw() < -130) || (ahrs->GetYaw() > 170)) {
    m_robotDrive.ArcadeDrive(0.0, .4, true);
    }

    m_encL.Reset();
    m_encR.Reset();

    while ((m_encL.GetDistance() < 58.0) && (m_encR.GetDistance() < 58.0)) {
    m_robotDrive.ArcadeDrive(0.4, 0.0, true);}

  while (ahrs->GetYaw() > -178) {
    m_robotDrive.ArcadeDrive(0.0, -0.4, true);
    }

    m_encL.Reset();
    m_encR.Reset();

    while ((m_encL.GetDistance() < 53.0) && (m_encR.GetDistance() < 53.0)) {
    m_robotDrive.ArcadeDrive(0.4, 0.0, true);} 

}

 