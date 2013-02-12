
#ifndef ELEVATION_H
#define ELEVATION_H
#include "Commands/Subsystem.h"
#include "WPILib.h"
/**
 *
 *
 * @author ExampleAuthor
 */
class Elevation: public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:

	SpeedController* spd1;
	SpeedController* shooterSpd;
	Encoder* qenc;
	DigitalInput* bottomLimit;

	Elevation();
	void InitDefaultCommand();
	void Up(float);
	void Down(float);
	void Stop();
	void FindBottom();
};
#endif
