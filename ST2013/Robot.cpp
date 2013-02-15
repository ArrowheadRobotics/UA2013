/*
 * Use this file for implementing the constructor
 * and destructor, as well as defining any global 
 */

#include "Robot.h"

Cyberhawk::Cyberhawk() :	drive(2, 2, 1),  //good
							vics(4, 4, 3, 8, 9),  //good
							noids(6,1.1,1.3,1.5,2.1,2.3,2.5),  //good
							spikes(2, 1, 2),  //good
							switches(4,1,8,9,10),  //good
							sticks(3, 1, 2, 3),  //good
							encoders(6, 2, 3, 4 ,5 ,6, 7),  //good
							// todo make sure these match the enums
							compressor(1,2)  //good
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
