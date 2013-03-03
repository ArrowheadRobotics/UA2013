#include "Chute.h"
#include "../Robotmap.h"
#include "../Robot.h"
Chute::Chute() : Subsystem("chute") {
	chutelowextend = RobotMap::chutelowextend;
	chutelowretract = RobotMap::chutelowretract;
	chutehighextend = RobotMap::chutehighextend;
	chutehighretract = RobotMap::chutehighretract;
	state = 0;
		
}
    
void Chute::InitDefaultCommand() {

}
void Chute::resetState() {//Run this during auto, resets and zeros the state machine
	Robot::chute->chutehighextend->Set(false);
	Robot::chute->chutehighretract->Set(true);
	Robot::chute->chutelowextend->Set(false);
	Robot::chute->chutelowretract->Set(true);
	state = 0;
}

void Chute::gotoState(){
	if(state<0) state = 0;
	if(state>2) state = 2;
	if(state==0){//hood is down
		Robot::chute->chutehighextend->Set(false);
		Robot::chute->chutehighretract->Set(true);
		Robot::chute->chutelowextend->Set(false);
		Robot::chute->chutelowretract->Set(true);
	}
	else if(state==1){//feeding positon
		Robot::chute->chutehighextend->Set(false);
		Robot::chute->chutehighretract->Set(true);
		Robot::chute->chutelowextend->Set(true);
		Robot::chute->chutelowretract->Set(false);
		
	}
	else if(state==2){//defensive position
		Robot::chute->chutehighextend->Set(true);
		Robot::chute->chutehighretract->Set(false);
		Robot::chute->chutelowextend->Set(true);
		Robot::chute->chutelowretract->Set(false);
	}
}

void Chute::lowExtend(){
	Robot::chute->chutelowextend->Set(true);
	Robot::chute->chutelowretract->Set(false);
}
void Chute::lowRetract(){
	Robot::chute->chutelowextend->Set(false);
	Robot::chute->chutelowretract->Set(true);
}
void Chute::highExtend(){
	Robot::chute->chutehighextend->Set(true);
	Robot::chute->chutehighretract->Set(false);
}
void Chute::highRetract(){
	Robot::chute->chutehighextend->Set(false);
	Robot::chute->chutehighretract->Set(true);
}

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
