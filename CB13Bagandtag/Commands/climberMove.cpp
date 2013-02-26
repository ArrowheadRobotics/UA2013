#include "ClimberMove.h"
#include "../robot.h"
ClimberMove::ClimberMove() {
	 Requires(Robot::climber);
}

<<<<<<< HEAD:CB13/Commands/climberMove.cpp
void ClimberMove::Initialize() {
	
=======
void climberMove::Initialize() {
	Robot::climber->move(1.0f);
	SetTimeout(0.5f);
>>>>>>> hey:CB13Bagandtag/Commands/climberMove.cpp
}

void ClimberMove::Execute() {
	Robot::climber->move(0.2f);
}

<<<<<<< HEAD:CB13/Commands/climberMove.cpp
bool ClimberMove::IsFinished() {
	return false;
}

void ClimberMove::End() {
	
}

void ClimberMove::Interrupted() {
=======
bool climberMove::IsFinished() {
	return IsTimedOut();
}

void climberMove::End() {
	Robot::climber->move(0.0f);
}

void climberMove::Interrupted() {
	Robot::climber->move(0.0f);
>>>>>>> hey:CB13Bagandtag/Commands/climberMove.cpp
}
