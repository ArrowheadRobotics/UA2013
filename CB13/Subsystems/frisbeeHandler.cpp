#include "frisbeeHandler.h"
#include "../Robotmap.h"
#include "../robot.h"
#include "WPILib.h"

frisbeeHandler::frisbeeHandler() : Subsystem("frisbeeHandler") {
	forkUp = RobotMap::frisbeeHandlersol1;
	forkDown = RobotMap::frisbeeHandlersol2;
	dump = RobotMap::frisbeeServo;
	
	//SetDefaultCommand(new ConveyorDefault());
}
    
void frisbeeHandler::InitDefaultCommand() {
}


void frisbeeHandler::toggle(){
	Robot::chute->chutelowextend->Set(false);
	if(Robot::frisbeeHandler->forkUp->Get()==true){
		Robot::frisbeeHandler->forkUp->Set(false);
		Robot::frisbeeHandler->forkDown->Set(true);
	}else{
		Robot::frisbeeHandler->forkUp->Set(true);
		Robot::frisbeeHandler->forkDown->Set(false);
	}
}

