// RobotBuilder Version: 0.0.2
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in th future.
#include "move_up.h"
#include "../Subsystems/Elevation.h"
move_up::move_up() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::elevation);
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
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
	Robot::elevation->Up();
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
