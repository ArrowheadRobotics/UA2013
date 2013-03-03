#ifndef CHUTE_H
#define CHUTE_H
#include "Commands/Subsystem.h"
#include "WPILib.h"

class Chute: public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	Solenoid* chutelowextend;
	Solenoid* chutelowretract;
	Solenoid* chutehighextend;
	Solenoid* chutehighretract;
	int state;
	Chute();
	void lowExtend();
	void lowRetract();
	void highExtend();
	void highRetract();
	void resetState();
	void gotoState();
	void InitDefaultCommand();
	
};
#endif
