//#include "../Subsystems/Elevation.h"
#include "ShootController.h"
#include "../Robot.h"
ShootController::ShootController() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);

}
// Called just before this Command runs the first time
void ShootController::Initialize() {
Robot::elevation->InitPID(3000.0f);
	
}
// Called repeatedly when this Command is scheduled to run
void ShootController::Execute() {
	//printf("Period: %f",Robot::elevation->OpticalShoot->GetPeriod());
	Robot::elevation->pidCalc(3000.0f);
}
// Make this return true when this Command no longer needs to run execute()
bool ShootController::IsFinished() {
	return false;
}
// Called once after isFinished returns true
void ShootController::End() {
}

void ShootController::Interrupted() {
}

