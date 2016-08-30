#ifndef __IGPIO_H_INCLUDED__
#define __IGPIO_H_INCLUDED__

#include <pigpio.h>
#include <iostream>

class IGpio {
 public:
	IGpio();
	~IGpio();

	int setMode(unsigned int t_gpioNb, unsigned int t_mode);
	int getMode(unsigned int t_gpioNb);

	int setPWM (unsigned int t_gpioNb, unsigned int t_open);
	int getPWM (unsigned int t_gpioNb);

	int setPWMFrequency (unsigned int t_gpioNb, unsigned int t_freq);
	int getPWMFrequency (unsigned int t_gpioNb);

	int setPWMRange (unsigned int t_gpioNb, unsigned int t_range);
	int getPWMRange (unsigned int t_gpioNb);
};

/*
Pin Types 
	Number:  -- -- -- 14 15 18 -- 23 24 -- 25 08 07 -- -- 12 -- 16 20 21
	Type:     5  5  G  X  X  X  G  X  X  G  X  X  X ID  G  X  G  X  X  X

	Number:  -- 02 03 04 -- 17 27 22 -- 10 09 11 -- -- 05 06 13 19 26 --
	Type:     3  X  X  X  G  X  X  X  3  X  X  X  G ID  X  X  X  X  X  G

Pin modes:
	PI_INPUT 0; PI_OUTPUT 1;
*/

#endif // __IGPIO_H_INCLUDED__