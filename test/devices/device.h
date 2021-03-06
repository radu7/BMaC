/*
	device.h - Header file for the Device class.
	
	Revision 0
	
	Notes:
			- 
			
	2018/09/18, Maya Posch
*/


#ifndef DEVICE_H
#define DEVICE_H


#include "config.h"
#include "types.h"


class Device {
	RoomState* roomState;
	Connection connType;
	std::string device;
	std::string mac;
	int spi_cs;
	int i2c_address;
	int uart_baud;		// UART baud rate.
	int uart_dev;		// UART peripheral (0, 1, etc.)
	Config devConf;
	bool deviceState;
	uint8_t i2c_register;
	
	void send(std::string data);
	
public:
	Device() { }
	Device(std::string id, Config &config, std::unique_ptr<RoomState> &rs);
	/* uint8_t readRegister8(int reg);
	void writeRegister8(int reg, uint8_t data); */
	void setMAC(std::string mac);
	Connection connectionType() { return connType; }
	int spiCS() { return spi_cs; }
	int i2cAddress() { return i2c_address; }
	
	bool write(std::string bytes);
	std::string read();
	std::string read(int length);
};


#endif
