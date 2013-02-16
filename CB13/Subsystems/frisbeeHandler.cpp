#include "frisbeeHandler.h"
#include "../Robotmap.h"
#include "../robot.h"
#include "WPILib.h"
#include "../Commands/conveyorDefault.h"
frisbeeHandler::frisbeeHandler() : Subsystem("frisbeeHandler") {
	forkUp = RobotMap::frisbeeHandlersol1;
	forkDown = RobotMap::frisbeeHandlersol2;
	dump = RobotMap::frisbeeServo;
	conveyor = RobotMap::conveyor;
	SetDefaultCommand(new ConveyorDefault());
}
    
void frisbeeHandler::InitDefaultCommand() {
}


void frisbeeHandler::toggle(){
	if(Robot::frisbeeHandler->forkUp->Get()==true){
		RobotMap::frisbeeHandlersol1->Set(false);
		RobotMap::frisbeeHandlersol2->Set(true);
	}else{
		RobotMap::frisbeeHandlersol1->Set(true);
		RobotMap::frisbeeHandlersol2->Set(false);
	}
}

void frisbeeHandler::dumpUp(){
	dump->Set(1.0f);
}
void frisbeeHandler::dumpDown(){
	dump->Set(0.0f);
}

void frisbeeHandler::conveyorUp(){
	conveyor->Set(Relay::kForward);
}
void frisbeeHandler::conveyorDown(){
	conveyor->Set(Relay::kReverse);
}
void frisbeeHandler::conveyorStaaaaaaahp(){
	conveyor->Set(Relay::kOff);
}

