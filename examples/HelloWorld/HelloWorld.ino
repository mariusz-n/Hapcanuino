// Hapcanuino helps to implement Hapcan (Home Automation Project) compatible devices on Arduino board.
// 
// Code explanation: https://github.com/Onixarts/Hapcanuino/wiki/HelloWorld
// Github: https://github.com/Onixarts/Hapcanuino
// Author's site: http://onixarts.pl
// Contact: software@onixarts.pl
// 
// Copyright (C) 2016-2018  Bartosz Rosa (onixarts.pl)
//
// This program is free software : you can redistribute it and / or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.See the
// GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with this program.If not, see <http://www.gnu.org/licenses/>.
#include "Arduino.h"
#include "HapcanDevice.h"

// Hapcanuino uses namespaces 
using namespace Onixarts::HomeAutomationCore;

// HapcanDevice class declaration
Hapcan::HapcanDevice hapcanDevice;

// Configure Your Hapcan device here
const byte Hapcan::Config::MCP::InterruptPin = 2;				// CAN module interrupt is connected to this pin (see https://www.arduino.cc/en/Reference/AttachInterrupt)
const byte Hapcan::Config::MCP::CSPin = 10;						// SPI CS pin
const byte Hapcan::Config::MCP::OscillatorFrequency = MCP_8MHZ;	// MCP oscillator frequency on MCP CAN module (or MCP_16MHz)

const byte Hapcan::Config::Hardware::DeviceId1 = 0x12;			// unique device identifier 1, change it
const byte Hapcan::Config::Hardware::DeviceId2 = 0x34;			// unique device identifier 2, change it

const byte Hapcan::Config::Node::SerialNumber0 = 9;				// ID0 serial number MSB
const byte Hapcan::Config::Node::SerialNumber1 = 9;
const byte Hapcan::Config::Node::SerialNumber2 = 32;			// this is also a default node
const byte Hapcan::Config::Node::SerialNumber3 = 9;				// this is also a default group

const byte Hapcan::Config::Firmware::ApplicationType = 51;		// application (hardware) type (such as button, relay, dimmer) 1-10 Hapcan modules, 102 - ethernet, 51 - Hapcanuino example device
const byte Hapcan::Config::Firmware::ApplicationVersion = 0;	// application (hardware) version, change it with device hardware changes
const byte Hapcan::Config::Firmware::FirmwareVersion = 1;		// firmware version
const int  Hapcan::Config::Firmware::FirmwareRevision = 0;		// firmware revision
																// Configuration end

void setup()
{
	Serial.begin(115200);
	Serial.println("Hapcanuino device starting...");

	// initializing Hapcanuino device
	hapcanDevice.Begin();
}

void loop()
{
	// call Update in loop, to process incomming CAN messages. Should be called as frequent as possible
	hapcanDevice.Update();

	// TODO: place your loop code here. This code should not block loop function for a long time. 
	// Do not use delay() here. 
	// Note: all onixarts libraries are written in the same manner, the loop must only updates the objects and don't block the loop function with delay.
}
