#include "gateToggle.h"
#include "../robot.h"
gateToggle::gateToggle() {
	//& Requires(Robot::gate);
}

void gateToggle::Initialize() {
	Robot::gate->toggle();
}

void gateToggle::Execute() {
	
}

bool gateToggle::IsFinished() {
	return false;
}

void gateToggle::End() {
	
}

void gateToggle::Interrupted() {
}
