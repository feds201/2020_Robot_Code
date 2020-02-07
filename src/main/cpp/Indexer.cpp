/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Indexer.h"

Indexer::Indexer() {
	//Encoder should be here I think
}

void Indexer::Spin(double triggerForward, double triggerReverse) {
	if (triggerForward > 0 && triggerReverse > 0)
    	index.Set(ControlMode::PercentOutput, 0);
	else
		index.Set(ControlMode::PercentOutput, triggerForward - triggerReverse);
	//Printer();
	dashboardPrinter();
}

void Indexer::feedBall() {
    if (feeder.Get() == frc::DoubleSolenoid::Value::kForward) {
		feeder.Set(frc::DoubleSolenoid::Value::kReverse);
	}
    else {
		feeder.Set(frc::DoubleSolenoid::Value::kForward);
	}
}

void Indexer::Printer() {

}

void Indexer::dashboardPrinter() {

}