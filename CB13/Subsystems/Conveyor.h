

#ifndef CONVEYOR_H
#define CONVEYOR_H
#include "Commands/Subsystem.h"
#include "WPILib.h"
/**
 *
 *
 * @author ExampleAuthor
 */
class Conveyor: public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	Conveyor();
	void InitDefaultCommand();
	void Move();
	Relay* conv;
	Servo* dumpsty;
	
	void Purge();
	void UnPurge();
	bool cycled;
};
#endif
