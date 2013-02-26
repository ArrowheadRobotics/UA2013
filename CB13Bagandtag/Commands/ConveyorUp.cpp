#include "ConveyorUp.h"

ConveyorUp::ConveyorUp() {
	// Use requires() here to declare subsystem dependencies
	Requires(Robot::conveyor);
}
// Called just before this Command runs the first time
void ConveyorUp::Initialize() {

}
// Called repeatedly when this Command is scheduled to run
void ConveyorUp::Execute() {
	if (RobotMap::gatesol1->Get())
		Robot::conveyor->Move();
	else {
		Robot::conveyor->conv->Set(Relay::kOff);
	}
}
// Make this return true when this Command no longer needs to run execute()
bool ConveyorUp::IsFinished() {
	return false;
}
// Called once after isFinished returns true
void ConveyorUp::End() {

}
// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ConveyorUp::Interrupted() {
}
