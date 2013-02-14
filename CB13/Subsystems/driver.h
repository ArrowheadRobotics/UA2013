
#ifndef DRIVER_H
#define DRIVER_H
#include "Commands/Subsystem.h"
#include "WPILib.h"
/**
 *
 *
 * @author ExampleAuthor
 */
class driver: public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	Encoder* en1;
	Encoder* en2;
	SpeedController* spd2;
	SpeedController* spd1;
	RobotDrive* driveTrain;
	Gyro* gyro1;
	driver();
	void InitDefaultCommand();
	void M_drive(Joystick* stick1, Joystick* stick2);
	void read();
	void reset();
};
#endif
