#include "Robot.h"

void Cyberhawk::OperatorControl() {
	while(IsEnabled()) {
		drive[DR_LEFT]->Set(sticks[LEFT_JOY]->GetY());
		drive[DR_RIGHT]->Set(sticks[RIGHT_JOY]->GetY());
	}
}
