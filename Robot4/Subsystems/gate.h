#ifndef GATE_H
#define GATE_H
#include "Commands/Subsystem.h"
#include "WPILib.h"

class gate: public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	Solenoid* sol1;
	Solenoid* sol2;
	gate();
	void InitDefaultCommand();
	void toggle();
};
#endif
