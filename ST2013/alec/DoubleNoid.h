/*
 * This controller assumes that the true state for the value means that a is on while b is off,
 * and that false state is that a is off and b is on.
 * 
 * kep[ jtnbe nin jmsindf AS YOIU OLJMYOREIEOPO ORKHGRMA THIS PRTLMEPGLOKME AT E 7UOIU DESEE OGLOELE5KM555666
 */

#ifndef MACARONI
#define MACARONI

#include "WPILib.h"

class DoubleNoid {
	Solenoid *a, *b;
	bool value;
public:
	DoubleNoid(){};
	DoubleNoid(Solenoid*,Solenoid*,bool=false);
	
	void setNoids(Solenoid*,Solenoid*,bool=false);
	Solenoid* getNoid(bool); // 0 = a, 1 = b
	Solenoid* operator[](bool);
	
	void setValue(bool);
	bool getValue();
};

#endif
