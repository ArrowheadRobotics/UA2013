/*
 * Frisbee Attitude Control
 */
#include "Elevation.h"
#include "../Robotmap.h"
#include "../OI.h"
#include "WPILib.h"
#include "../Robot.h"
Elevation::Elevation() :
	Subsystem("Elevation") {

	spd1 = RobotMap::elevationSpd1;
	qenc = RobotMap::elevationqenc;
	bottomLimit = RobotMap::bottomLimit;
	shooterSpd = RobotMap::shooterSpd1;
}

void Elevation::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());

}
// Put methods for controlling this subsystem
// here. Call these from Commands.
void Elevation::Up(float value) {
	if (Robot::elevation->qenc->Get() < 4000) {
		spd1->Set(value);
	} else {
		spd1->Set(0.0f);
	}

}
void Elevation::Down(float value) {
	/* 
	 * Down provides encoder protection
	 * float value needs to be negative for the elevation to go down
	 */
	printf("Down %d", bottomLimit->Get());
	float setval = 0.0f;
	if (Robot::elevation->qenc->Get() > 250) {
		setval = value;
	} else {
		setval = 0.1f;
	}
	if (bottomLimit->Get() == 0) {
		Robot::elevation->qenc->Reset();
		setval = 0.0f;

	}
	spd1->Set(setval);
}
void Elevation::Stop() {
	spd1->Set(0.0);
	printf("%d\n", Robot::elevation->qenc->Get());
}
void Elevation::FindBottom() {
	/*
	 * Finds the bottom and resets the encoder
	 * Not Tested
	 */
	spd1->Set(-0.1f); //Move the elevation down
	while (!bottomLimit->Get() == 0);//Wait until bottom
	Robot::elevation->qenc->Reset();//Reset the Encoder
	spd1->Set(0.0f);//Stop the motor

}

void Elevation::ShootLoop(){
	shooterSpd->Set(1.0f);
}
void Elevation::StopShootLoop(){
	shooterSpd->Set(0.0f);
}
