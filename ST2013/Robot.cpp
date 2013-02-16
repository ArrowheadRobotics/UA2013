/*
 * Use this file for implementing the constructor
 * and destructor, as well as defining any global 
 */

#include "Robot.h"

Cyberhawk::Cyberhawk() :	drive(2, 1, 2),
							vics(3, 3, 4, 5),
							noids(12,	1,1, 1,2, 1,3, 1,4, 1,5, 1,6,
										2,1, 2,2, 2,3, 2,4, 2,5, 2,6),
							switches(4, 1, 8, 9, 10),
							sticks(3, 1, 2, 3),
							spikes(1, 1),
							encoders(3, 2, 3, 4 ,5 ,6, 7),
							compressor(1, 2),
							cshooter(1)
{
	server = NetworkTable::GetTable("SmartDashboard");
	compressor.Start();
	
	dnoids = new DoubleNoid[4];
	dnoids[DSO_FIRINGPIN].setNoids(noids[SO_FIRINGPIN_IN], noids[SO_FIRINGPIN_OUT]);
	dnoids[DSO_GATE].setNoids(noids[SO_GATE_EXTEND], noids[SO_GATE_RETRACT]);
	dnoids[DSO_FORK].setNoids(noids[SO_FORK_UP], noids[SO_FORK_DOWN]);
	dnoids[DSO_ARMS].setNoids(noids[SO_ARMS_UP], noids[SO_ARMS_DOWN]);
	
	Ugly::Uglify();
}

void Cyberhawk::resetStates() {
	for(int i = 0; i < 4; i++) dnoids[i].setValue(false);
	for(int i = 0; i < vics.getCount(); i++) vics[i]->Set(0);
	for(int i = 0; i < drive.getCount(); i++) drive[i]->Set(0);
	for(int i = 0; i < spikes.getCount(); i++) spikes[i]->Set(Relay::kOff);
	for(int i = 0; i < encoders.getCount(); i++) encoders[i]->Reset();
	cshooter.Reset();
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
