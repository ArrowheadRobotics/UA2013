/*
 * Use this file for implementing the constructor
 * and destructor, as well as defining any global 
 */

#include "Robot.h"

Cyberhawk::Cyberhawk() :	compressor(10, 2),  //initilize shit
							cshooter(1),
							cerr("stderr.txt")
{
	server = NetworkTable::GetTable("SmartDashboard");
	compressor.Start();

	for(int i = 1; i <= 2; i++)
		drive.push_back(new Talon(i));
	for(int i = 3; i <= 5; i++)
		vics.push_back(new Victor(i));
	for(int i = 8; i <= 9; i++)
		switches.push_back(new DigitalInput(i));
	for(int i = 1; i <= 3; i++)
		sticks.push_back(new Joystick(i));
	spikes.push_back(new Relay(1));
	for(int i = 2; i <= 7; i+=2)
		encoders.push_back(new Encoder(i, i+1));
	for(int i = 1; i <= 2; i++) {
		for(int j = 1; j <= 6; j++)
			noids.push_back(new Solenoid(i,j));
	}
	
	for(int i = 0; i < 4; i++)
		canAdjustState[i] = true;
	
	dnoids = new DoubleNoid[6];
	dnoids[DSO_LOFAN].setNoids(noids[SO_LOFAN_EXTEND], noids[SO_LOFAN_RETRACT], true);
	dnoids[DSO_HIFAN].setNoids(noids[SO_HIFAN_EXTEND], noids[SO_HIFAN_RETRACT], true);
	dnoids[DSO_FIRINGPIN].setNoids(noids[SO_FIRINGPIN_IN], noids[SO_FIRINGPIN_OUT]);
	dnoids[DSO_GATE].setNoids(noids[SO_GATE_EXTEND], noids[SO_GATE_RETRACT]);
	dnoids[DSO_FORK].setNoids(noids[SO_FORK_UP], noids[SO_FORK_DOWN]);
	dnoids[DSO_ARMS].setNoids(noids[SO_ARMS_DOWN], noids[SO_ARMS_UP]);
	
	Ugly::Uglify();
}

void Cyberhawk::setAdjustableStates(bool gate, bool fork, bool firingpin, bool elevator) {
	canAdjustState[AS_GATE] = gate;
	canAdjustState[AS_FORK] = fork;
	canAdjustState[AS_FIRINGPIN] = firingpin;
	canAdjustState[AS_ELEVATOR] = elevator;
}

void Cyberhawk::setRobotState(kRobotStates state) {
	printf("Changing state to %i ...", state);
	switch(state) {
	case RS_DEFAULT: // allows for a smooth transition between autonomous and teleop, should not be needed anywhere else
		vics[VI_ELEVATOR]->Set(.3);  //puts elevator at bottom
		while(switches[SW_ELEVATOR] == 0);
		vics[VI_ELEVATOR]->Set(0);
		
		setAdjustableStates(true, true, true, true);  //resets shit
		
		for(int i = 2; i < 6; i++) dnoids[i].setToDefaultValue();  //reset noids
		for(unsigned int i = 0; i < vics.size(); i++) vics[i]->Set(0);  //reset more shit
		for(unsigned int i = 0; i < drive.size(); i++) drive[i]->Set(0);
		for(unsigned int i = 0; i < spikes.size(); i++) spikes[i]->Set(Relay::kOff);
		for(unsigned int i = 0; i < encoders.size(); i++) encoders[i]->Reset();
		setFan(FAN_DOWN);  //put fan down
		cshooter.Reset();  //reset shooter counter
		break;
		
	case RS_DRIVING_OFF: // offensive driving state
		vics[VI_ELEVATOR]->Set(.3);  //lower elevator
		while(switches[SW_ELEVATOR] == 0);
		vics[VI_ELEVATOR]->Set(0);
		
		setAdjustableStates(true, true, false, false);  //gate, fork, firing pin, elevator
		setFan(FAN_DOWN);
		dnoids[DSO_FIRINGPIN].setValue(false);  //turn off firing pin
		break;
		
	case RS_DRIVING_DEF: // defensive driving state
		vics[VI_ELEVATOR]->Set(.3);  //lower elevator (again)
		while(switches[SW_ELEVATOR] == 0);
		vics[VI_ELEVATOR]->Set(0);
		
		setAdjustableStates(false, false, false, false);  //you cant do shit
		setFan(FAN_UP);
		
		dnoids[DSO_GATE].setValue(false);  //nothing works
		dnoids[DSO_FORK].setValue(false);
		dnoids[DSO_FIRINGPIN].setValue(false);
		break;
		
	case RS_SHOOTING: // shooting state
		setAdjustableStates(false, false, true, true);  //cant control gate or fork
		setFan(FAN_DOWN);  //lower fan
		
		dnoids[DSO_GATE].setValue(false);  //turn off gate
		dnoids[DSO_FORK].setValue(false);  //turn off fork
		break;
		
	case RS_LOADING: // loading state
		vics[VI_ELEVATOR]->Set(.3);  //drop elevator
		while(switches[SW_ELEVATOR] == 0);
		vics[VI_ELEVATOR]->Set(0);
		
		setAdjustableStates(false, false, false, false);  //cant do shit
		setFan(FAN_MIDDLE);  //OMG ITS IN THE MIDDLE
		
		dnoids[DSO_GATE].setValue(false);  //boring
		dnoids[DSO_FORK].setValue(false);  //boring
		dnoids[DSO_FIRINGPIN].setValue(true);  //keeps from falling down
		break;
		
	default:
		cerr.write("FATAL ERROR IN STATE SHIFTING\n");  //YOU REALLY FUCKED UP
		break;
	}
	currentRobotState = state;
	printf("Finished changing state.\n");
}

int Cyberhawk::getRobotState() {	
	return currentRobotState;
}

void Cyberhawk::setFan(kFanPos pos) {
	switch(pos) {
	case FAN_UP:
		dnoids[DSO_LOFAN].setValue(true);
		dnoids[DSO_HIFAN].setValue(true);
		break;
	case FAN_MIDDLE:
		dnoids[DSO_LOFAN].setValue(true);
		dnoids[DSO_HIFAN].setValue(false);
		break;
	case FAN_DOWN:
		dnoids[DSO_LOFAN].setValue(false);
		dnoids[DSO_HIFAN].setValue(false);
		break;
	}
	fanPosition = pos;
}

int Cyberhawk::getFanPosition() {
	return fanPosition;
}

void Cyberhawk::Drive(float left, float right) {
	drive[DR_LEFT]->Set(left/2.f);
	drive[DR_RIGHT]->Set(-right/2.f);
}

Cyberhawk::~Cyberhawk() {
	compressor.Stop();
	
	delete &drive;
	delete &vics;
	delete &noids;
	delete &switches;
	delete &encoders;
	delete &compressor;
	delete &spikes;
}

START_ROBOT_CLASS(Cyberhawk);
