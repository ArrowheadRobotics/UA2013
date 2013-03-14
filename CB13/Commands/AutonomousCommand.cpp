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
	printf("TIME: %f   ",t.Get());
	printf("JOY1  %f      JOY2  %f\n",Robot::oi->getjoy1()->GetZ(), Robot::oi->getjoy2()->GetZ());
	//	Robot::elevation->pidCalc(6000.0f);
	if (t.Get() < 2.0f) {
		Robot::elevation->recoil();
		Robot::elevation->ShootLoop();
		Robot::elevation->elevationSetPoint = 3400;
		if (!Robot::elevation->atSet)
			Robot::elevation->gotoSetPoint();
	}
	if (t.Get() > 2.0f && t.Get() < 2.1f)
		Robot::elevation->firingpinIn->Set(true);
	if (t.Get() > 2.0f && t.Get() < 2.1f)
		Robot::elevation->firingpinOut->Set(false);
	if (t.Get() > 2.5f && t.Get() < 2.6f)
		Robot::elevation->firingpinIn->Set(false);
	if (t.Get() > 2.5f && t.Get() < 2.6f)
		Robot::elevation->firingpinOut->Set(true);

	if (t.Get() > 3.0f && t.Get() < 3.1f)
		Robot::elevation->firingpinIn->Set(true);
	if (t.Get() > 3.0f && t.Get() < 3.1f)
		Robot::elevation->firingpinOut->Set(false);
	if (t.Get() > 3.5f && t.Get() < 3.6f)
		Robot::elevation->firingpinIn->Set(false);
	if (t.Get() > 3.5f && t.Get() < 3.6f)
		Robot::elevation->firingpinOut->Set(true);

	if (t.Get() > 4.0f && t.Get() < 4.1f)
		Robot::elevation->firingpinIn->Set(true);
	if (t.Get() > 4.0f && t.Get() < 4.1f)
		Robot::elevation->firingpinOut->Set(false);
	if (t.Get() > 4.5f && t.Get() < 4.6f)
		Robot::elevation->firingpinIn->Set(false);
	if (t.Get() > 4.5f && t.Get() < 4.6f)
		Robot::elevation->firingpinOut->Set(true);

	if (t.Get() > 5.0f && t.Get() < 5.1f)
		Robot::elevation->firingpinIn->Set(true);
	if (t.Get() > 5.0f && t.Get() < 5.1f)
		Robot::elevation->firingpinOut->Set(false);
	if (t.Get() > 5.5f && t.Get() < 5.6f)
		Robot::elevation->firingpinIn->Set(false);
	if (t.Get() > 5.5f && t.Get() < 5.6f)
		Robot::elevation->firingpinOut->Set(true);

	if (t.Get() > 5.6f && t.Get() < 7.5f) {
		printf("up in this bitch\n");
		Robot::elevation->shooterSpd->Set(0);
		Robot::elevation->elevationSetPoint = 0;
		if (!Robot::elevation->atSet)
			Robot::elevation->gotoSetPoint();
	}
//	if (t.Get() > 7.6f && t.Get() < 10.0f) {
//		printf("up in this butch\n");
//		printf("enq %d ", Robot::driver->en1->Get());
//		if (Robot::driver->en1->Get() > -520) {
//			//			Robot::driver->spd1->Set(.7f);
//			//			Robot::driver->spd2->Set(.7f);
//		} else {
//
//		}
//	}
	
	//FORWARDS
	if (t.Get() > 7.6f && t.Get() < 10.0f) {
		Robot::driver->en1->Reset();
		Robot::driver->en2->Reset();
		while (Robot::driver->en1->Get() > -520 || Robot::driver->en2->Get()
				> -520) {
			if (Robot::driver->en1->Get() > -520)
				Robot::driver->spd1->Set(-.8f);
			if (Robot::driver->en2->Get() > -520)
				Robot::driver->spd2->Set(.8f);
			//Wait(10);
			printf("d1  %d    d2  %d  Forwards\n", Robot::driver->en1->Get(),
					Robot::driver->en2->Get());
		}
		Robot::driver->spd1->Set(0);
		Robot::driver->spd2->Set(0);
	}
	
	//BACKWARDS
	if (t.Get() > 10.1 && t.Get() < 12.5f) {
		Robot::driver->en1->Reset();
		Robot::driver->en2->Reset();
		while (Robot::driver->en1->Get() < 520 || Robot::driver->en2->Get()
				< 520) {
			if (Robot::driver->en1->Get() < 520)
				Robot::driver->spd1->Set(.8f);
			if (Robot::driver->en2->Get() < 520)
				Robot::driver->spd2->Set(-.8f);
			//Wait(10);
			printf("d1  %d    d2  %d  Backwards\n", Robot::driver->en1->Get(),
					Robot::driver->en2->Get());
		}
		Robot::driver->spd1->Set(0);
		Robot::driver->spd2->Set(0);
	}
	
	//TURN
	if (t.Get() > 12.6 && t.Get() < 15.0f) {
		Robot::driver->en1->Reset();
		Robot::driver->en2->Reset();
		while (Robot::driver->en1->Get() > -156 || Robot::driver->en2->Get() < 156) {
			if (Robot::driver->en1->Get() > -156)
				Robot::driver->spd1->Set(-.8f);
			if (Robot::driver->en2->Get() < 156)
				Robot::driver->spd2->Set(-.8f);
			//Wait(10);
			printf("d1  %d    d2  %d  Turn\n", Robot::driver->en1->Get(),
					Robot::driver->en2->Get());
		}
		Robot::driver->spd1->Set(0);
		Robot::driver->spd2->Set(0);
	}
	
	//FORWARDS
	if (t.Get() > 15.1f && t.Get() < 17.5f) {
		Robot::driver->en1->Reset();
		Robot::driver->en2->Reset();
		while (Robot::driver->en1->Get() > -520 || Robot::driver->en2->Get()
				> -520) {
			if (Robot::driver->en1->Get() > -520)
				Robot::driver->spd1->Set(-.8f);
			if (Robot::driver->en2->Get() > -520)
				Robot::driver->spd2->Set(.8f);
			//Wait(10);
			printf("d1  %d    d2  %d  Forwards\n", Robot::driver->en1->Get(),
					Robot::driver->en2->Get());
		}
		Robot::driver->spd1->Set(0);
		Robot::driver->spd2->Set(0);
	}

	//TURN
	if (t.Get() > 17.6 && t.Get() < 20.0f) {
		Robot::driver->en1->Reset();
		Robot::driver->en2->Reset();
		while (Robot::driver->en1->Get() > -156 || Robot::driver->en2->Get()
				< 156) {
			if (Robot::driver->en1->Get() > -156)
				Robot::driver->spd1->Set(-.8f);
			if (Robot::driver->en2->Get() < 156)
				Robot::driver->spd2->Set(-.8f);
			//Wait(10);
			printf("d1  %d    d2  %d  Turn\n", Robot::driver->en1->Get(),
					Robot::driver->en2->Get());
		}
		Robot::driver->spd1->Set(0);
		Robot::driver->spd2->Set(0);
	}

	//FORWARDS
	if (t.Get() > 20.1f && t.Get() < 22.5f) {
		Robot::driver->en1->Reset();
		Robot::driver->en2->Reset();
		while (Robot::driver->en1->Get() > -520 || Robot::driver->en2->Get()
				> -520) {
			if (Robot::driver->en1->Get() > -520)
				Robot::driver->spd1->Set(-.8f);
			if (Robot::driver->en2->Get() > -520)
				Robot::driver->spd2->Set(.8f);
			//Wait(10);
			printf("d1  %d    d2  %d  Forwards\n", Robot::driver->en1->Get(),
					Robot::driver->en2->Get());
		}
		Robot::driver->spd1->Set(0);
		Robot::driver->spd2->Set(0);
	}
	
	
	if (t.Get() > 22.6f) {
		printf(" Done\n");
		Robot::driver->spd1->Set(0);
		Robot::driver->spd2->Set(0);
	}
}
// Make this return true when this Command no longer needs to run execute()
bool AutonomousCommand::IsFinished() {
	return false;
}
// Called once after isFinished returns true
void AutonomousCommand::End() {
	Robot::driver->spd1->Set(0);
	Robot::driver->spd2->Set(0);
}
// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutonomousCommand::Interrupted() {
	Robot::driver->spd1->Set(0);
	Robot::driver->spd2->Set(0);
}
