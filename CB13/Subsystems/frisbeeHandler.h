
#ifndef FRISBEEHANDLER_H
#define FRISBEEHANDLER_H
#include "Commands/Subsystem.h"
#include "WPILib.h"
/**
 *
 *
 * @author ExampleAuthor
 */
class frisbeeHandler: public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	Solenoid* forkUp;
	Solenoid* forkDown;
	Servo* dump;
	Relay* conveyor;
	frisbeeHandler();
	void InitDefaultCommand();
	void toggle();
};
#endif
