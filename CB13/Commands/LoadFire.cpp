#include "LoadFire.h"

LoadFire::LoadFire() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
}
// Called just before this Command runs the first time
void LoadFire::Initialize() {
	Robot::elevation->fire();
	
}
// Called repeatedly when this Command is scheduled to run
void LoadFire::Execute() {
	
}
// Make this return true when this Command no longer needs to run execute()
bool LoadFire::IsFinished() {
	return true;
}
// Called once after isFinished returns true
void LoadFire::End() {

}
// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void LoadFire::Interrupted() {
	
}
