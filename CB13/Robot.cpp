#include "Robot.h"

Elevation* Robot::elevation = 0;
gate* Robot::gate = 0;
OI* Robot::oi = 0;
driver* Robot::driver = 0;
Climber* Robot::climber = 0;
Chute* Robot::chute = 0;
Conveyor* Robot::conveyor = 0;
Frisbee* Robot::frisbee = 0;
void Robot::RobotInit() {
	RobotMap::init();

	conveyor = new ::Conveyor();
	driver = new ::driver();
	elevation = new ::Elevation();
	climber = new ::Climber();
	chute = new ::Chute();
	gate = new ::gate();
	frisbee = new ::Frisbee();
	oi = new OI();
	lw = LiveWindow::GetInstance();
	lw->AddSensor("Elevation", "OpticalShoot", Robot::elevation->OpticalShoot);
	autonomousCommand = new AutonomousCommand();

	elevation->qenc->Reset();
	elevation->qenc->Start();
	RobotMap::compressor->Start();
}

void Robot::AutonomousInit() {
	if (autonomousCommand != NULL)
		autonomousCommand->Start();
}

void Robot::AutonomousPeriodic() {
	Scheduler::GetInstance()->Run();
	Robot::elevation->fire();
	Robot::elevation->recoil();
}

void Robot::TeleopInit() {
	// This makes sure that the autonomous stops running when
	// teleop starts running. If you want the autonomous to 
	// continue until interrupted by another command, remove
	// this line or comment it out.
	autonomousCommand->Cancel();

}

void Robot::TeleopPeriodic() {
	if (autonomousCommand != NULL)
		Scheduler::GetInstance()->Run();
	printf("Shoot %f\n", elevation->shooterSpd->Get());

}
void Robot::TestPeriodic() {
	lw->Run();
}
START_ROBOT_CLASS(Robot)
;
