#include "lowRetract.h"
#include "../robot.h"
lowRetract::lowRetract() {
	Requires(Robot::chute);
}

void lowRetract::Initialize() {
	Robot::chute->lowRetract();
}

void lowRetract::Execute() {
	
}

bool lowRetract::IsFinished() {
	return false;
}

void lowRetract::End() {
	
}

void lowRetract::Interrupted() {
}
