#include "lowExtend.h"
#include "../robot.h"
lowExtend::lowExtend() {
	//*Requires(Robot::chute);
}

void lowExtend::Initialize() {
	Robot::chute->lowExtend();
}

void lowExtend::Execute() {
	
}

bool lowExtend::IsFinished() {
	return false;
}

void lowExtend::End() {
	
}

void lowExtend::Interrupted() {
}
