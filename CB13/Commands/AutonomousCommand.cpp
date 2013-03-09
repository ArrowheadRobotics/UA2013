#include "AutonomousCommand.h"
#include "fire.h"
Timer t;
AutonomousCommand::AutonomousCommand() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	

}
// Called just before this Command runs the first time
void AutonomousCommand::Initialize() {
	//Robot::elevation->InitPID(6000.0f);
	Robot::chute->resetState();
	t.Start();
	t.Reset();
	
}
// Called repeatedly when this Command is scheduled to run
void AutonomousCommand::Execute() {
//	Robot::elevation->pidCalc(6000.0f);
	if(t.Get()<2.0f){	
	Robot::elevation->recoil();
	Robot::elevation->ShootLoop();
	Robot::elevation->elevationSetPoint = 3400;
	if(!Robot::elevation->atSet)Robot::elevation->gotoSetPoint();
	}
	if(t.Get()>2.0f&&t.Get()<2.1f)Robot::elevation->firingpinIn->Set(true);
	if(t.Get()>2.0f&&t.Get()<2.1f)Robot::elevation->firingpinOut->Set(false);
	if(t.Get()>2.5f&&t.Get()<2.6f)Robot::elevation->firingpinIn->Set(false);
	if(t.Get()>2.5f&&t.Get()<2.6f)Robot::elevation->firingpinOut->Set(true);

	if(t.Get()>3.0f&&t.Get()<3.1f)Robot::elevation->firingpinIn->Set(true);
	if(t.Get()>3.0f&&t.Get()<3.1f)Robot::elevation->firingpinOut->Set(false);
	if(t.Get()>3.5f&&t.Get()<3.6f)Robot::elevation->firingpinIn->Set(false);
	if(t.Get()>3.5f&&t.Get()<3.6f)Robot::elevation->firingpinOut->Set(true);

	if(t.Get()>4.0f&&t.Get()<4.1f)Robot::elevation->firingpinIn->Set(true);
	if(t.Get()>4.0f&&t.Get()<4.1f)Robot::elevation->firingpinOut->Set(false);
	if(t.Get()>4.5f&&t.Get()<4.6f)Robot::elevation->firingpinIn->Set(false);
	if(t.Get()>4.5f&&t.Get()<4.6f)Robot::elevation->firingpinOut->Set(true);
	
	if(t.Get()>5.0f&&t.Get()<5.1f)Robot::elevation->firingpinIn->Set(true);
	if(t.Get()>5.0f&&t.Get()<5.1f)Robot::elevation->firingpinOut->Set(false);
	if(t.Get()>5.5f&&t.Get()<5.6f)Robot::elevation->firingpinIn->Set(false);
	if(t.Get()>5.5f&&t.Get()<5.6f)Robot::elevation->firingpinOut->Set(true);
	
	if(t.Get()>5.6f&&t.Get()<6.5){
	Robot::elevation->ShooterStop();
	Robot::elevation->elevationSetPoint = 0;
	if(!Robot::elevation->atSet)Robot::elevation->gotoSetPoint();
	}
	if(t.Get()>6.6f&&t.Get()<10.0f){
			printf("enq %d ",Robot::driver->en1->Get());
		if(Robot::driver->en1->Get()>-520){
//			Robot::driver->spd1->Set(.7f);
//			Robot::driver->spd2->Set(.7f);
		}
		else{
			
		}
	}

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
