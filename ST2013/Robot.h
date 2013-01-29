/*
 * This class (Cyberhawk) is the entry point of the robot.
 * 
 * Please do NOT implement Autonomous or Teleop in this
 * file. Use the respective Autonomous.cpp and Teleop.cpp
 * for implementations.
 * 
 * In fact, don't implement anything here.
 * 
 * The only other functions that should be in this file
 * should either be shared between teleop and autonomous
 * 
 */

#ifndef RAVIOLI
#define RAVIOLI

#include "WPILib.h"
#include "alec/AutoParser.h"
#include "alec/ConstParser.h"
#include "alec/GenericController.h"
#include "alec/RoboSock.h"
#include "alec/Threading.h"

class Cyberhawk : public SimpleRobot {
	
public:
	Cyberhawk(void);
	~Cyberhawk(void);
	
	void Autonomous(void);
	void OperatorControl(void);
};

#endif
