/*
 * Frisbee Attitude Control
 */
#include "Conveyor.h"
#include "../Robotmap.h"
#include "../OI.h"
#include "WPILib.h"

Conveyor::Conveyor() :
	Subsystem("Conveyor") {
	conv = RobotMap::conveyorRelay;
}

void Conveyor::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());

}
// Put methods for controlling this subsystem
// here. Call these from Commands.
void Conveyor::Move(){
	conv->Set(Relay::kForward);
	if(RobotMap::forkLiftSW->Get()){
		conv->Set(Relay::kOff);
	}
}
