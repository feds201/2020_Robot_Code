/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "IndicatorLights.h"

IndicatorLights::IndicatorLights(const wpi::Twine& device, const wpi::Twine& deviceAlternate, frc::SerialPort::Port port = frc::SerialPort::Port::kUSB) {
	// Try to connect to first device ID.
	try {
		// Create SerialPort instance with specified settings.
		// We will use this to interface with the USB connection to the arduino.
		serial = new frc::SerialPort(BAUD, device, port);
	} catch(...) {
		// Failed, try the second device ID
		try {
			serial = new frc::SerialPort(BAUD, deviceAlternate, port);
		} catch (...) {
			// Oh well.
			return;
		}
	}
	
	// We set the buffer size to 3, for each of the 3 color channel bytes.
	// We set the buffer to auto flush when it is full.
	serial->SetWriteBufferSize(3);
	serial->SetWriteBufferMode(frc::SerialPort::WriteBufferMode::kFlushWhenFull);
}

// Destructor, likely never called.
IndicatorLights::~IndicatorLights() {
	// As serial is a pointer it is good practice to release the memory.
	// In practice this will usually have no effect.
	delete serial;
}

// Sets the LEDs to a predefined color from the COLOR enum.
void IndicatorLights::setColor(COLOR color) {
	switch (color) {
	case RED:
		setColor(255, 0, 0);
		break;
	case GREEN:
		setColor(0, 255, 0);
		break;
	case BLUE:
		setColor(0, 0, 255);
		break;
	case YELLOW:
		setColor(255, 255, 0);
		break;
	default:
		setColor(0, 0, 0);
		break;
	}
}

// Sets the LEDs to a custom RGB color.
// Only the lower 8 bits are used.
// Basically only use numbers 0-255.
void IndicatorLights::setColor(int r, int g, int b) {
	// Create array to house each of our color channels.
	// We cast to char as SerialPort::Write() takes a char pointer.
	const char buffer [3] = { (char) r, (char) g, (char) b };
	// Send the bytes to the function.
	// Send only the first element's address as that is how array pointers work
	serial->Write(&buffer[0], 3);
	// Flush to ensure nothing lingered. This should do nothing but I like to be sure.
	serial->Flush();
}