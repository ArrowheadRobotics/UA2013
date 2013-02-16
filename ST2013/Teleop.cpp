#include "Robot.h"

void Cyberhawk::OperatorControl() {
	while(IsEnabled()) {
		Drive(sticks[JS_LEFT]->GetY(), sticks[JS_RIGHT]->GetY());
	}
}
