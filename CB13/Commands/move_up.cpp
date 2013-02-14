#include "move_up.h"
#include "../Subsystems/Elevation.h"
move_up::move_up() {
	Requires(Robot::elevation);
	//SetTimeout(0.5);
}
// Called just before this Command runs the first time
void move_up::Initialize() {
	printf("move_up - init\n");
	//Robot::elevation->Up();
}
// Called repeatedly when this Command is scheduled to run
void move_up::Execute() {
	//Robot::elevation->spd1->Set(Robot::oi->getJoy1()->GetY());
	//printf("encoder %d\n",Robot::elevation->qenc->Get());
	Robot::elevation->Up(.3f);
}
// Make this return true when this Command no longer needs to run execute()
bool move_up::IsFinished() {
	return false;
}
// Called once after isFinished returns true
void move_up::End() {
	printf("move_up -end\n");
}
// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void move_up::Interrupted() {
	printf("move_up - interrup\n");
	Robot::elevation->Stop();
}
