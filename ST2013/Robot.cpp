/*
 * Use this file for implementing the constructor
 * and destructor, as well as defining any global 
 */

#include "Robot.h"

Cyberhawk::Cyberhawk() :	drive(2, 2, 1),  //good
							vics(3, 3, 4, 5),  //good
							noids(6,1,1,1,3,1,5,2,1,2,3,2,5),  //good
							switches(4,1,8,9,10),  //good
							sticks(3, 1, 2, 3),  //good
							encoders(3, 2, 3, 4 ,5 ,6, 7),  //good
							// todo make sure these match the enums
							conveyor(1,1),  //good
							compressor(1,2)  //good
							servo(6);  //good
{
	server = NetworkTable::GetTable("SmartDashboard");
	compressor.Start();
	ugly();
}

Cyberhawk::~Cyberhawk() {
	compressor.Stop();
	
	delete &drive;
	delete &vics;
	delete &noids;
	delete &switches;
	delete &encoders;
	delete &compressor;
	delete &conveyor;
}

START_ROBOT_CLASS(Cyberhawk);
