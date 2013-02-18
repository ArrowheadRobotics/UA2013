#include "ClimberMove.h"
#include "../robot.h"
ClimberMove::ClimberMove() {
	 Requires(Robot::climber);
}

void ClimberMove::Initialize() {
	
}

void ClimberMove::Execute() {
	Robot::climber->move(0.2f);
}

bool ClimberMove::IsFinished() {
	return false;
}

void ClimberMove::End() {
	
}

void ClimberMove::Interrupted() {
}
