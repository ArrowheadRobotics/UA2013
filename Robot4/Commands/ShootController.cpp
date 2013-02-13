
#include "ShootController.h"
ShootController::ShootController() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);

}
// Called just before this Command runs the first time
void ShootController::Initialize() {}
// Called repeatedly when this Command is scheduled to run
void ShootController::Execute() {}
// Make this return true when this Command no longer needs to run execute()
bool ShootController::IsFinished() {
	return true;
}
// Called once after isFinished returns true
void ShootController::End() {}

void ShootController::Interrupted() {
}

