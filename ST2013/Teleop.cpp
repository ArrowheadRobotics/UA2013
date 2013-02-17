#include "Robot.h"

void* hDrive(void*);

void Cyberhawk::OperatorControl() {
	setRobotState(RS_DEFAULT); // reset robot
	setRobotState(RS_DRIVING_DEF); // set to default state for teleop (driving defensive)
	
	bool buttonBuffer[] = {false, false, false, false, false};  //holds current button values -- used so button presses only register once per press
	bool defense = true;  //if in defense mode
	enum kButtons {B_DEFENSE, B_SHOOTING, B_LOADING, B_SHOOT, B_GATE};  //buttons
	
	Thread driving(hDrive, true, (void*)this);  //driving thread -- function to run, run on init, parameters (passing robot object)
	
	while(IsEnabled()) {
		printf("%i %i %i %i %i\n", buttonBuffer[0], buttonBuffer[1], buttonBuffer[2], buttonBuffer[3], buttonBuffer[4]);
		if(dnoids[DSO_GATE].getValue() == false)
			spikes[SP_CONVEYOR]->Set(Relay::kOff);
		
		if(buttonBuffer[B_DEFENSE] == 0 && sticks[JS_LEFT]->GetRawButton(3) == 1) {  //if you just pressed the defensive button (3)
			if(getRobotState() == RS_DRIVING_DEF) {  //toggle defensive state
				setRobotState(RS_DRIVING_OFF);
				defense = false;
			} else if(getRobotState() == RS_DRIVING_OFF) {
				setRobotState(RS_DRIVING_DEF);
				defense = true;
			} else {
				setRobotState(RS_DRIVING_DEF);  //default
				defense = true;
			}
		}
		
		if(buttonBuffer[B_SHOOTING] == 0 && sticks[JS_LEFT]->GetRawButton(4) == 1) {  //shooting mode button just pressed
			if(getRobotState() == RS_SHOOTING)  //toggle shooting (remembers previous state using defense)
				setRobotState((defense)?RS_DRIVING_DEF:RS_DRIVING_OFF);
			else
				setRobotState(RS_SHOOTING);
		}
		
		if(buttonBuffer[B_SHOOT] == 0 && sticks[JS_RIGHT]->GetRawButton(1) == 1) {  //shooting button just pressed
			if(getRobotState() == RS_SHOOTING) {  //if your allowed to shoot
				if(canAdjustState[AS_FIRINGPIN]) {  //if your allowed to shoot (again)
					vics[VI_SHOOTER]->Set(.5f);  //power up shooting
					Wait(500);
					dnoids[DSO_FIRINGPIN].setValue(true);  //LAUNCH!!
					Wait(500);
					dnoids[DSO_FIRINGPIN].setValue(false);  //reset pin
					vics[VI_SHOOTER]->Set(0.f);  //kill motor
				}
			}
		}

		if(buttonBuffer[B_GATE] == 0 && sticks[JS_LEFT]->GetRawButton(1) == 1) {  //if gate button just pressed
			if(canAdjustState[AS_GATE] == true)  //if your allowed to modify the gate
				dnoids[DSO_GATE].setValue(!dnoids[DSO_GATE].getValue());  //flip gate
		}

		if(buttonBuffer[B_LOADING] == 0 && sticks[JS_LEFT]->GetRawButton(5) == 1) {  //if loading button just pressed
			if(getRobotState() == RS_LOADING)  //toggle loading state (remembers previous value)
				setRobotState((defense)?RS_DRIVING_DEF:RS_DRIVING_OFF);
			else
				setRobotState(RS_LOADING);
		}
		
		if(switches[SW_FORK] == 0) {  //if the fork is not at the bottom
			spikes[SP_CONVEYOR]->Set(Relay::kOff);  //turn off conveyor
			if(canAdjustState[AS_FORK]) {  //if you can modify fork
				Wait(500);
				dnoids[DSO_FORK].setValue(true);  //set fork  up
				Wait(500);
				dnoids[DSO_FORK].setValue(false);  //set fork down
			}
		} else {
			if(dnoids[DSO_GATE].getValue() == true)
				spikes[SP_CONVEYOR]->Set(Relay::kForward);  //turn the conveyor back on
		}

		// todo write an override for this if vision is used
		if(canAdjustState[AS_ELEVATOR]) {  //if you can adjust the elevation
			if(sticks[JS_RIGHT]->GetRawButton(10))  //controls elevator
				vics[VI_ELEVATOR]->Set(.3f);  //move elevator down
			else if(sticks[JS_RIGHT]->GetRawButton(11))  //controls elevator other way
				vics[VI_ELEVATOR]->Set(-.3f);  //move elevator up alec dies
			else
				vics[VI_ELEVATOR]->Set(0.f);  //turn off elevator
		}

		buttonBuffer[B_DEFENSE] = sticks[JS_LEFT]->GetRawButton(3);  //resets buffers
		buttonBuffer[B_SHOOTING] = sticks[JS_LEFT]->GetRawButton(4);
		buttonBuffer[B_LOADING] = sticks[JS_LEFT]->GetRawButton(5);
		buttonBuffer[B_SHOOT] = sticks[JS_RIGHT]->GetRawButton(1);
		buttonBuffer[B_GATE] = sticks[JS_LEFT]->GetRawButton(1);
	}
}

void* hDrive(void *args) {   //drives  -- used in a separate driving thread
	Cyberhawk *hawk = (Cyberhawk*)args;
	while(hawk->IsEnabled()) {
		hawk->Drive(hawk->sticks[hawk->JS_LEFT]->GetY(), hawk->sticks[hawk->JS_RIGHT]->GetY());
	}
	return 0;
}  
