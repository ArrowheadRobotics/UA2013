
#ifndef ROBOTMAP_H
#define ROBOTMAP_H
#include "WPILib.h"
/**
 * The RobotMap is a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of magic numbers
 * floating around.
 */
class RobotMap {
public:

	// Elevation *****************************************************
	static SpeedController* elevationSpd1;
	static Encoder* elevationqenc;
	static DigitalInput* bottomLimit;
	static Counter* OpticalShoot;
	static SpeedController* shooterSpd1;
	static Solenoid* firingpinIn;
	static Solenoid* firingpinOut;

	
	// Climber ***************************************************
	static Solenoid* chutelowextend;
	static Solenoid* chutelowretract;
	static Solenoid* chutehighextend;
	static Solenoid* chutehighretract;
	
	// Climber ***************************************************
	static SpeedController* climberspd1;
	
	// Gate ******************************************************
	static Solenoid* gatesol1;
	static Solenoid* gatesol2;
	
	// FrisbeeHandler ********************************************
	static Solenoid* frisbeeHandlersol1;
	static Solenoid* frisbeeHandlersol2;
	static Servo* frisbeeServo;
	static Relay* conveyor;
	
	// Climber ***************************************************
	static Solenoid* climbersol1;
	static Solenoid* climbersol2;
	
	// Drive *****************************************************
	static Encoder* driveren1;
	static Encoder* driveren2;
	static SpeedController* driverspd2;
	static SpeedController* driverspd1;
	static RobotDrive* driverdriveTrain;
	static Gyro* drivergyro1;

	// Robot *****************************************************
	static Compressor* compressor;
	static void init();
};
#endif
