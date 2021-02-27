/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Robot.h"

void Robot::R2Jesu_Limelight()
{

   double targetOffsetAngle_Horizontal = limelight_Table->GetNumber("tx",0.0);
   double targetOffsetAngle_Vertical = limelight_Table->GetNumber("ty",0.0);
   double targetArea = limelight_Table->GetNumber("ta",0.0);
   double targetSkew = limelight_Table->GetNumber("ts",0.0);
   /*frc::SmartDashboard::PutNumber("targetOffsetAngle_Horizontal", limelight_Table->GetNumber("tx",0.0));
   frc::SmartDashboard::PutNumber("targetOffsetAngle_Vertical", limelight_Table->GetNumber("ty",0.0));
   frc::SmartDashboard::PutNumber("targetArea", limelight_Table->GetNumber("ta",0.0));
   frc::SmartDashboard::PutNumber("targetSkew", limelight_Table->GetNumber("ts",0.0));*/
 
  frc::SmartDashboard::PutNumber("targetOffsetAngle_Vertical", limelight_Table->GetNumber("ty",0.0));
 
   //(Target height - camera height) / tan((camera angle + target offset angle from limelight)) * (PI / 180)))
   double ourDist = (((double)98.25 - (double)26.75) / tan(((double)12.2 + targetOffsetAngle_Vertical) * (PI / 180)));
   currentDistance = ourDist;
   frc::SmartDashboard::PutNumber("current distance", currentDistance);

}