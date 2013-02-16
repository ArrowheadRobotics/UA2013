#include "stateDrive.h"
stateDrive::stateDrive() {
	// Use requires() here to declare subsystem dependencies
	//requires(chassis);
	Requires(Robot::elevation);
	Requires(Robot::frisbeeHandler);
	Requires(Robot::chute);
}
// Called just before this Command runs the first time
void stateDrive::Initialize() {
	Robot::chute->lowExtend();
	Robot::chute->highExtend();
	Robot::gate->sol1->Set(false);
	Robot::gate->sol2->Set(true);
	Robot::frisbeeHandler->forkUp->Set(false);
	Robot::frisbeeHandler->forkDown->Set(true);
	Robot::elevation->recoil();
}
// Called repeatedly when this Command is scheduled to run
void stateDrive::Execute() {
	
}
// Make this return true when this Command no longer needs to run execute()
bool stateDrive::IsFinished() {
	return true;
}
// Called once after isFinished returns true
void stateDrive::End() {
	
}
// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void stateDrive::Interrupted() {
}
