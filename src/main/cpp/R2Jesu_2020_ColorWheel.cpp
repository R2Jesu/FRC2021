/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Robot.h"

/**
     * The method GetColor() returns a normalized color value from the sensor and can be
     * useful if outputting the color to an RGB LED or similar. To
     * read the raw color, use GetRawColor().
     * 
     * The color sensor works best when within a few inches from an object in
     * well lit conditions (the built in LED is a big help here!). The farther
     * an object is the more light from the surroundings will bleed into the 
     * measurements and make it difficult to accurately determine its color.
     */

void Robot::R2Jesu_ProcessColorWheel()
{
  R2Jesu_ReadColorWheel();

  double l_drvMotorLimit = 0.25; // Limit drive motors to 25% when color wheel processing
#if R2JESU_TURNON_PNEUMATICS

  if (m_Drivestick.GetRawButton(8))
    colorArm.Set(true);
  else
    colorArm.Set(false);

#endif

// Position Color Wheel
  if (m_OperatorStick.GetRawButton(3))
  { //red button
    //run motor until game color is seen once
  colorArm.Set(true);
  std::this_thread::sleep_for(std::chrono::milliseconds(250));
  if (gameColor != R2Jesu_ReadColorWheel())
  {int colorCounter = 0;
    ColorWheelmotor.Set(.5);
    std::this_thread::sleep_for(std::chrono::milliseconds(750));
    while (colorCounter < 2 && !(m_OperatorStick.GetRawButton(7)))
    {
      if (gameColor == R2Jesu_ReadColorWheel())
      {
        colorCounter++;
      }
      // Allow for operator driving
      R2Jesu_ProcessDrive(l_drvMotorLimit);
    }
    ColorWheelmotor.Set(-.4);
    std::this_thread::sleep_for(std::chrono::milliseconds(333));
    ColorWheelmotor.StopMotor();
    std::this_thread::sleep_for(std::chrono::seconds(1));
    }
      colorArm.Set(false);
  }

// Rotate Color 4 times
  if (m_OperatorStick.GetRawButton(1))
  {
    //run motor until game color is seen 9 times
  colorArm.Set(true);
    int colorCount = 0;
    int colorCount2 = 0;
    

    /**
     * Run the color match algorithm on our detected color
     */
    frc::Color startingColor = R2Jesu_ReadColorWheel();
    frc::Color secondColor;

    if (startingColor == kBlueTarget){
      secondColor = kYellowTarget;
    } else if (startingColor == kYellowTarget){
      secondColor = kRedTarget;
    } else if (startingColor == kRedTarget) {
      secondColor = kGreenTarget;
    } else if (startingColor == kGreenTarget){
      secondColor = kBlueTarget;
    }

    
    ColorWheelmotor.Set(.45);
    while (colorCount < 9 && !(m_OperatorStick.GetRawButton(7)))
    {
      if (startingColor == R2Jesu_ReadColorWheel())
      {
        if (colorCount < 8)
        {
          colorCount2 = 0;
          while (colorCount2 < 1 && !(m_OperatorStick.GetRawButton(7)))
          {
            if (secondColor == R2Jesu_ReadColorWheel())
            {
              colorCount2++;
            }
            // Allow for operator driving
          }
        }
        colorCount++;
      }
    //  R2Jesu_ProcessDrive(l_drvMotorLimit);
    }
    ColorWheelmotor.Set(-.4);
    std::this_thread::sleep_for(std::chrono::milliseconds(333));
    ColorWheelmotor.StopMotor();
    std::this_thread::sleep_for(std::chrono::seconds(1));
    colorArm.Set(false);
  }
}

void Robot::R2Jesu_CheckGameTargetColor()
{
  gameData = frc::DriverStation::GetInstance().GetGameSpecificMessage();
  if ((gameData.length() > 0) && (gameColor == nun))
  {
    switch (gameData[0])
    {
    case 'B':
      gameColor = kRedTarget;
      break;
    case 'G':
      gameColor = kYellowTarget;
      break;
    case 'R':
      gameColor = kBlueTarget;
      break;
    case 'Y':
      gameColor = kGreenTarget;
      break;
    }
  }
#if R2JESU_TURNON_SMARTDASHBOARD
  frc::SmartDashboard::PutString("gameData", gameData);
  frc::SmartDashboard::PutNumber("gameColor", gameColor.red);
#endif
}

frc::Color Robot::R2Jesu_ReadColorWheel()
{

  std::string colorString;

  frc::Color detectedColor = m_colorSensor.GetColor();

  frc::Color matchedColor = m_colorMatcher.MatchClosestColor(detectedColor, ColorConfidence);

  if (matchedColor == kBlueTarget)
  {
    colorString = "Blue";
  }
  else if (matchedColor == kRedTarget)
  {
    colorString = "Red";
  }
  else if (matchedColor == kGreenTarget)
  {
    colorString = "Green";
  }
  else if (matchedColor == kYellowTarget)
  {
    colorString = "Yellow";
  }
  else
  {
    colorString = "Unknown";
  }

//#if R2JESU_TURNON_SMARTDASHBOARD
  frc::SmartDashboard::PutNumber("Red", detectedColor.red);
  frc::SmartDashboard::PutNumber("Green", detectedColor.green);
  frc::SmartDashboard::PutNumber("Blue", detectedColor.blue);
  frc::SmartDashboard::PutNumber("Confidence", ColorConfidence);
  frc::SmartDashboard::PutString("Detected Color", colorString);
//#endif

  return (matchedColor);
}
