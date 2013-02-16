#include "Robot.h"

Elevation* Robot::elevation = 0;
gate* Robot::gate = 0;
OI* Robot::oi = 0;
driver* Robot::driver = 0;
frisbeeHandler* Robot::frisbeeHandler = 0;
climber* Robot::climber = 0;
Chute* Robot::chute =0;

void Robot::RobotInit() {
	RobotMap::init();

	driver = new ::driver();
	elevation = new Elevation();
	frisbeeHandler = new ::frisbeeHandler();
	climber = new ::climber();
	chute = new ::Chute();

	oi = new OI();
	lw = LiveWindow::GetInstance();
	lw->AddSensor("Elevation","OpticalShoot",Robot::elevation->OpticalShoot);
	autonomousCommand = new AutonomousCommand();

	elevation->qenc->Reset();
	elevation->qenc->Start();
}

void Robot::AutonomousInit() {
	if (autonomousCommand != NULL)
		autonomousCommand->Start();
}

void Robot::AutonomousPeriodic() {
	Scheduler::GetInstance()->Run();
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
	printf("%f\n", 60.0f/(elevation->OpticalShoot->GetPeriod()));
}
void Robot::TestPeriodic() {
	lw->Run();
}
START_ROBOT_CLASS(Robot)
;
