/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Robot.h"

void Robot::R2Jesu_Autonomous() 
{ double trpm;
  double l_mtrPwr = -0.4;
  double r_mtrPwr = -0.4;
   trpm = -1*((.02195*(currentDistance)*(currentDistance)) - (7.874 * currentDistance) + 2895);
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
  } else
{
  m_ShooterMotorRight.Set(0);
  m_ShooterMotorLeft.Set(0);
}
//m_robotDrive.ArcadeDrive(-0.3, 0.0, true);
  // Drive for 2 seconds
  if (m_encL.GetDistance() < 48.0) {
    // Drive forwards half speed
    m_robotDrive.ArcadeDrive(-0.3, 0.0, true);
 } else {
    // Stop robot
    m_robotDrive.ArcadeDrive(0.0, 0.0, true);
  }
  if (!(ballCupLimit.Get())) {
    snowMotor.Set(0);
  ballPopper.Set(true);
  } else {
    ballPopper.Set(false);
    snowMotor.Set(-1);
  }
}

 