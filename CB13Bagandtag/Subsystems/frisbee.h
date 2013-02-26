#ifndef FRISBEE_H
#define FRISBEE_H
#include "Commands/Subsystem.h"
#include "WPILib.h"

class Frisbee: public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	Solenoid* sol1;
	Solenoid* sol2;
	Frisbee();
	void InitDefaultCommand();
	void toggle();
	bool toggleState;
	void AutoState();
	Timer* t;
	bool isNormal;
};
#endif
