#include "stop.h"
stop::stop() {
	Requires(Robot::driver);
}
// Called just before this Command runs the first time
void stop::Initialize() {
	
}
// Called repeatedly when this Command is scheduled to run
void stop::Execute() {
	Robot::driver->spd1->Set(0);
	Robot::driver->spd2->Set(0);
}
// Make this return true when this Command no longer needs to run execute()
bool stop::IsFinished() {
	return false;
}
// Called once after isFinished returns true
void stop::End() {
	
}
// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void stop::Interrupted() {
}
