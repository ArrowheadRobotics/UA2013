#include "climber.h"
#include "../Robotmap.h"
#include "../Robot.h"
climber::climber() : Subsystem("climber") {
	sol1 = RobotMap::climbersol1;
	sol2 = RobotMap::climbersol2;
}
    
void climber::InitDefaultCommand() {
}


void climber::toggle(){
	if(Robot::climber->sol1->Get()==true){
		Robot::climber->sol1->Set(false);
		Robot::climber->sol2->Set(true);
	}else{
		Robot::climber->sol1->Set(true);
		Robot::climber->sol2->Set(false);
	}
}
