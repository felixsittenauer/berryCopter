#include "I2CDevice.h"

// --------------------
// FlightController constructor
I2CDevice::I2CDevice(unsigned int t_I2CAddr, unsigned int t_busInterfaceId, IGpio& t_IGpioInstance):
	I2CAddr(t_I2CAddr),
	IGpioInstance(t_IGpioInstance)
{
	this->I2CHandleID = (this->IGpioInstance).registerI2CDevice(t_busInterfaceId, this->I2CAddr);
	if(this->I2CHandleID >= 0) {
		std::cout << "I2C device "<< this->I2CAddr <<" Registered at " << this->I2CHandleID << "\n";
	} else {
		std::cout << "FAILED to register I2C device "<< this->I2CAddr << "\n";
	}
}
// --------------------
// FlightController destructor
I2CDevice::~I2CDevice() {
	(this->IGpioInstance).unregisterI2CDevice(this->I2CHandleID);
}
// --------------------

int I2CDevice::readRegister(unsigned int t_regAddr, unsigned int* t_byte) {
	unsigned int readByte = (this->IGpioInstance).readI2CRegisterByte(this->I2CHandleID, t_regAddr);
	//std::cout << "I2C READ " << readBytesCount  << " / " << t_byteCount << " B from register " << t_regAddr << " deviceAddr: " << this->I2CAddr << " I2CHandleId: " << this->I2CHandleID <<  "\n";
	t_byte = &readByte;
	return 1;
}

int I2CDevice::writeRegister(unsigned int t_regAddr, unsigned int* t_byte) {
	int result = (this->IGpioInstance).writeI2CRegisterByte(this->I2CHandleID, t_regAddr, *t_byte);
	//std::cout << "I2C WRITE " << t_byteCount << " B to register " << t_regAddr << " deviceAddr: " << this->I2CAddr << " I2CHandleId: " << this->I2CHandleID <<  "\n";
	if (result == 0) {
		return 1;
	} else {
		return 0;
	}
}