#include "gate.h"
#include "../Robotmap.h"
#include "../Robot.h"
gate::gate() : Subsystem("gate") {
	sol1 = RobotMap::gatesol1;
	sol2 = RobotMap::gatesol2;
	toggleState = true;
}
    
void gate::InitDefaultCommand() {

}

void gate::toggle(){
	if(toggleState){
		sol1->Set(false);
		sol2->Set(true);
		printf("gate toggle true\n");
		
	}else{
		sol1->Set(true);
		sol2->Set(false);
		printf("gate toggle false\n");
		
	}
	toggleState = !toggleState;
}
