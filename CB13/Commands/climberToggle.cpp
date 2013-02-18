#include "ClimberToggle.h"
#include "../robot.h"
ClimberToggle::ClimberToggle() {
	Requires(Robot::climber);
}

void ClimberToggle::Initialize() {
	try {
		Robot::climber->toggle();
	} catch (...) {
		printf("Alex needs to buy a c++ book\n");
	}
}

void ClimberToggle::Execute() {

}

bool ClimberToggle::IsFinished() {
	return false;
}

void ClimberToggle::End() {

}

void ClimberToggle::Interrupted() {
}
