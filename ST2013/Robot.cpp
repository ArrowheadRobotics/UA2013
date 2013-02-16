/*
 * Use this file for implementing the constructor
 * and destructor, as well as defining any global 
 */

#include "Robot.h"

Cyberhawk::Cyberhawk() :	drive(2, 1, 2),
							vics(2, 4, 5),
							noids(12,	1,1, 1,2, 1,3, 1,4, 1,5, 1,6,
										2,1, 2,2, 2,3, 2,4, 2,5, 2,6),
							switches(4, 1, 8, 9, 10),
							sticks(3, 1, 2, 3),
							spikes(1, 1),
							encoders(3, 2, 3, 4 ,5 ,6, 7),
							compressor(1, 2),
							cshooter(1),
							elevator(3),
							cerr("stderr.txt")
{
	server = NetworkTable::GetTable("SmartDashboard");
	compressor.Start();
	
	for(int i = 0; i < 4; i++)
		canAdjustState[i] = true;
	
	dnoids = new DoubleNoid[6];
	dnoids[DSO_LOFAN].setNoids(noids[SO_LOFAN_EXTEND], noids[SO_LOFAN_RETRACT], true);
	dnoids[DSO_HIFAN].setNoids(noids[SO_HIFAN_EXTEND], noids[SO_HIFAN_RETRACT], true);
	dnoids[DSO_FIRINGPIN].setNoids(noids[SO_FIRINGPIN_IN], noids[SO_FIRINGPIN_OUT]);
	dnoids[DSO_GATE].setNoids(noids[SO_GATE_EXTEND], noids[SO_GATE_RETRACT]);
	dnoids[DSO_FORK].setNoids(noids[SO_FORK_UP], noids[SO_FORK_DOWN]);
	dnoids[DSO_ARMS].setNoids(noids[SO_ARMS_UP], noids[SO_ARMS_DOWN]);
	
	Ugly::Uglify();
}

void Cyberhawk::setAdjustableStates(bool gate, bool fork, bool firingpin, bool elevator) {
	canAdjustState[AS_GATE] = gate;
	canAdjustState[AS_FORK] = fork;
	canAdjustState[AS_FIRINGPIN] = firingpin;
	canAdjustState[AS_ELEVATOR] = elevator;
}

void Cyberhawk::setRobotState(kRobotStates state) {
	switch(state) {
	case RS_DEFAULT: // allows for a smooth transition between autonomous and teleop, should not be needed anywhere else
		setAdjustableStates(true, true, true, true);
		for(int i = 2; i < 6; i++) dnoids[i].setToDefaultValue();
		for(int i = 0; i < vics.getCount(); i++) vics[i]->Set(0);
		for(int i = 0; i < drive.getCount(); i++) drive[i]->Set(0);
		for(int i = 0; i < spikes.getCount(); i++) spikes[i]->Set(Relay::kOff);
		for(int i = 0; i < encoders.getCount(); i++) encoders[i]->Reset();
		setFan(FAN_UP);
		cshooter.Reset();
		elevator.Set(0);
		break;
	case RS_DRIVING_OFF: // offensive driving state
		setAdjustableStates(true, true, false, false);
		setFan(FAN_DOWN);
		dnoids[DSO_FIRINGPIN].setValue(false);
		elevator.Set(0);
		break;
	case RS_DRIVING_DEF: // defensive driving state
		setAdjustableStates(false, false, false, false);
		setFan(FAN_UP);
		dnoids[DSO_GATE].setValue(false);
		dnoids[DSO_FORK].setValue(false);
		dnoids[DSO_FIRINGPIN].setValue(false);
		elevator.Set(0);
		break;
	case RS_SHOOTING: // shooting state
		setAdjustableStates(false, false, true, true);
		setFan(FAN_DOWN);
		dnoids[DSO_GATE].setValue(false);
		dnoids[DSO_FORK].setValue(false);
		break;
	case RS_LOADING: // loading state
		setAdjustableStates(false, false, false, false);
		setFan(FAN_MIDDLE);
		dnoids[DSO_GATE].setValue(false);
		dnoids[DSO_FORK].setValue(false);
		dnoids[DSO_FIRINGPIN].setValue(true);
		elevator.Set(0);
		break;
	default:
		cerr.write("FATAL ERROR IN STATE SHIFTING\n");
		break;
	}
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
	drive[DR_LEFT]->Set(left);
	drive[DR_RIGHT]->Set(right);
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
