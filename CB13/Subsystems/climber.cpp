#include "climber.h"
#include "../Robotmap.h"
#include "../Robot.h"
climber::climber() : Subsystem("climber") {
	sol1 = RobotMap::climbersol1;
	sol2 = RobotMap::climbersol2;
	spd1 = RobotMap::climberspd1;
	toggle1 = true;
}
    
void climber::InitDefaultCommand() {
}


void climber::toggle(){
	if(toggle1){
		sol1->Set(false);
		sol2->Set(true);
	}else{
		sol1->Set(true);
		sol2->Set(false);
	}
	toggle1 = !toggle1;
}

void climber::move(float spd){
	spd1->Set(spd);
}

void climber::stop(){
	spd1->Set(0);
}
