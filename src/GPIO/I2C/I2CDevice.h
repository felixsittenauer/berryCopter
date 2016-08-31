#ifndef __I2CDEVICE_H_INCLUDED__
#define __I2CDEVICE_H_INCLUDED__

#include <iostream>
#include "../IGpio/IGpio.h"

class I2CDevice {
 public:
	I2CDevice(unsigned int t_I2CAddr, unsigned int t_busInterfaceId, IGpio& t_IGpioInstance); 
	~I2CDevice();

	int readRegister(unsigned int t_regAddr, char* buffer);

 protected:
 	unsigned int I2CHandleID, I2CAddr;
 	IGpio& IGpioInstance;
};

// busId: 1 --> 0 is not supported

#endif // __I2CDevice_H_INCLUDED__