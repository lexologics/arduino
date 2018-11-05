/*
 * Sketch     Modify Wi-Fi hotspot name and password of the robot
 * Platform   Freenove Hexapod Robot (Arduino/Genuino Mega 2560)
 * Brief      This sketch is used to show how to modify Wi-Fi hotspot name and password of the robot 
 *            when using default function.
 * Author     Ethan Pan @ Freenove (support@freenove.com)
 * Date       2018/03/30
 * Copyright  Copyright © Freenove (http://www.freenove.com)
 * License    Creative Commons Attribution ShareAlike 3.0
 *            (http://creativecommons.org/licenses/by-sa/3.0/legalcode)
 * -----------------------------------------------------------------------------------------------*/

// Include FNHR (Freenove Hexapod Robot) library
#include <FNHR.h>

FNHR robot;

void setup() {
  // Set Wi-Fi hotspot name and password
  // Call this function before robot.Start()
  // The Wi-Fi password is case sensitive and at least 8 characters
  robot.SetWiFi("HexapotBot", "xanadu1966");
  // Start Freenove Hexapod Robot with default function
  robot.Start(true);
}

void loop() {
  // Update Freenove Hexapod Robot
  robot.Update();
}
