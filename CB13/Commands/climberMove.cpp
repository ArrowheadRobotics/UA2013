#include "climberMove.h"
#include "../robot.h"
climberMove::climberMove() {
	//& Requires(Robot::climber);
}

void climberMove::Initialize() {
	Robot::climber->move(0.0f);
}

void climberMove::Execute() {
	
}

bool climberMove::IsFinished() {
	return false;
}

void climberMove::End() {
	
}

void climberMove::Interrupted() {
}
