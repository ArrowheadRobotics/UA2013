/*
 * Frisbee Attitude Control
 */
#include "Conveyor.h"
#include "../Robotmap.h"
#include "../OI.h"
#include "WPILib.h"
#include "../Commands/ConveyorUp.h"
#include "../Commands/frisbeeToggle.h"

Conveyor::Conveyor() :
	Subsystem("Conveyor") {
	conv = RobotMap::conveyorRelay;
	dumpsty = RobotMap::frisbeeServo;
}

void Conveyor::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	SetDefaultCommand(new ConveyorUp);
	cycled = false;
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
void Conveyor::Move(){
	

	if(!RobotMap::forkLiftSW->Get()){
		conv->Set(Relay::kOff);		
	}
	else{
		conv->Set(Relay::kForward);
	
	}
	dumpsty->Set(1.0f);
	
}

void Conveyor::Purge(){
	conv->Set(Relay::kReverse);
	dumpsty->Set(0.0f);
}
void Conveyor::UnPurge(){
	dumpsty->Set(1.0f);
}


