#include "Robot.h"

void Cyberhawk::OperatorControl() {
	setRobotState(RS_DEFAULT);
	JoystickButton defenseToggle(sticks[JS_ACTION], 4); // todo figure out button numbers on gamepad
	
	while(IsEnabled()) {
		Drive(sticks[JS_LEFT]->GetY(), sticks[JS_RIGHT]->GetY());
		if(true){}
	}
}
