#include "Robot.h"

void Cyberhawk::OperatorControl() {
	resetStates();
	bool defense = false;
	
	while(IsEnabled()) {
		Drive(sticks[JS_LEFT]->GetY(), sticks[JS_RIGHT]->GetY());
		
	}
}
