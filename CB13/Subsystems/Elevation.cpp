/*
 * Frisbee Attitude Control
 */
#include "Elevation.h"
#include "../Robotmap.h"
#include "../OI.h"
#include "WPILib.h"
#include "../Robot.h"
#include "../Commands/move_up.h"
#define CONTROL_LOOP_TIME 0.040 //40 Millisecond loop time

/*#define KP 100
#define KI 15
#define KD 25*/

extern "C" { 
	volatile float KP = 150.0f;
	volatile float KI = 35.0f;
	volatile float KD = 15.0f;
};

Elevation::Elevation() :
	Subsystem("Elevation") {

	spd1 = RobotMap::elevationSpd1;
	qenc = RobotMap::elevationqenc;
	bottomLimit = RobotMap::bottomLimit;
	shooterSpd = RobotMap::shooterSpd1;
	OpticalShoot = RobotMap::OpticalShoot;
	firingpinIn = RobotMap::firingpinIn;
	firingpinOut = RobotMap::firingpinOut;
	
}

void Elevation::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new move_up);

}
// Put methods for controlling this subsystem
// here. Call these from Commands.
void Elevation::Up(float value) {
	if (Robot::elevation->qenc->Get() < 5360) {
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
	if (Robot::elevation->qenc->Get() > 500) {
		setval = value;
	} else {
		setval = 0.2f;
	}
	if (bottomLimit->Get() == 1) {
		Robot::elevation->qenc->Reset();
		setval = 0.0f;

	}
	spd1->Set(setval);
}
void Elevation::Stop() {//stops the elevation
	spd1->Set(0.0);
	
}
void Elevation::ShooterStop() {
	shooterSpd->Set(0.0);
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
	shooterSpd->Set(1.0f);
	
}
void Elevation::StopShootLoop(){
	shooterSpd->Set(0.0f);
}

void Elevation::InitPID(double desiredRPM){
	 previousError = desiredRPM - 60.0f/(OpticalShoot->GetPeriod());
	 errorSum = 0;
}

void Elevation::pidCalc(double desiredRPM){
    error = desiredRPM - 60.0f/(OpticalShoot->GetPeriod());
    errorSum = errorSum + (error*CONTROL_LOOP_TIME);
    errorRateOfChange = (error - previousError)/CONTROL_LOOP_TIME;
    previousError = error;
    double output = 0;
    output += ((KP*error)+(KI*errorSum)+(KD*errorRateOfChange));
    if (output < 0.0f) output = 0.0f;//shouldn't ever really happen
    shooterSpd->Set(output);
   // printf("PID output: %f\n",output);
}

void Elevation::fire(){
	RobotMap::firingpinIn->Set(true);
	RobotMap::firingpinOut->Set(false);
}
void Elevation::recoil(){
	RobotMap::firingpinIn->Set(false);
	RobotMap::firingpinOut->Set(true);
}
void Elevation::gotoSetPoint(){
	printf("Enq %d Setpoint %d\n Motor: %f",qenc->Get(),elevationSetPoint,-.7*(qenc->Get()-elevationSetPoint)/elevationSetPoint);
	if((-100*(elevationSetPoint-qenc->Get())/elevationSetPoint)<.15&&(-100*(elevationSetPoint-qenc->Get())/elevationSetPoint)>-.15)Robot::elevation->Stop();
	else if(qenc->Get()<elevationSetPoint-100) {
		printf("Below\n");
		Robot::elevation->Up(-100*(elevationSetPoint-qenc->Get())/elevationSetPoint);
	}else if (qenc->Get()>elevationSetPoint+100){
		Robot::elevation->Down(-100*(elevationSetPoint-qenc->Get())/elevationSetPoint);
		printf("Above\n");
	}
	else{
		printf("Else\n");
		Robot::elevation->Stop();
	}
	
}
void Elevation::isAtSetPoint(){
}
