/*
 * This class (Cyberhawk) is the entry point of the robot.
 * 
 * Please do NOT implement Autonomous or Teleop in this
 * file. Use the respective Autonomous.cpp and Teleop.cpp
 * for implementations.
 * 
 * should either be shared between teleop and autonomous
 * 
 * 
 */

#ifndef RAVIOLIISVERYYUMMY
#define RAVIOLIISVERYYUMMY

#include "WPILib.h"
#include "alec/AutoParser.h"
#include "alec/ConstParser.h"
#include "alec/GenericController.h"
#include "alec/RoboSock.h"
#include "alec/Threading.h"
#include "ugly.h"

class Cyberhawk : public SimpleRobot {
	NetworkTable *server;
	
	GenericController<Jaguar> 		drive; // todo replace with talon
	GenericController<Victor> 		vics;
	GenericController2Arg<Solenoid>		noids;
	GenericController<DigitalInput>		switches;
	GenericController<Joystick>		sticks;
	GenericController2Arg<Encoder>		encoders;
	
	Compressor				compressor;
	Counter					shootercounter;
	Relay					conveyor;
	
	// todo verify all of these enums
	enum kDrive		{DR_RIGHT, DR_LEFT};
	enum kVictors		{VI_SHOOTER, VI_ANGLER, VI_UNKNOWN1, VI_UNKNOWN2};
	enum kSolenoids		{SO_CHUTE_LOW, SO_CHUTE_HI, SO_FIRING, SO_GATE, SO_FORK, SO_ARMS};
	enum kSwitches		{SPEED_SO, FORKLIFT_SO, ELEVATION_SO, COMP_PRESSURE };
	enum KJoysticks		{RIGHT_JOY, LEFT_JOY, ACTIVE_JOY};
	enum kEncoders		{EN_RAISER, EN_DRIVELEFT, EN_DRIVERIGHT};
public:
	Cyberhawk(void);
	~Cyberhawk(void);
	
	void Autonomous(void);
	void OperatorControl(void);
};

#endif
