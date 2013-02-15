#include "frisbeeHandler.h"
#include "../Robotmap.h"
#include "../robot.h"
frisbeeHandler::frisbeeHandler() : Subsystem("frisbeeHandler") {
	sol1 = RobotMap::frisbeeHandlersol1;
	sol2 = RobotMap::frisbeeHandlersol2;
}
    
void frisbeeHandler::InitDefaultCommand() {
}


void frisbeeHandler::toggle(){
	if(Robot::frisbeeHandler->sol1->Get()==true){
		Robot::frisbeeHandler->sol1->Set(false);
		Robot::frisbeeHandler->sol2->Set(true);
	}else{
		Robot::frisbeeHandler->sol1->Set(true);
		Robot::frisbeeHandler->sol2->Set(false);
	}
}
