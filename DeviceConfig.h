#pragma once
namespace Onixarts
{
	namespace HomeAutomationCore
	{
		namespace Hapcan
		{
			namespace Config
			{
				const byte RxFifoQueueSize = 10;				// max 255

				const byte InitialGroup = 3;					// Initial group identifier
				const byte InitialNode = 3;						// Initial node identifier
				
				namespace Hardware
				{
					const byte HardwareType1 = 0x4f;			//hardware type (0x3000 = UNIV 3, 0x4F41 = OA Hapcanuino)
					const byte HardwareType2 = 0x41;
					const byte HardwareVersion = 1;				// 3 for Hapcan's UNIV 3, 1 = Arduino Uno 

					const byte DeviceId1 = 0x12;				// unique device identifier 1, change it
					const byte DeviceId2 = 0x34;				// unique device identifier 2, change it
				}

				namespace Node
				{
					const byte SerialNumber0 = 0x01;			// ID0 serial number MSB
					const byte SerialNumber1 = 0x02;
					const byte SerialNumber2 = 0x03;
					const byte SerialNumber3 = 0x04;
				}

				namespace Firmware
				{
					const byte ApplicationType = 0x20;			// application (hardware) type (such as button, relay, dimmer) 1-10 reserved for Hapcan modules, 102 - ethernet
					const byte ApplicationVersion = 0;			// application (hardware) version
					const byte FirmwareVersion = 0;				// firmware version
					const int FirmwareRevision = 1;				// firmware revision
				}

				namespace MCP
				{
					const byte InterruptPin = 2;				// CAN module interrupt is connected to this pin (see https://www.arduino.cc/en/Reference/AttachInterrupt)
					const byte CSPin = 10;						// SPI CS pin
					const byte OscillatorFrequency = MCP_8MHz;	// MCP oscillator frequency on MCP CAN module (or MCP_16MHz)
				}

				namespace BootLoader
				{
					const byte BootloaderVersion = 1;			// BVER1
					const byte BootloaderRevision = 0;			// BREV2
				}
			}

			namespace Message
			{
				//const byte SystemMessage0x00Flag = 0x00;

				//const byte SystemMessage0x10Flag = 0x10;
				//const byte SystemMessage0x11Flag = 0x11;
				const byte NormalMessageCategory = 0x30;

				namespace System
				{
					// Handled by bootloader in programming mode
					const unsigned int ExitAllFromBootloaderProgrammingMode = 0x010;
					const unsigned int ExitOneNodeFromBootloaderProgrammingMode = 0x020;
					const unsigned int AddressFrame = 0x030;
					const unsigned int DataFrame = 0x040;

					// Handled by bootloader
					const unsigned int EnterProgrammingMode = 0x100;
					const unsigned int RebootRequestToGroup = 0x101;
					const unsigned int RebootRequestToNode = 0x102;
					const unsigned int HardwareTypeRequestToGroup = 0x103;
					const unsigned int HardwareTypeRequestToNode = 0x104;
					const unsigned int FirmwareTypeRequestToGroup = 0x105;
					const unsigned int FirmwareTypeRequestToNode = 0x106;
					const unsigned int SetDefaultNodeAndGroupRequestToNode = 0x107;

					// Handled by functional firmware
					const unsigned int StatusRequestToGroup = 0x108;
					const unsigned int StatusRequestToNode = 0x109;
					const unsigned int ControlMessage = 0x10A;

					//Handled by bootloader
					const unsigned int SupplyVoltageRequestToGroup = 0x10B;
					const unsigned int SupplyVoltageRequestToNode = 0x10C;
					const unsigned int DescriptionRequestToGroup = 0x10D;
					const unsigned int DescriptionRequestToNode = 0x10E;
					const unsigned int DeviceIDRequestToGroup = 0x10F;

					// Handled by functional firmware
					const unsigned int DeviceIDRequestToNode = 0x111;
					const unsigned int UptimeRequestToGroup = 0x112;
					const unsigned int UptimeRequestToNode = 0x113;
					const unsigned int HealthCheckRequestToGroup = 0x114;
					const unsigned int HealthCheckRequestToNode = 0x115;
				}

				namespace Normal
				{
					// Handled by functional firmware
					const unsigned int ButtonNodeMessage = 0x301;
					const unsigned int RelayMessage = 0x302;
					const unsigned int InfraredReceiverMessage = 0x303;
					const unsigned int TemperatureSensorMessage = 0x304;
					const unsigned int InfraredTransmitterMessage = 0x305;
					const unsigned int DimmerMessage = 0x306;
					const unsigned int BlindControllerMessage = 0x307;
					const unsigned int LedControllerMessage = 0x308;
				}
			}
		}
	}
}