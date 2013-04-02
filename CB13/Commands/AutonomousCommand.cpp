#include "AutonomousCommand.h"
#include "ForkLiftDefault.h"
#include "ConveyorUp.h"

#include "fire.h"
Timer t;
Timer tConv;
bool firstGate;
AutonomousCommand::AutonomousCommand() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	fk = new ForkLiftDefault();
	cu = new ConveyorUp();

}
// Called just before this Command runs the first time
void AutonomousCommand::Initialize() {
	//Robot::elevation->InitPID(6000.0f);
	Robot::chute->resetState();
	//	fk->Start();
	//	cu->Start();
	t.Start();
	t.Reset();
	tConv.Start();
	tConv.Reset();
	firstGate = true;

}
// Called repeatedly when this Command is scheduled to run
void AutonomousCommand::Execute() {
	/*
	 * Auto Mode - uses the throttle positions on the joystics.
	 * Slot 2 = Joy 1
	 * Slot 1 = Joy 2
	 * Top = throttle is perpendicular to the joystic base
	 */
	if (Robot::oi->getjoy1()->GetZ() < -.9) {
		printf("JOY1 TOP     ");
		if (Robot::oi->getjoy2()->GetZ() < -.9) {//UP UP
			//* Sit here and shoot ***********************************
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

			if (t.Get() > 7.0f) {
				Robot::elevation->recoil();
				Robot::elevation->Down(0.7f);//tune
				while (Robot::elevation->qenc->Get() > 100 && t.Get() < 14.9f
						&& RobotMap::bottomLimit->Get() == 0)
					;
				Robot::elevation->Stop();
			}
			printf("JOY2 TOP\n");
			printf("Sit and shoot auto\n");

		} else if (Robot::oi->getjoy2()->GetZ() > -.9
				&& Robot::oi->getjoy2()->GetZ() < .9) {

		} else {
			printf("JOY2 DOWN\n");//UP DOWN
		}
	} else if (Robot::oi->getjoy1()->GetZ() > -.9
			&& Robot::oi->getjoy1()->GetZ() < .9) {
		printf("JOY1 MID     ");
		if (Robot::oi->getjoy2()->GetZ() < -.9) {//MID UP
			//while(true);
			printf("JOY2 TOP WHILE WHILE\n");
		} else if (Robot::oi->getjoy2()->GetZ() > -.9
				&& Robot::oi->getjoy2()->GetZ() < .9) {//MID MID
			printf("JOY2 MID\n");
		} else {//MID DOWN
			printf("JOY2 DOWN\n");
		}
	} else {
		printf("JOY1 DOWN    ");
		if (Robot::oi->getjoy2()->GetZ() < -.9) {//DOWN UP
			printf("JOY2 TOP\n");

		} else if (Robot::oi->getjoy2()->GetZ() > -.9
				&& Robot::oi->getjoy2()->GetZ() < .9) { //DOWN MID
			printf("JOY2 MID\n");
		} else {//DOWN DOWN
			Robot::driver->gyro1->Reset();
			Robot::driver->en1->Reset();
		//	Robot::chute->resetState();
		//	Robot::elevation->recoil();
			printf("JOY2 DOWN\n");
//			while(t.Get()<1.0f);
//			while (Robot::driver->en1->GetDistance() < 24.0f && t.Get() < 14.9f) {
//				Robot::driver->spd1->Set(.3f);//move backwards
//				Robot::driver->spd2->Set(-.3f);
//				printf("Moving backwards\n");
//
//			}
//			Robot::driver->spd1->Set(0.0f);//move backwards
//			Robot::driver->spd2->Set(0.0F);
//
//			Robot::driver->gyro1->Reset();
//			Robot::driver->en1->Reset();
//			Robot::driver->spd1->Set(0.0f);//stop
//			Robot::driver->spd2->Set(0.0f);
//
//			while (Robot::driver->en1->GetDistance() > -84 && t.Get() < 14.9f) {
//				Robot::driver->spd1->Set(-.3f);//open gates, run conveyor, move forward
//				Robot::driver->spd2->Set(.3f);
//				RobotMap::gatesol1->Set(true);//gates
//				RobotMap::gatesol2->Set(false);
//				Robot::frisbee->AutoState();
//				Robot::conveyor->Move();
//			}
//			Robot::driver->gyro1->Reset();
//			Robot::driver->en1->Reset();
//			RobotMap::gatesol1->Set(false);//gates
//			RobotMap::gatesol2->Set(true);
//
//			Robot::driver->spd1->Set(.3f);//open gates, run conveyor, move backwards
//			Robot::driver->spd2->Set(-.3f);
//
//			while (Robot::driver->en1->GetDistance() < 47.0 && t.Get() < 14.9f) {
//				Robot::frisbee->AutoState();
//				Robot::conveyor->Move();
//			}
//
//			Robot::driver->spd1->Set(0.0f);//open gates, run conveyor, move backwards
//			Robot::driver->spd2->Set(0.0f);
//
//			Robot::conveyor->conv->Set(Relay::kOff);
//			Robot::elevation->atSet = false;
			
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

					if (t.Get() > 7.0f) {
						Robot::elevation->recoil();
						Robot::elevation->Down(0.7f);//tune
						while (Robot::elevation->qenc->Get() > 100 && t.Get() < 14.9f
								&& RobotMap::bottomLimit->Get() == 0)
							;
						Robot::elevation->Stop();
			}
		}
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
