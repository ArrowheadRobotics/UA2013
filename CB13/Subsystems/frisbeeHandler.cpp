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
		Robot::frisbeeHandler->forkUp->Set(false);
		Robot::frisbeeHandler->forkDown->Set(true);
	}else{
		Robot::frisbeeHandler->forkUp->Set(true);
		Robot::frisbeeHandler->forkDown->Set(false);
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

