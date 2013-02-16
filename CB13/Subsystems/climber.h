
#ifndef CLIMBER_H
#define CLIMBER_H
#include "Commands/Subsystem.h"
#include "WPILib.h"
/**
 *
 *
 * @author ExampleAuthor
 */
class climber: public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	Solenoid* sol1;
	Solenoid* sol2;
	SpeedController* spd1;
	climber();
	void InitDefaultCommand();
	void toggle();
	void move(float);
	void stop();
	bool toggle1;
};
#endif
