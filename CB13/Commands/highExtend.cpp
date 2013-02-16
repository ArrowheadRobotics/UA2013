#include "highExtend.h"
#include "../robot.h"
highExtend::highExtend() {
	//*Requires(Robot::chute);
}

void highExtend::Initialize() {
	Robot::chute->highExtend();
}

void highExtend::Execute() {
	
}

bool highExtend::IsFinished() {
	return false;
}

void highExtend::End() {
	
}

void highExtend::Interrupted() {
}
