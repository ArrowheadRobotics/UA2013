#include "frisbeeToggle.h"
#include "../robot.h"
frisbeeToggle::frisbeeToggle() {
	 //Requires(Robot::frisbee);
}

void frisbeeToggle::Initialize() {
	Robot::gate->toggle();
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
