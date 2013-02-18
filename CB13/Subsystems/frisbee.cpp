#include "Frisbee.h"
#include "../Robotmap.h"
#include "../Robot.h"
#include "../Commands/ForkLiftDefault.h"

Frisbee::Frisbee() :
	Subsystem("Frisbee") {
	sol1 = RobotMap::frisbeesol1;
	sol2 = RobotMap::frisbeesol2;
	t = new Timer();
	toggleState = true;
	isNormal = true;
}

void Frisbee::InitDefaultCommand() {
	SetDefaultCommand(new ForkLiftDefault);

}

void Frisbee::toggle() {
	if (toggleState) {
		sol1->Set(false);
		sol2->Set(true);

	} else {
		sol1->Set(true);
		sol2->Set(false);

	}
	toggleState = !toggleState;
}

void Frisbee::AutoState() {
//	printf("Timer: %f", t->Get());
	if (!RobotMap::forkLiftSW->Get()) {
		sol1->Set(true);
		sol2->Set(false);

		t->Start();
		isNormal =false;
	} else {

		if(isNormal){
			sol1->Set(false);
			sol2->Set(true);
		}
		else if (t->Get() < 1.0f)
			;
		else {
			sol1->Set(false);
			sol2->Set(true);
			t->Reset();
			t->Stop();
			isNormal=true;
		}

	}

}

