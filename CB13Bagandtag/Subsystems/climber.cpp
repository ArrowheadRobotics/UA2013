#include "Climber.h"
#include "../Robotmap.h"
#include "../Robot.h"
Climber::Climber() : Subsystem("Climber") {
	sol1 = RobotMap::climbersol1;
	sol2 = RobotMap::climbersol2;
	spd1 = RobotMap::climberspd1;
	toggle1 = true;
}

void Climber::InitDefaultCommand() {
}

void Climber::toggle() {
	try {
		if (toggle1) {
			sol1->Set(false);
			sol2->Set(true);
		} else {
			sol1->Set(true);
			sol2->Set(false);
		}
		toggle1 = !toggle1;
	} catch (...) {
		printf("Alex is going to use some tutorials on the youtubes\n");
	}
}

void Climber::move(float spd) {
	spd1->Set(spd);
}

void Climber::stop() {
	spd1->Set(0);
}
