#pragma once

#include <iostream>
#include <string>
#include <stdarg.h> //Logger & Timer
#include <fstream> //Logger & Timer
#include <time.h> //Logger & Timer
#include <sys/time.h> //Logger & Timer

//#include "frc/WPILib.h"
#include "frc/Joystick.h"
#include "frc/DoubleSolenoid.h"
#include "frc/SerialPort.h" //Lights
#include "frc/TimedRobot.h"
#include "frc/smartdashboard/SendableChooser.h"
#include "frc/smartdashboard/SmartDashboard.h"
#include "networktables/NetworkTable.h" //Vision
#include "networktables/NetworkTableInstance.h" //Vision
#include "cameraserver/CameraServer.h"
#include "rev/ColorSensorV3.h" //Color Sensor
#include "rev/ColorMatch.h" //Color Sensor
#include "rev/CIEColor.h" //Color Sensor
#include "ctre/Phoenix.h"
#include "rev/CANSparkMax.h" //Sparks

/* CONTROLS
   Driver: 
   Drive Forward - Left Joystick Y Axis
   Turn - Right Joystick X Axis
   Shift Gears - A Button
   Push Ball out of Indexer - B Button

   Operator: 
   Shoot - Left Joystick Y Axis
   Move Shooter Up One Position - Right Bumper (Temporary)
   Move Shooter Down One Position - Left Bumper (Temporary)
   Ball Pickup - Right Joystick Y Axis
   Index - Right Trigger
   Climb - Left Trigger
   Toggle Climb Status - Menu Button
*/

//Misc
constexpr double velToRPM_SRX = (1000 * 60) / 4096; /* Conversion factor from counts/100ms to RPM = 14.6484375
                                                       X counts/100ms * 1000ms/1s * 60s/1min * 1rev/4096 counts */

constexpr double velToRPM_FX = (1000 * 60) / 2048; /* Conversion factor from counts/100ms to RPM = 29.296875
                                                      X counts/100ms * 1000ms/1s * 60s/1min * 1rev/2048 counts */

//Joystick
constexpr int driverJoyUSBPort = 0; //Can be changed in Driver Station
constexpr int operatorJoyUSBPort = 1;

constexpr int fwdJoyChl = 1; //Y Axis on Left Joystick (Driver)
constexpr int trnJoyChl = 4; //X Axis on Right Joystick (Driver)
constexpr int shifterBtn = 1; //A Button (Driver)

constexpr int shootJoyChl = 1;  //Y Axis on Left Joystick (Operator)
constexpr int shootChangeLevelUpBtn = 6; //Right Bumper (Operator)
constexpr int shootChangeLevelDownBtn = 5; //Left Bumper (Operator)

constexpr int climbStatusBtn = 8; //Menu button (Operator)
constexpr int climbJoyChl = 2; //Left Trigger (Operator)

constexpr int ballPickupJoyChl = 5; //Y Axis on Right Joystick (Operator)

constexpr int indexJoyChl = 3; //Right Trigger (Operator) 
constexpr int indexPusherBtn = 1; //B (Driver)

//Drivetrain
constexpr int frontLeftMotorID = 12; //FX
constexpr int frontRightMotorID = 9; //FX
constexpr int backLeftMotorID = 11; //FX
constexpr int backRightMotorID = 10; //FX

constexpr int PCMID = 0; 
constexpr int shiferFirstGear = 3; 
constexpr int shifterSecondGear = 4; 

//Climber
constexpr int winchMotorID = 4; //SRX

//Ball Pickup
constexpr int pickupMotorID = 0; //SRX

//PanelSpinner
constexpr int spinnerMotorID = 100; //SRX? Fix

static constexpr auto i2cPort = frc::I2C::Port::kOnboard;

static constexpr frc::Color kBlueTarget = frc::Color(0.121, 0.430, 0.447);
static constexpr frc::Color kGreenTarget = frc::Color(0.165, 0.587, 0.249);
static constexpr frc::Color kRedTarget = frc::Color(0.520, 0.356, 0.125);
static constexpr frc::Color kYellowTarget = frc::Color(0.320, 0.563, 0.114);

//Shooter
constexpr int shooterMotorID = 1; //Spark
constexpr int slaveShoooterMotorID = 2; //Spark
constexpr int wristMotorID = 100; //SRX Fix

//Indexer 
constexpr int indexerMotorID = 7; //SRX 

constexpr int pusherKReverse = 2;
constexpr int pusherKForward = 5;

//Andy's Drivetrain

constexpr int pigeonID = 0; //Fix

constexpr double Drivetrain_P = 0;
constexpr double Drivetrain_I = 0;
constexpr double Drivetrain_D = 0;

constexpr int maxSpeedLo = 0;
constexpr int maxSpeedHi = 0;
constexpr double gearRatioLo = 0;
constexpr double gearRatioHi = 0;
constexpr int wheelR = 0;

constexpr bool ACCEL_LIMIT_ENABLED = false;

constexpr bool drivetrainVoltageControl = true;
constexpr bool drivetrainAutoheading = false;

