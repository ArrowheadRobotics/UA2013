#include "fire.h"

Fire::Fire() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	t = new Timer();

	SetTimeout(.9f);
}
// Called just before this Command runs the first time
void Fire::Initialize() {
	Robot::elevation->fire();
	t->Reset();
	t->Start();
	printf("Init\n");
}
// Called repeatedly when this Command is scheduled to run
void Fire::Execute() {
	printf("Exec\n");

	if (t->Get() > .5f && RobotMap::bottomLimit->Get() != 1)
		Robot::elevation->recoil();
}
// Make this return true when this Command no longer needs to run execute()
bool Fire::IsFinished() {
	printf("Finish\n");
	return IsTimedOut();
}
// Called once after isFinished returns true
void Fire::End() {
	printf("End\n");
	if (RobotMap::bottomLimit->Get() != 1)
		Robot::elevation->recoil();
}
// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Fire::Interrupted() {
	printf("Int\n");
	Robot::elevation->recoil();
}
