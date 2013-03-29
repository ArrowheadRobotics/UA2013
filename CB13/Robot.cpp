#include "Robot.h"
#include "OI.h"
#include "String.h"
Elevation* Robot::elevation = 0;
gate* Robot::gate = 0;
OI* Robot::oi = 0;
driver* Robot::driver = 0;
Climber* Robot::climber = 0;
Chute* Robot::chute = 0;
Conveyor* Robot::conveyor = 0;
Frisbee* Robot::frisbee = 0;
char buffer[128];
void Robot::RobotInit() {
	RobotMap::init();

	matchTimerUpdateCounter = 0;
	conveyor = new ::Conveyor();
	driver = new ::driver();
	elevation = new ::Elevation();
	climber = new ::Climber();
	chute = new ::Chute();
	gate = new ::gate();
	frisbee = new ::Frisbee();
	oi = new OI();
#ifdef USE_NETWORK
	lw = LiveWindow::GetInstance();
	lw->AddSensor("Elevation", "OpticalShoot", Robot::elevation->OpticalShoot);
#endif
	autonomousCommand = new AutonomousCommand();
	elevation->qenc->Reset();
	elevation->qenc->Start();
	RobotMap::compressor->Start();
}

void Robot::AutonomousInit() {
	if (autonomousCommand != NULL)
		autonomousCommand->Start();
	Robot::elevation->atSet = false;
	RobotMap::driveren1->Start();
	RobotMap::driveren2->Start();
	RobotMap::driveren1->Reset();
	RobotMap::driveren2->Reset();
	Robot::driver->en1->SetDistancePerPulse((6*3.14)/250);

}

void Robot::AutonomousPeriodic() {
	Scheduler::GetInstance()->Run();
//	printf("en1: %d\n", driver->en1->Get());
//	//printf("Yeah: %f", Robot::oi->getgamepad()->GetRawAxis(3));
//	//		printf("    d2: %d\n", driver->en2->Get());
////	printf("Shoot: %f\n", 60.0f / elevation->OpticalShoot->GetPeriod());
//	printf("SEnq: %d\n", elevation->qenc->Get());
//	printf("Gyro: %f\n", driver->gyro1->GetAngle());
}

void Robot::TeleopInit() {
	// This makes sure that the autonomous stops running when
	// teleop starts running. If you want the autonomous to 
	// continue until interrupted by another command, remove
	// this line or comment it out.
	autonomousCommand->Cancel();
	Robot::oi->matchTimer->Reset();
	Robot::oi->matchTimer->Start();
	Robot::driver->en1->Reset();
	Robot::driver->en1->SetDistancePerPulse((6*3.14)/250);
	Robot::driver->en2->Reset();
	Robot::driver->gyro1->Reset();

}

void Robot::TeleopPeriodic() {
	if (autonomousCommand != NULL)
		Scheduler::GetInstance()->Run();
	printf("en1: %d\n", driver->en1->Get());
	//printf("Yeah: %f", Robot::oi->getgamepad()->GetRawAxis(3));
	//		printf("    d2: %d\n", driver->en2->Get());
//	printf("Shoot: %f\n", 60.0f / elevation->OpticalShoot->GetPeriod());
	printf("SEnq: %d dist: %f\n", elevation->qenc->Get(),elevation->qenc->GetDistance());
	printf("Gyro: %f\n", driver->gyro1->GetAngle());

	//printf("Dump: %f\n", RobotMap::conveyorRelay->Get());
	//printf("m: %d",matchTimerUpdateCounter);
#ifdef USE_NETWORK
	if (matchTimerUpdateCounter > 100) {
		snprintf(buffer, 128, "%g",120- Robot::oi->matchTimer->Get() );
		Robot::oi->server->PutString("timeremaining", buffer);
		matchTimerUpdateCounter = 0;
	}
	matchTimerUpdateCounter++;
#endif	
	//printf("JOY1  %f      JOY2  %f\n",Robot::oi->getjoy1()->GetZ(), Robot::oi->getjoy2()->GetZ());

}
void Robot::TestPeriodic() {
#ifdef USE_NETWORK
	lw->Run();
#endif
}
START_ROBOT_CLASS(Robot)
;
