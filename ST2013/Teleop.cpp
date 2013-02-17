#include "Robot.h"

void Cyberhawk::OperatorControl() {
	setRobotState(RS_DEFAULT); // reset robot
	setRobotState(RS_DRIVING_DEF); // set to default state for teleop (driving defensive)
	
	bool *buttonBuffer = {false};
	enum kButtons {B_TOGDEFENSE};
	
	while(IsEnabled()) {
		Drive(sticks[JS_LEFT]->GetY(), sticks[JS_RIGHT]->GetY());
		
		buttonBuffer[B_TOGDEFENSE] = sticks[JS_GAMEPAD]->GetRawButton(3);
	}
}
