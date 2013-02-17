#include "ConveyorUp.h"

ConveyorUp::ConveyorUp() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
}
// Called just before this Command runs the first time
void ConveyorUp::Initialize() {
	Robot::conveyor->Move();
}
// Called repeatedly when this Command is scheduled to run
void ConveyorUp::Execute() {
	
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
