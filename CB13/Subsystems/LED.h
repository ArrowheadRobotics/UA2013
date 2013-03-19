#ifndef LED_H
#define LED_H
#include "Commands/Subsystem.h"
#include "WPILib.h"

/**
 *
 *
 * @author Cyberhawk
 */
class LED: public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	
public:
	Relay* LED1;
	Relay* LED2;
	LED();
	void InitDefaultCommand();
	void red();
	void blue();
	void green();
	void pink();
	void yellow();
	void aqua();
	void white();
	void off();
	
};

#endif
