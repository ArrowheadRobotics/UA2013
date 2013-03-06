#include "EnqElev.h"
EnqElev::EnqElev() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
}
// Called just before this Command runs the first time
void EnqElev::Initialize() {
	//will hold the dseio getters.  This will choose what value to set the setpoint at
}
// Called repeatedly when this Command is scheduled to run
void EnqElev::Execute() {
	Robot::elevation->elevationSetPoint = 3700;
	Robot::elevation->gotoSetPoint();
}
// Make this return true when this Command no longer needs to run execute()
bool EnqElev::IsFinished() {
	return false;
}
// Called once after isFinished returns true
void EnqElev::End() {
	Robot::elevation->Stop();
}
// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void EnqElev::Interrupted() {
	Robot::elevation->Stop();
}
