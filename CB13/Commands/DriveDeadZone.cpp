#include "DriveDeadZone.h"
#include "../robot.h"
DriveDeadZone::DriveDeadZone() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
}
// Called just before this Command runs the first time
void DriveDeadZone::Initialize() {
	
}
// Called repeatedly when this Command is scheduled to run
void DriveDeadZone::Execute() {
	Robot::driver->drive2(Robot::oi->getjoy1(), Robot::oi->getjoy2());
}
// Make this return true when this Command no longer needs to run execute()
bool DriveDeadZone::IsFinished() {
	return false;
}
// Called once after isFinished returns true
void DriveDeadZone::End() {
	
}
// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveDeadZone::Interrupted() {
}
