#include "Robot.h"

Elevation* Robot::elevation = 0;
gate* Robot::gate = 0;
OI* Robot::oi = 0;
driver* Robot::driver = 0;

void Robot::RobotInit() {
	RobotMap::init();

	driver = new ::driver();
	elevation = new Elevation();

	oi = new OI();
	lw = LiveWindow::GetInstance();

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
	printf("%d\n", elevation->bottomLimit->Get());
}
void Robot::TestPeriodic() {
	lw->Run();
}
START_ROBOT_CLASS(Robot)
;
