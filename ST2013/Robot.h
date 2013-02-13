/*
 * This class (Cyberhawk) is the entry point of the robot.
 * 
 * Please do NOT implement Autonomous or Teleop in this
 * file. Use the respective Autonomous.cpp and Teleop.cpp
 * for implementations.
 * 




 * should either be shared between teleop and autonomous
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
	
	GenericController<Jaguar> 	*drive;
	GenericController<Victor> 	*vics;
	GenericController<Solenoid>	*noids;
	GenericController<Relay> 	*spikes;
	
	enum kDrive 	{DR_BACKLEFT, DR_BACKRIGHT, DR_FRONTLEFT, DR_FRONTRIGHT};
	enum kVictors 	{VI_SHOOTER, VI_ANGLER, VI_UNKNOWN1, VI_UNKNOWN2}; // todo figure out unknowns
	enum kSolenoids	{SO_SHAFT, /* todo see right */ SO_INTAKEARMS, SO_INTAKEPUSH /* todo figure out if one or two */, SO_SHOOTARM, SO_LIFTARM, SO_TRAYBOT, SO_TRAYTOP};
	enum kSpikes 	{SP_INTAKE, SP_COMPRESS};
public:
	Cyberhawk(void);
	~Cyberhawk(void);
	
	void Autonomous(void);
	void OperatorControl(void);
};

#endif
