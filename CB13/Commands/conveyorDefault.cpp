#include "ConveyorDefault.h"
#include "../Robot.h"
ConveyorDefault::ConveyorDefault() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
}
// Called just before this Command runs the first time
void ConveyorDefault::Initialize() {
	
}
// Called repeatedly when this Command is scheduled to run
void ConveyorDefault::Execute() {
	Robot::frisbeeHandler->conveyorUp();
	
}
// Make this return true when this Command no longer needs to run execute()
bool ConveyorDefault::IsFinished() {
	return false;
}
// Called once after isFinished returns true
void ConveyorDefault::End() {
	Robot::frisbeeHandler->conveyorStaaaaaaahp();
}
// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ConveyorDefault::Interrupted() {
	Robot::frisbeeHandler->conveyorStaaaaaaahp();
}
