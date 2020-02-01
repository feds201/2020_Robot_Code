/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include "RobotMap.h"

class BallPickup {
 public:
  BallPickup();
  void Pickup(double);
  void Printer();
  void DashboardPrinter();
 
 private:
  WPI_TalonSRX pickup{pickupMotorID};
};