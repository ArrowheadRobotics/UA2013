#include "Chute.h"
#include "../Robotmap.h"
#include "../Robot.h"
Chute::Chute() : Subsystem("chute") {
	chutelowextend = RobotMap::chutelowextend;
	chutelowretract = RobotMap::chutelowretract;
	chutehighextend = RobotMap::chutehighextend;
	chutehighretract = RobotMap::chutehighretract;
		
}
    
void Chute::InitDefaultCommand() {

}

void Chute::lowExtend(){}
void Chute::lowRetract(){}
void Chute::highExtend(){}
void Chute::highRetract(){}

void allOn(){
	Robot::chute->chutehighextend->Set(true);
	Robot::chute->chutelowextend->Set(true);
	Robot::chute->chutehighretract->Set(true);
	Robot::chute->chutelowretract->Set(true);
}
void allOff(){
	Robot::chute->chutehighextend->Set(false);
	Robot::chute->chutelowextend->Set(false);
	Robot::chute->chutehighretract->Set(false);
	Robot::chute->chutelowretract->Set(false);	
}
