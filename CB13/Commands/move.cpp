#include "move.h"
#include "../Subsystems/gate.h"
#include "../Robot.h"
move::move() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	Requires(Robot::gate);

}
// Called just before this Command runs the first time
void move::Initialize() {
	Robot::gate->toggle();
}
// Called repeatedly when this Command is scheduled to run
void move::Execute() {
	
}
// Make this return true when this Command no longer needs to run execute()
bool move::IsFinished() {
	return true;
}
// Called once after isFinished returns true
void move::End() {
	
}
// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void move::Interrupted() {
}
