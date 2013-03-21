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
			while(true);
			printf("JOY2 TOP\n");
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
//			//UP MID
//						//FORWARDS
//						if (t.Get() > 1.25f && t.Get() < 4.0f) {//drive forwards, open gates
//
//							RobotMap::gatesol1->Set(true);//gates
//							RobotMap::gatesol2->Set(false);
//							while (Robot::driver->en1->Get() > -520
//									|| Robot::driver->en2->Get() > -520) {
//								Robot::frisbee->AutoState();
//								/////////////////////////////
//
//
//								if (tConv.Get() > 1.25f || firstGate) {//timer has completed, run conveyor
//									if (!RobotMap::forkLiftSW->Get()) {//the switch was triggered, stop conveyor and reset timer
//										firstGate = false;
//										Robot::conveyor->conv->Set(Relay::kOff);
//										tConv.Reset();
//										if (Robot::driver->en1->Get() > -520)
//											Robot::driver->spd1->Set(-.0f);
//										if (Robot::driver->en2->Get() > -520)
//											Robot::driver->spd2->Set(.0f);
//									} else {//switch not triggered, timer completed, run conveyor
//										if (Robot::driver->en1->Get() > -520)
//											Robot::driver->spd1->Set(-.7f);
//										if (Robot::driver->en2->Get() > -520)
//											Robot::driver->spd2->Set(.7f);
//										Robot::conveyor->Move();
//									}
//								}
//
//								//////////////////////////////////
//								//Wait(10);
//								printf("d1  %d    d2  %d  Forwards\n",
//										Robot::driver->en1->Get(),
//										Robot::driver->en2->Get());
//							}
//							//backin it up
//						}
//						if (t.Get() > 4.1f && t.Get() < 7.0f) {//drive forwards, open gates
//
//							RobotMap::gatesol1->Set(true);//gates
//							RobotMap::gatesol2->Set(false);
//							printf("yerp %d %d %f %d\n",Robot::driver->en1->Get(),Robot::driver->en2->Get(),t.Get(),t.Get()<8.0f);
//							while ((Robot::driver->en1->Get() < -450
//									|| Robot::driver->en2->Get() < -450) && t.Get() < 8.0f) {
//								Robot::frisbee->AutoState();
//								/////////////////////////////
//							
//								printf("lolo %d %d %f %d\n",Robot::driver->en1->Get(),Robot::driver->en2->Get(),t.Get(),t.Get()<8.0f);
//
//								if (tConv.Get() > 1.25f || firstGate) {//timer has completed, run conveyor
//									if (!RobotMap::forkLiftSW->Get()) {//the switch was triggered, stop conveyor and reset timer
//										firstGate = false;
//										Robot::conveyor->conv->Set(Relay::kOff);
//										tConv.Reset();
//					
//											Robot::driver->spd1->Set(-.0f);
//				
//											Robot::driver->spd2->Set(.0f);
//									} else {//switch not triggered, timer completed, run conveyor
//										if (Robot::driver->en1->Get() < -450)
//											Robot::driver->spd1->Set(.7f);
//										if (Robot::driver->en2->Get() < -450)
//											Robot::driver->spd2->Set(-.7f);
//										Robot::conveyor->Move();
//									}
//								}
//
//								//////////////////////////////////
//								//Wait(10);
//								printf("d1  %d    d2  %d  backwards\n",
//										Robot::driver->en1->Get(),
//										Robot::driver->en2->Get());
//							}
//
//							RobotMap::gatesol1->Set(false);//gates
//							RobotMap::gatesol2->Set(true);
//
//							Robot::driver->spd1->Set(0);
//							Robot::driver->spd2->Set(0);
//
//							printf("JOY2 MID\n");
//							printf("Side of pyramid auto\n");
//						}
//						if (t.Get() > 8.0f) {
//							Robot::conveyor->conv->Set(Relay::kOff);
//							RobotMap::frisbeesol1->Set(false);
//							RobotMap::frisbeesol2->Set(true);
//							//UP UP
//							//* Sit here and shoot ***********************************
//							if (t.Get() < 10.0f) {
//								Robot::elevation->recoil();
//								Robot::elevation->ShootLoop();
//								Robot::elevation->elevationSetPoint = 3400;
//								if (!Robot::elevation->atSet)
//									Robot::elevation->gotoSetPoint();
//							}
//								if (!Robot::elevation->atSet)
//									Robot::elevation->gotoSetPoint();
//							if (t.Get() > 11.0f && t.Get() < 11.1f)
//								Robot::elevation->firingpinIn->Set(true);
//							if (t.Get() > 11.0f && t.Get() < 11.1f)
//								Robot::elevation->firingpinOut->Set(false);
//							if (t.Get() > 11.5f && t.Get() < 11.6f)
//								Robot::elevation->firingpinIn->Set(false);
//							if (t.Get() > 11.5f && t.Get() < 11.6f)
//								Robot::elevation->firingpinOut->Set(true);
//
//							if (t.Get() > 12.0f && t.Get() < 12.1f)
//								Robot::elevation->firingpinIn->Set(true);
//							if (t.Get() > 12.0f && t.Get() < 12.1f)
//								Robot::elevation->firingpinOut->Set(false);
//							if (t.Get() > 12.5f && t.Get() < 12.6f)
//								Robot::elevation->firingpinIn->Set(false);
//							if (t.Get() > 12.5f && t.Get() < 12.6f)
//								Robot::elevation->firingpinOut->Set(true);
//
//							if (t.Get() > 13.0f && t.Get() < 13.1f)
//								Robot::elevation->firingpinIn->Set(true);
//							if (t.Get() > 13.0f && t.Get() < 13.1f)
//								Robot::elevation->firingpinOut->Set(false);
//							if (t.Get() > 13.5f && t.Get() < 13.6f)
//								Robot::elevation->firingpinIn->Set(false);
//							if (t.Get() > 13.5f && t.Get() < 13.6f)
//								Robot::elevation->firingpinOut->Set(true);
//
//							if (t.Get() > 14.0f && t.Get() < 14.1f)
//								Robot::elevation->firingpinIn->Set(true);
//							if (t.Get() > 14.0f && t.Get() < 14.1f)
//								Robot::elevation->firingpinOut->Set(false);
//							if (t.Get() > 14.5f && t.Get() < 14.6f)
//								Robot::elevation->firingpinIn->Set(false);
//							if (t.Get() > 14.5f && t.Get() < 14.6f)
//								Robot::elevation->firingpinOut->Set(true);
//
//
//
//						}
//					
		} else if (Robot::oi->getjoy2()->GetZ() > -.9
				&& Robot::oi->getjoy2()->GetZ() < .9) { //DOWN MID
			printf("JOY2 MID\n");
		} else {//DOWN DOWN
			printf("JOY2 DOWN\n");
			
		}
	}

	//	printf("TIME: %f   ",t.Get());
	//	printf("JOY1  %f      JOY2  %f\n",Robot::oi->getjoy1()->GetZ(), Robot::oi->getjoy2()->GetZ());
	//	//	Robot::elevation->pidCalc(6000.0f);
	//		if (t.Get() < 2.0f) {
	//			Robot::elevation->recoil();
	//			Robot::elevation->ShootLoop();
	//			Robot::elevation->elevationSetPoint = 3400;
	//			if (!Robot::elevation->atSet)
	//				Robot::elevation->gotoSetPoint();
	//		}
	//		if (t.Get() > 2.0f && t.Get() < 2.1f)
	//			Robot::elevation->firingpinIn->Set(true);
	//		if (t.Get() > 2.0f && t.Get() < 2.1f)
	//			Robot::elevation->firingpinOut->Set(false);
	//		if (t.Get() > 2.5f && t.Get() < 2.6f)
	//			Robot::elevation->firingpinIn->Set(false);
	//		if (t.Get() > 2.5f && t.Get() < 2.6f)
	//			Robot::elevation->firingpinOut->Set(true);
	//	
	//		if (t.Get() > 3.0f && t.Get() < 3.1f)
	//			Robot::elevation->firingpinIn->Set(true);
	//		if (t.Get() > 3.0f && t.Get() < 3.1f)
	//			Robot::elevation->firingpinOut->Set(false);
	//		if (t.Get() > 3.5f && t.Get() < 3.6f)
	//			Robot::elevation->firingpinIn->Set(false);
	//		if (t.Get() > 3.5f && t.Get() < 3.6f)
	//			Robot::elevation->firingpinOut->Set(true);
	//	
	//		if (t.Get() > 4.0f && t.Get() < 4.1f)
	//			Robot::elevation->firingpinIn->Set(true);
	//		if (t.Get() > 4.0f && t.Get() < 4.1f)
	//			Robot::elevation->firingpinOut->Set(false);
	//		if (t.Get() > 4.5f && t.Get() < 4.6f)
	//			Robot::elevation->firingpinIn->Set(false);
	//		if (t.Get() > 4.5f && t.Get() < 4.6f)
	//			Robot::elevation->firingpinOut->Set(true);
	//	
	//		if (t.Get() > 5.0f && t.Get() < 5.1f)
	//			Robot::elevation->firingpinIn->Set(true);
	//		if (t.Get() > 5.0f && t.Get() < 5.1f)
	//			Robot::elevation->firingpinOut->Set(false);
	//		if (t.Get() > 5.5f && t.Get() < 5.6f)
	//			Robot::elevation->firingpinIn->Set(false);
	//		if (t.Get() > 5.5f && t.Get() < 5.6f)
	//			Robot::elevation->firingpinOut->Set(true);
	//	
	//	if (t.Get() > 5.6f && t.Get() < 7.5f) {
	//		printf("up in this bitch\n");
	//		Robot::elevation->shooterSpd->Set(0);
	//		Robot::elevation->elevationSetPoint = 0;
	//		if (!Robot::elevation->atSet)
	//			Robot::elevation->gotoSetPoint();
	//	}
	////	if (t.Get() > 7.6f && t.Get() < 10.0f) {
	////		printf("up in this butch\n");
	////		printf("enq %d ", Robot::driver->en1->Get());
	////		if (Robot::driver->en1->Get() > -520) {
	////			//			Robot::driver->spd1->Set(.7f);
	////			//			Robot::driver->spd2->Set(.7f);
	////		} else {
	////
	////		}
	////	}
	//	
	//		//FORWARDS
	//		if (t.Get() > 7.6f && t.Get() < 10.0f) {
	//			Robot::driver->en1->Reset();
	//			Robot::driver->en2->Reset();
	//			while (Robot::driver->en1->Get() > -520 || Robot::driver->en2->Get()
	//					> -520) {
	//				if (Robot::driver->en1->Get() > -520)
	//					Robot::driver->spd1->Set(-.8f);
	//				if (Robot::driver->en2->Get() > -520)
	//					Robot::driver->spd2->Set(.8f);
	//				//Wait(10);
	//				printf("d1  %d    d2  %d  Forwards\n", Robot::driver->en1->Get(),
	//						Robot::driver->en2->Get());
	//			}
	//			Robot::driver->spd1->Set(0);
	//			Robot::driver->spd2->Set(0);
	//		}
	//	
	//	//BACKWARDS
	//	if (t.Get() > 10.1 && t.Get() < 12.5f) {
	//		Robot::driver->en1->Reset();
	//		Robot::driver->en2->Reset();
	//		while (Robot::driver->en1->Get() < 520 || Robot::driver->en2->Get()
	//				< 520) {
	//			if (Robot::driver->en1->Get() < 520)
	//				Robot::driver->spd1->Set(.8f);
	//			if (Robot::driver->en2->Get() < 520)
	//				Robot::driver->spd2->Set(-.8f);
	//			//Wait(10);
	//			printf("d1  %d    d2  %d  Backwards\n", Robot::driver->en1->Get(),
	//					Robot::driver->en2->Get());
	//		}
	//		Robot::driver->spd1->Set(0);
	//		Robot::driver->spd2->Set(0);
	//	}
	//	
	//	//TURN
	//	if (t.Get() > 12.6 && t.Get() < 15.0f) {
	//		Robot::driver->en1->Reset();
	//		Robot::driver->en2->Reset();
	//		while (Robot::driver->en1->Get() > -156 || Robot::driver->en2->Get() < 156) {
	//			if (Robot::driver->en1->Get() > -156)
	//				Robot::driver->spd1->Set(-.8f);
	//			if (Robot::driver->en2->Get() < 156)
	//				Robot::driver->spd2->Set(-.8f);
	//			//Wait(10);
	//			printf("d1  %d    d2  %d  Turn\n", Robot::driver->en1->Get(),
	//					Robot::driver->en2->Get());
	//		}
	//		Robot::driver->spd1->Set(0);
	//		Robot::driver->spd2->Set(0);
	//	}
	//	
	//	//FORWARDS
	//	if (t.Get() > 15.1f && t.Get() < 17.5f) {
	//		Robot::driver->en1->Reset();
	//		Robot::driver->en2->Reset();
	//		while (Robot::driver->en1->Get() > -520 || Robot::driver->en2->Get()
	//				> -520) {
	//			if (Robot::driver->en1->Get() > -520)
	//				Robot::driver->spd1->Set(-.8f);
	//			if (Robot::driver->en2->Get() > -520)
	//				Robot::driver->spd2->Set(.8f);
	//			//Wait(10);
	//			printf("d1  %d    d2  %d  Forwards\n", Robot::driver->en1->Get(),
	//					Robot::driver->en2->Get());
	//		}
	//		Robot::driver->spd1->Set(0);
	//		Robot::driver->spd2->Set(0);
	//	}
	//
	//	//TURN
	//	if (t.Get() > 17.6 && t.Get() < 20.0f) {
	//		Robot::driver->en1->Reset();
	//		Robot::driver->en2->Reset();
	//		while (Robot::driver->en1->Get() > -156 || Robot::driver->en2->Get()
	//				< 156) {
	//			if (Robot::driver->en1->Get() > -156)
	//				Robot::driver->spd1->Set(-.8f);
	//			if (Robot::driver->en2->Get() < 156)
	//				Robot::driver->spd2->Set(-.8f);
	//			//Wait(10);
	//			printf("d1  %d    d2  %d  Turn\n", Robot::driver->en1->Get(),
	//					Robot::driver->en2->Get());
	//		}
	//		Robot::driver->spd1->Set(0);
	//		Robot::driver->spd2->Set(0);
	//	}
	//
	//	//FORWARDS
	//	if (t.Get() > 20.1f && t.Get() < 22.5f) {
	//		Robot::driver->en1->Reset();
	//		Robot::driver->en2->Reset();
	//		while (Robot::driver->en1->Get() > -520 || Robot::driver->en2->Get()
	//				> -520) {
	//			if (Robot::driver->en1->Get() > -520)
	//				Robot::driver->spd1->Set(-.8f);
	//			if (Robot::driver->en2->Get() > -520)
	//				Robot::driver->spd2->Set(.8f);
	//			//Wait(10);
	//			printf("d1  %d    d2  %d  Forwards\n", Robot::driver->en1->Get(),
	//					Robot::driver->en2->Get());
	//		}
	//		Robot::driver->spd1->Set(0);
	//		Robot::driver->spd2->Set(0);
	//	}
	//	
	//	
	//	if (t.Get() > 22.6f) {
	//		printf(" Done\n");
	//		Robot::driver->spd1->Set(0);
	//		Robot::driver->spd2->Set(0);
	//	}
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
