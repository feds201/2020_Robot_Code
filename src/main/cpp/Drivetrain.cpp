/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Drivetrain.h"

Drivetrain::Drivetrain() {

     //Use Phoenix Tuner to test encoders, maybe use IntegratedSensor or Encoder Class, CTRE_MagEncoder_Relative
    //back_left.ConfigSelectedFeedbackSensor(FeedbackDevice::IntegratedSensor, 0, 10);
    //back_right.ConfigSelectedFeedbackSensor(FeedbackDevice::IntegratedSensor, 0, 10);
    //front_left.ConfigSelectedFeedbackSensor(FeedbackDevice::IntegratedSensor, 0, 10);
    //front_right.ConfigSelectedFeedbackSensor(FeedbackDevice::IntegratedSensor, 0, 10);

    backLeft.ConfigSelectedFeedbackSensor(FeedbackDevice::CTRE_MagEncoder_Relative, 0, 10);
    backRight.ConfigSelectedFeedbackSensor(FeedbackDevice::CTRE_MagEncoder_Relative, 0, 10);
    frontLeft.ConfigSelectedFeedbackSensor(FeedbackDevice::CTRE_MagEncoder_Relative, 0, 10);
    frontRight.ConfigSelectedFeedbackSensor(FeedbackDevice::CTRE_MagEncoder_Relative, 0, 10);
  
    frontRight.SetSelectedSensorPosition(0);
    backRight.SetSelectedSensorPosition(0);
    frontLeft.SetSelectedSensorPosition(0);
    backLeft.SetSelectedSensorPosition(0);

}

void Drivetrain::Drive(double forward, double turn) {
    
    leftThrot = turn - forward;
    rightThrot = turn + forward;
    
    backLeft.Set(ControlMode::PercentOutput, leftThrot);
    frontLeft.Set(ControlMode::PercentOutput, leftThrot);
    backRight.Set(ControlMode::PercentOutput, rightThrot);
    frontRight.Set(ControlMode::PercentOutput, rightThrot);

    //Printer();
}

void Drivetrain::Shift() {
    if (shifter.Get() == frc::DoubleSolenoid::Value::kForward) {
		shifter.Set(frc::DoubleSolenoid::Value::kReverse);
		//currentGear = 2;
		//gearHasChanged = true;
	}
    else {
		shifter.Set(frc::DoubleSolenoid::Value::kForward);
		//currentGear = 1;
		//gearHasChanged = true;
	}
}

void Drivetrain::Printer() {
    std::cout << "Back left:" << std::endl;
    std::cout << backLeft.GetSelectedSensorPosition(0) << " counts" << std::endl;
    //std::cout << backLeft.GetSelectedSensorVelocity(0) << " counts/100ms" << std::endl;
    std::cout << backLeft.GetSelectedSensorVelocity(0) * velToRPM_FX << " RPM" << std::endl;
    std::cout << std::endl;

    std::cout << "Front left:" << std::endl;
    std::cout << frontLeft.GetSelectedSensorPosition(0) << " counts" << std::endl;
    //std::cout << frontLeft.GetSelectedSensorVelocity(0) << " counts/100ms" << std::endl;
    std::cout << frontLeft.GetSelectedSensorVelocity(0) * velToRPM_FX << " RPM" << std::endl;
    std::cout << std::endl;

    std::cout << "Back right:" << std::endl;
    std::cout << backRight.GetSelectedSensorPosition(0) << " counts" << std::endl;
    //std::cout << backRight.GetSelectedSensorVelocity(0) << " counts/100ms" << std::endl;
    std::cout << backRight.GetSelectedSensorVelocity(0) * velToRPM_FX << " RPM" << std::endl;
    std::cout << std::endl;

    std::cout << "Front right:" << std::endl;
    std::cout << frontRight.GetSelectedSensorPosition(0) << " counts" << std::endl;
    //std::cout << frontRight.GetSelectedSensorVelocity(0) << " counts/100ms" << std::endl;
    std::cout << frontRight.GetSelectedSensorVelocity(0) * velToRPM_FX << " RPM" << std::endl;
    std::cout << std::endl;
}

void Drivetrain::DashboardPrinter() {
    frc::SmartDashboard::PutNumber("Back Left Motor Position (counts)", backLeft.GetSelectedSensorPosition(0));
    frc::SmartDashboard::PutNumber("Back Left Motor Velocity (counts/100ms)", backLeft.GetSelectedSensorVelocity(0));
    frc::SmartDashboard::PutNumber("Back Left Motor RPM", backLeft.GetSelectedSensorVelocity(0) * velToRPM_FX);

    frc::SmartDashboard::PutNumber("Front Left Motor Position (counts)", frontLeft.GetSelectedSensorPosition(0));
    frc::SmartDashboard::PutNumber("Front Left Motor Velocity (counts/100ms)", frontLeft.GetSelectedSensorVelocity(0));
    frc::SmartDashboard::PutNumber("Front Left Motor RPM", frontLeft.GetSelectedSensorVelocity(0) * velToRPM_FX);

    frc::SmartDashboard::PutNumber("Back Right Motor Position (counts)", backRight.GetSelectedSensorPosition(0));
    frc::SmartDashboard::PutNumber("Back Right Motor Velocity (counts/100ms)", backRight.GetSelectedSensorVelocity(0));
    frc::SmartDashboard::PutNumber("Back Right Motor RPM", backRight.GetSelectedSensorVelocity(0) * velToRPM_FX);

    frc::SmartDashboard::PutNumber("Front Right Motor Position (counts)", frontRight.GetSelectedSensorPosition(0));
    frc::SmartDashboard::PutNumber("Front Right Motor Velocity (counts/100ms)", frontRight.GetSelectedSensorVelocity(0));
    frc::SmartDashboard::PutNumber("Front Right Motor RPM", frontRight.GetSelectedSensorVelocity(0) * velToRPM_FX);
}