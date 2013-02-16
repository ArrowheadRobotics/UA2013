#include "gate.h"
#include "../Robotmap.h"
#include "../Robot.h"
gate::gate() : Subsystem("gate") {
	sol1 = RobotMap::gatesol1;
	sol2 = RobotMap::gatesol2;
}
    
void gate::InitDefaultCommand() {

}

void gate::toggle(){
	if(Robot::gate->sol1->Get()==true){
		RobotMap::gatesol1->Set(false);
		RobotMap::gatesol2->Set(true);
	}else{
		RobotMap::gatesol1->Set(true);
		RobotMap::gatesol2->Set(false);
	}
}
