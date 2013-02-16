#include "Dump.h"
#include "WPILib.h"
#include "../Robot.h"

Dump::Dump() {
	// Use Requires() here to declare subsystem dependencies
//	Requires(Robot::conveyor);
}
// Called just before this Command runs the first time
void Dump::Initialize() {
	SetTimeout(5.0f);

}
// Called repeatedly when this Command is scheduled to run
void Dump::Execute() {
	
}
// Make this return true when this Command no longer needs to run execute()
bool Dump::IsFinished() {
	return IsTimedOut();
}
// Called once after isFinished returns true
void Dump::End() {

}
// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Dump::Interrupted() {

}
