/*
 * Frisbee Attitude Control
 */
#include "Elevation.h"
#include "../Robotmap.h"
#include "../OI.h"
#include "WPILib.h"
#include "../Robot.h"
#define CONTROL_LOOP_TIME 0.040 //20 Millisecond loop time
#define KP 1.0
#define KI 0.00000
#define KD 0.00000

Elevation::Elevation() :
	Subsystem("Elevation") {

	spd1 = RobotMap::elevationSpd1;
	qenc = RobotMap::elevationqenc;
	bottomLimit = RobotMap::bottomLimit;
	shooterSpd = RobotMap::shooterSpd1;
	OpticalShoot = RobotMap::OpticalShoot;
	
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
	//printf("%d\n", Robot::elevation->qenc->Get());
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
	if(60.0f/(OpticalShoot->GetPeriod())>6000.0f)shooterSpd->Set(0.0f);
	else shooterSpd->Set(1.0f);
	
}
void Elevation::StopShootLoop(){
	shooterSpd->Set(0.0f);
}

void Elevation::InitPID(double desiredRPM){
	 previousError = desiredRPM - 60.0f/(OpticalShoot->GetPeriod());
	 errorSum = 0;
}

double Elevation::pidCalc(double desiredRPM){
    error = desiredRPM - 60.0f/(OpticalShoot->GetPeriod());
    errorSum = errorSum + (error*CONTROL_LOOP_TIME);
    errorRateOfChange = (error - previousError)/CONTROL_LOOP_TIME;
    previousError = error;
    double output = 0;
    output += ((KP*error)+(KI*errorSum)+(KD*errorRateOfChange));
    if (output < 0.0f) output = 0.0f;//shouldn't ever really happen
    return output;
}
