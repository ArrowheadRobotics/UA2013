/*
 * Use this file for implementing the constructor
 * and destructor, as well as defining any global 
 */

#include "Robot.h"

Cyberhawk::Cyberhawk() :	drive(4, 1, 2, 3, 4),
							vics(4, 1, 2, 3, 4),
							noids(7, 1, 2, 3, 4, 5, 6, 7),
							spikes(1, 1),
							switches(2, 1, 2),
							// todo make sure these match the enums
							compressor(1,2)
{
	server = NetworkTable::GetTable("SmartDashboard");
	compressor.Start();
}

Cyberhawk::~Cyberhawk() {
	compressor.Stop();
	
	delete &drive;
	delete &vics;
	delete &noids;
	delete &spikes;
	delete &switches;
	delete &compressor;
}

START_ROBOT_CLASS(Cyberhawk);
