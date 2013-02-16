#include "drive3.h"
#include "../robot.h"
drive3::drive3() {
	Requires(Robot::driver);
}
// Called just before this Command runs the first time
void drive3::Initialize() {
	
}
// Called repeatedly when this Command is scheduled to run
void drive3::Execute() {
	//TODO Update joystiq Here or see note above
	Robot::driver->M_drive(Robot::oi->getgamepad1(), Robot::oi->getgamepad2());
}
// Make this return true when this Command no longer needs to run execute()
bool drive3::IsFinished() {
	return false;
}
// Called once after isFinished returns true
void drive3::End() {
	
}
// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void drive3::Interrupted() {
}
