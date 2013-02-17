/*
 * Frisbee Attitude Control
 */
#include "Conveyor.h"
#include "../Robotmap.h"
#include "../OI.h"
#include "WPILib.h"
#include "../Commands/ConveyorUp.h"

Conveyor::Conveyor() :
	Subsystem("Conveyor") {
	conv = RobotMap::conveyorRelay;
}

void Conveyor::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	SetDefaultCommand(new ConveyorUp);

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
}
