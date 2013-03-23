#include "gateToggle.h"
#include "../robot.h"
gateToggle::gateToggle() {
	 Requires(Robot::gate);
}

void gateToggle::Initialize() {
	//Robot::gate->toggle();
	//SetTimeout(.5f);
}

void gateToggle::Execute() {
	printf("exe\n");
	RobotMap::gatesol1->Set(true);//gates
	RobotMap::gatesol2->Set(false);
}

bool gateToggle::IsFinished() {
	return false;
}

void gateToggle::End() {
	printf("end\n");
	RobotMap::gatesol1->Set(false);//gates
	RobotMap::gatesol2->Set(true);	
}

void gateToggle::Interrupted() {
	printf("int\n");
	RobotMap::gatesol1->Set(false);//gates
	RobotMap::gatesol2->Set(true);
}
