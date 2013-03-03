#include "IncChuteState.h"
IncChuteState::IncChuteState() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
}
// Called just before this Command runs the first time
void IncChuteState::Initialize() {
	Robot::chute->state++;
}
// Called repeatedly when this Command is scheduled to run
void IncChuteState::Execute() {
	Robot::chute->gotoState();
}
// Make this return true when this Command no longer needs to run execute()
bool IncChuteState::IsFinished() {
	return false;
}
// Called once after isFinished returns true
void IncChuteState::End() {
	
}
// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void IncChuteState::Interrupted() {
}
