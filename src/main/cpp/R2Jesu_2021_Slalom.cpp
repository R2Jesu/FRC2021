/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Robot.h"
//right of right box

void Robot::R2Jesu_Slalom() 
{
  double correction;
  ahrs -> ZeroYaw();
   m_encL.Reset();
  m_encR.Reset();
  while ((m_encL.GetDistance() < 48.0) && (m_encR.GetDistance() < 48.0)) {
    m_robotDrive.ArcadeDrive(0.5, 0.0, true);
  } 
  
   m_robotDrive.ArcadeDrive(0.0, 0.0);
  
  while (ahrs->GetYaw() > -65) {
    // Drive forwards half speed
    m_robotDrive.ArcadeDrive(0.5, -0.5, true);
  } 
   m_robotDrive.ArcadeDrive(0.0, 0.0, true);

  m_encL.Reset();
  m_encR.Reset();
   
     while ((m_encL.GetDistance() < 60.0) && (m_encR.GetDistance() < 60.0)) {
    // Drive forwards half speed
    m_robotDrive.ArcadeDrive(0.5, 0.0, true);
  } 
   while (ahrs->GetYaw() < -5) {
    // Drive forwards half speed
    m_robotDrive.ArcadeDrive(0.0, 0.5, true);
  } 

    m_encL.Reset();
    m_encR.Reset();

    while ((m_encL.GetDistance() < 170.0) && (m_encR.GetDistance() < 170.0)) {
    correction = .1 * (0 - ahrs->GetYaw());
    if (correction > .3){
      correction = .3;}
    if (correction < -.3){
      correction = -.3; 
    }
    frc::SmartDashboard::PutNumber("IMU_Yaw", ahrs->GetYaw());
    m_robotDrive.ArcadeDrive(0.6, correction, true);
    }

    while (ahrs->GetYaw() < 62.5) {
    m_robotDrive.ArcadeDrive(0.0, 0.5, true);}

    m_encL.Reset();
    m_encR.Reset();

    while ((m_encL.GetDistance() < 25.0) && (m_encR.GetDistance() < 25.0)) {
    m_robotDrive.ArcadeDrive(0.5, 0.0, true);}

    while ((ahrs->GetYaw() > 125) || (ahrs->GetYaw() < 115)) {
    m_robotDrive.ArcadeDrive(0.5, -0.325, true);
    frc::SmartDashboard::PutNumber("IMU_Yaw", ahrs->GetYaw());}
     m_robotDrive.ArcadeDrive(0, 0, true);

    m_encL.Reset();
    m_encR.Reset();

    while ((m_encL.GetDistance() < 56.0) && (m_encR.GetDistance() < 56.0)) {
    m_robotDrive.ArcadeDrive(0.5, 0.0, true);}

    while ((ahrs->GetYaw() < 170) && (ahrs->GetYaw() > -180)) {
    m_robotDrive.ArcadeDrive(0.0, 0.5, true);
    }

    while ((m_encL.GetDistance() < 195.0) && (m_encR.GetDistance() < 195.0)) {
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
      m_robotDrive.ArcadeDrive(0.6, correction, true);
    } 

       m_robotDrive.ArcadeDrive(0, 0, true);
    
    while ((ahrs->GetYaw() < -130) || (ahrs->GetYaw() > 170)) {
    m_robotDrive.ArcadeDrive(0.0, .5, true);
    }

    m_encL.Reset();
    m_encR.Reset();

    while ((m_encL.GetDistance() < 60.0) && (m_encR.GetDistance() < 60.0)) {
    m_robotDrive.ArcadeDrive(0.5, 0.0, true);}

  while (ahrs->GetYaw() > -155) {
    m_robotDrive.ArcadeDrive(0.0, -0.5, true);
    }

    m_encL.Reset();
    m_encR.Reset();

    while ((m_encL.GetDistance() < 42.0) && (m_encR.GetDistance() < 42.0)) {
    m_robotDrive.ArcadeDrive(0.5, 0.0, true);} 

}

 