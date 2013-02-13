/*
 * Use this file for implementing the constructor
 * and destructor, as well as defining any global 
 */

#include "Robot.h"

Cyberhawk::Cyberhawk() {
	server = NetworkTable::GetTable("SmartDashboard");
}

Cyberhawk::~Cyberhawk() {
	
}

START_ROBOT_CLASS(Cyberhawk);
