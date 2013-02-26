#include "ClimberRelease.h"
#include "../robot.h" 

ClimberRelease::ClimberRelease() {
	 Requires(Robot::climber);
}

void ClimberRelease::Initialize() {
	Robot::climber->move(-1.0f);
	SetTimeout(0.5f);
}

void ClimberRelease::Execute() {
	
}

bool ClimberRelease::IsFinished() {
	return IsTimedOut();
}

void ClimberRelease::End() {
	Robot::climber->move(0.0f);
}

void ClimberRelease::Interrupted() {
	Robot::climber->move(0.0f);
}
