#include "climberToggle.h"
#include "../robot.h"
climberToggle::climberToggle() {
	Requires(Robot::driver);
}

void climberToggle::Initialize() {
	Robot::climber->toggle();
}

void climberToggle::Execute() {
	
}

bool climberToggle::IsFinished() {
	return false;
}

void climberToggle::End() {
	
}

void climberToggle::Interrupted() {
}
