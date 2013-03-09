
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
	Counter* OpticalShoot;
	Solenoid* firingpinIn;
	Solenoid* firingpinOut;
	int elevationSetPoint;
	bool atSet;
	bool visionEnabled;
	double error;             //Proportional (P)
	double previousError;
	double errorSum;          //Integral     (I)
	double errorRateOfChange; //Derivative   (D)
	void gotoSetPoint(void);
	void isAtSetPoint(void);
	void pidCalc(double desiredRPM);
	void InitPID(double desiredRPM);
	Elevation();
	void InitDefaultCommand();
	void Up(float);
	void Down(float);
	void Stop();
	void ShooterStop();
	void FindBottom();
	void ShootLoop();
	void StopShootLoop();
	void fire();
	void recoil();
};
#endif
