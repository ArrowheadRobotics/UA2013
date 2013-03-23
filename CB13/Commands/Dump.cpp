#include "Dump.h"
#include "WPILib.h"
#include "../Robot.h"

Dump::Dump() {
	// Use Requires() here to declare subsystem dependencies
	Requires(Robot::conveyor);
	Requires(Robot::frisbee);
	t = new Timer();
	t->Reset();

}
// Called just before this Command runs the first time
void Dump::Initialize() {
	t->Start();
	t->Reset();
	if (Robot::oi->getgamepad()->GetRawAxis(3) > .8f) {
		RobotMap::frisbeesol1->Set(true);
		RobotMap::frisbeesol2->Set(false);
	}
	SetTimeout(5.0f);

}
// Called repeatedly when this Command is scheduled to run
void Dump::Execute() {
	printf("timer: %f\n", t->Get());
	RobotMap::frisbeeServo->Set(0.0f);
	if (t->Get() > .5f)
		Robot::conveyor->Purge();
	if (RobotMap::bottomLimit->Get()&&Robot::oi->getgamepad()->GetRawAxis(3) > .8f) {
		RobotMap::frisbeesol1->Set(true);
		RobotMap::frisbeesol2->Set(false);
	}
}
// Make this return true when this Command no longer needs to run execute()
bool Dump::IsFinished() {
	return IsTimedOut();

}
// Called once after isFinished returns true
void Dump::End() {
	Robot::conveyor->UnPurge();
	RobotMap::frisbeesol1->Set(false);
	RobotMap::frisbeesol2->Set(true);
	RobotMap::gatesol1->Set(false);
	RobotMap::gatesol2->Set(true);	
}
// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Dump::Interrupted() {
	Robot::conveyor->UnPurge();
	RobotMap::frisbeesol1->Set(false);
	RobotMap::frisbeesol2->Set(true);
	RobotMap::gatesol1->Set(false);
	RobotMap::gatesol2->Set(true);	
}
