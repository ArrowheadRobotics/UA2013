#include "highRetract.h"
#include "../robot.h"
highRetract::highRetract() {
	Requires(Robot::chute);
}

void highRetract::Initialize() {
	Robot::chute->highRetract();
}

void highRetract::Execute() {
	
}

bool highRetract::IsFinished() {
	return false;
}

void highRetract::End() {
	
}

void highRetract::Interrupted() {
}
