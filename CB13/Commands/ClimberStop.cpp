#include "ClimberStop.h"
#include "../robot.h"
ClimberStop::ClimberStop() {
	 Requires(Robot::climber);
}

void ClimberStop::Initialize() {
	
}

void ClimberStop::Execute() {
	Robot::climber->move(0.0f);
}

bool ClimberStop::IsFinished() {
	return false;
}

void ClimberStop::End() {
	
}

void ClimberStop::Interrupted() {
}
