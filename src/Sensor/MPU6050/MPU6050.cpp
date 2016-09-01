#include "MPU6050.h"

// --------------------
// FlightController constructor
MPU6050::MPU6050 (IGpio& t_IGpioInstance): 
	I2CDevice (0x68, 1, t_IGpioInstance)
{
}
// --------------------
// FlightController destructor
MPU6050::~MPU6050 () {
}
// --------------------

void MPU6050::reset () {
	char hex_00[] = { 0x00 };
	I2CDevice::writeRegister(MPU6050_PWR_MGMT_1, hex_00, 1);
}
// --------------------

void MPU6050::startLoop() {
	char lastValue[] = { 0x00 };
	char value[] = { 0x00 };
	char* p_value = value;
	char* p_lastValue = lastValue;

	for(;;) {
		I2CDevice::readRegister(0x75, p_value, 1);
		if (*p_lastValue != *p_value) {
			p_lastValue = p_value;
			printf("%02x ", *p_lastValue);
		}
	}
	
}