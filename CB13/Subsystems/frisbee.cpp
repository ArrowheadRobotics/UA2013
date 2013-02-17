#include "frisbee.h"
#include "../Robotmap.h"
#include "../Robot.h"
frisbee::frisbee() : Subsystem("frisbee") {
	sol1 = RobotMap::frisbeesol1;
	sol2 = RobotMap::frisbeesol2;
	toggleState = true;
}
    
void frisbee::InitDefaultCommand() {

}

void frisbee::toggle(){
	if(toggleState){
		sol1->Set(false);
		sol2->Set(true);
		
	}else{
		sol1->Set(true);
		sol2->Set(false);
		
	}
	toggleState = !toggleState;
}
