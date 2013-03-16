#include "ClimberMove.h"
#include "../robot.h"
ClimberMove::ClimberMove() {
	 Requires(Robot::climber);
	 SetTimeout(.1f);
}

void ClimberMove::Initialize() {
	
}

void ClimberMove::Execute() {
	Robot::climber->move(1.0f);
}

bool ClimberMove::IsFinished() {
	return IsTimedOut();
}

void ClimberMove::End() {
	Robot::climber->move(0.0f);
}
	
void ClimberMove::Interrupted() {
	Robot::climber->move(0.0f);
}
