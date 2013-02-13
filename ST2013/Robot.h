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

class Cyberhawk : public SimpleRobot {
	NetworkTable *server;
	
	GenericController<Jaguar> 		drive; // todo replace with talon
	GenericController<Victor> 		vics;
	GenericController<Solenoid>		noids;
	GenericController<Relay> 		spikes;
	GenericController<DigitalInput>	switches;
	
	GenericController2Arg<Encoder>	encoders;
	
	Compressor						compressor;
	Counter							shootercounter;
	
	// todo verify all of these enums
	enum kDrive			{DR_FRONTRIGHT, DR_FRONTLEFT, DR_BACKRIGHT, DR_BACKLEFT};
	enum kVictors		{VI_SHOOTER, VI_ANGLER, VI_UNKNOWN1, VI_UNKNOWN2};
	enum kSolenoids		{SO_SHAFT, SO_INTAKEARMS, SO_INTAKEPUSH, SO_SHOOTARM, SO_LIFTARM, SO_TRAYBOT, SO_TRAYTOP};
	enum kSpikes		{SP_INTAKE, SP_COMPRESS};
	enum kSwitches		{DI_INTAKE};
	enum kEncoders		{EN_RAISER, EN_DRIVELEFT, EN_DRIVERIGHT};
public:
	Cyberhawk(void);
	~Cyberhawk(void);
	
	void Autonomous(void);
	void OperatorControl(void);
};

#endif
