/*
 * This class (Cyberhawk) is the entry point of the robot.
 * 
 * Please do NOT implement Autonomous or Teleop in this
 * file. Use the respective Autonomous.cpp and Teleop.cpp
 * for implementations.
 */

#ifndef ROBOTH
#define ROBOTH

#include "WPILib.h"

class Cyberhawk : public SimpleRobot {
	
public:
	Cyberhawk(void) {};
	~Cyberhawk(void) {};
	
	void Autonomous(void);
	void OperatorControl(void);
};

#endif
