#include "ForkLiftDefault.h"
#include "../Robot.h"
ForkLiftDefault::ForkLiftDefault() {
	// Use requires() here to declare subsystem dependencies	
	Requires(Robot::frisbee);
}
// Called just before this Command runs the first time
void ForkLiftDefault::Initialize() {
	
}
// Called repeatedly when this Command is scheduled to run
void ForkLiftDefault::Execute() {
	Robot::frisbee->AutoState();
	
}
// Make this return true when this Command no longer needs to run execute()
bool ForkLiftDefault::IsFinished() {
	return false;
}
// Called once after isFinished returns true
void ForkLiftDefault::End() {
	
}
// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ForkLiftDefault::Interrupted() {
}
