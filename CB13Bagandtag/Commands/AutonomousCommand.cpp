#include "AutonomousCommand.h"
#include "fire.h"
AutonomousCommand::AutonomousCommand() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
}
// Called just before this Command runs the first time
void AutonomousCommand::Initialize() {
	Robot::elevation->InitPID(6000.0f);
	Robot::chute->highRetract();
	Robot::chute->lowRetract();
	
}
// Called repeatedly when this Command is scheduled to run
void AutonomousCommand::Execute() {
	Robot::elevation->pidCalc(6000.0f);

}
// Make this return true when this Command no longer needs to run execute()
bool AutonomousCommand::IsFinished() {
	return false;
}
// Called once after isFinished returns true
void AutonomousCommand::End() {
	
}
// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutonomousCommand::Interrupted() {
}
