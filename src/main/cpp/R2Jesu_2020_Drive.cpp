/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Robot.h"

void Robot::R2Jesu_ProcessDrive(double p_LimitFactor)
{
  double drive_throttle = (m_Drivestick.GetThrottle() - 1) * -.4;
  // Limit the drive motors for certain operations like color wheel
  if (m_Drivestick.GetRawButton(1)) // Break
  {
    m_drvL = 0.0;
    m_drvR = 0.0;
  }
  else
  {
  m_drvL = -m_Drivestick.GetY() * drive_throttle;
  //m_drvR = (m_Drivestick.GetX()+(m_Drivestick.GetTwist()*0.4f)) * p_LimitFactor;
  m_drvR = (m_Drivestick.GetTwist() * .7) * drive_throttle;
  }


  // Drive with arcade style (use right stick)
  m_robotDrive.ArcadeDrive(m_drvL, m_drvR);

#if R2JESU_TURNON_SMARTDASHBOARD
  frc::SmartDashboard::PutNumber("DrvL", m_drvL);
  frc::SmartDashboard::PutNumber("DrvR", m_drvR);
  frc::SmartDashboard::PutNumber("DrvL", m_drvL);
  frc::SmartDashboard::PutNumber("DrvLimit", p_LimitFactor);
  frc::SmartDashboard::PutNumber("throttle", m_Drivestick.GetThrottle());
#endif
}
