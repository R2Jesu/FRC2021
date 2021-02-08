/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Robot.h"

void Robot::R2Jesu_Slalom() 
{
  while ((m_encL.GetDistance() < 48.0) && (m_encR.GetDistance() < 48.0)) {
    // Drive forwards half speed
    m_robotDrive.ArcadeDrive(0.3, 0.0);
  } 
  
   m_robotDrive.ArcadeDrive(0.0, 0.0);
  
  while (ahrs->GetYaw() > -70) {
    // Drive forwards half speed
    m_robotDrive.ArcadeDrive(0.3, -0.3);
  } 
   m_robotDrive.ArcadeDrive(0.0, 0.0);

  m_encL.Reset();
  m_encR.Reset();
   
     while ((m_encL.GetDistance() < 68.0) && (m_encR.GetDistance() < 68.0)) {
    // Drive forwards half speed
    m_robotDrive.ArcadeDrive(0.3, 0.0);
  } 
   while (ahrs->GetYaw() < -5) {
    // Drive forwards half speed
    m_robotDrive.ArcadeDrive(0.0, 0.3);
  } 

    m_encL.Reset();
    m_encR.Reset();

    while ((m_encL.GetDistance() < 155.0) && (m_encR.GetDistance() < 155.0)) {
    double correction = .1 * (-5 - ahrs->GetAngle());
    m_robotDrive.ArcadeDrive(0.3, correction);}

    while (ahrs->GetYaw() < 65) {
    m_robotDrive.ArcadeDrive(0.0, 0.3);}

    m_encL.Reset();
    m_encR.Reset();

    while ((m_encL.GetDistance() < 35.0) && (m_encR.GetDistance() < 35.0)) {
    m_robotDrive.ArcadeDrive(0.3, 0.0);}

    while (ahrs->GetYaw() > -180) {
    m_drvL = .1;
    m_drvR = .3;
    }
}

 