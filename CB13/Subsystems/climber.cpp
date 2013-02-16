#include "climber.h"
#include "../Robotmap.h"
#include "../Robot.h"
climber::climber() : Subsystem("climber") {
	sol1 = RobotMap::climbersol1;
	sol2 = RobotMap::climbersol2;
	spd1 = RobotMap::climberspd1;
}
    
void climber::InitDefaultCommand() {
}


void climber::toggle(){
	if(Robot::climber->sol1->Get()==true){
		RobotMap::climbersol1->Set(false);
		RobotMap::climbersol2->Set(true);
	}else{
		RobotMap::climbersol1->Set(true);
		RobotMap::climbersol2->Set(false);
	}
}

void climber::move(float spd){
	Robot::climber->spd1->Set(spd);
}

void climber::stop(){
	Robot::climber->spd1->Set(0);
}
