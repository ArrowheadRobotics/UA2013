#include "FrisbeeToggle.h"
#include "../robot.h"
FrisbeeToggle::FrisbeeToggle() {
	 //Requires(Robot::frisbee);
	SetTimeout(1.0f);
}

void FrisbeeToggle::Initialize() {
	Robot::frisbee->toggle();
}

void FrisbeeToggle::Execute() {
	
}

bool FrisbeeToggle::IsFinished() {
	return IsTimedOut();
}

void FrisbeeToggle::End() {
	Robot::frisbee->toggle();
}

void FrisbeeToggle::Interrupted() {
	Robot::frisbee->toggle();
}
