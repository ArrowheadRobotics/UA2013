#include "frisbeeToggle.h"
#include "../robot.h"
frisbeeToggle::frisbeeToggle() {
	Requires(Robot::driver);
}

void frisbeeToggle::Initialize() {
	Robot::frisbeeHandler->toggle();
}

void frisbeeToggle::Execute() {
	
}

bool frisbeeToggle::IsFinished() {
	return false;
}

void frisbeeToggle::End() {
	
}

void frisbeeToggle::Interrupted() {
}
