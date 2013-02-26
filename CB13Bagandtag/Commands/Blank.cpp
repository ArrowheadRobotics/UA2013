#include "Blank.h"
Blank::Blank() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
}
// Called just before this Command runs the first time
void Blank::Initialize() {
	
}
// Called repeatedly when this Command is scheduled to run
void Blank::Execute() {
	
}
// Make this return true when this Command no longer needs to run execute()
bool Blank::IsFinished() {
	return false;
}
// Called once after isFinished returns true
void Blank::End() {
	
}
// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Blank::Interrupted() {
}
