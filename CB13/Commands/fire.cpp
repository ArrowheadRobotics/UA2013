#include "fire.h"

Fire::Fire() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	t = new Timer();
	
	SetTimeout(1.0f);
}
// Called just before this Command runs the first time
void Fire::Initialize() {
	Robot::elevation->fire();
	t->Reset();
	t->Start();
}
// Called repeatedly when this Command is scheduled to run
void Fire::Execute() {
	if(t->Get()>.5)Robot::elevation->recoil();
}
// Make this return true when this Command no longer needs to run execute()
bool Fire::IsFinished() {
	return IsTimedOut();
}
// Called once after isFinished returns true
void Fire::End() {
	Robot::elevation->recoil();
}
// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Fire::Interrupted() {
	Robot::elevation->recoil();
}
