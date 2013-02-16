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
#include "alec/DoubleNoid.h"
#include "alec/ugly.h"

class Cyberhawk : public SimpleRobot {
	NetworkTable *server;
	
	GenericController<Jaguar> 			drive; // todo replace with talon
	GenericController<Victor> 			vics;
	GenericController2Arg<Solenoid>		noids;
	GenericController<DigitalInput>		switches;
	GenericController<Joystick>			sticks;
	GenericController<Relay>			spikes;
	GenericController2Arg<Encoder>		encoders;
	
	Compressor							compressor;
	Counter								cshooter;
	
	DoubleNoid							*dnoids;
	
	enum kDrive			{DR_LEFT, DR_RIGHT};
	enum kVictors		{VI_ELEVATOR, VI_SHOOTER, VI_WINCH};
	
	enum kSolenoids		{SO_LOFAN_EXTEND	, SO_LOFAN_RETRACT,
						 SO_HIFAN_EXTEND	, SO_HIFAN_RETRACT,
						 SO_FIRINGPIN_IN	, SO_FIRINGPIN_OUT,
						 SO_GATE_EXTEND		, SO_GATE_RETRACT,
						 SO_FORK_UP			, SO_FORK_DOWN,
						 SO_ARMS_UP			, SO_ARMS_DOWN};

	enum kDoubleNoids	{DSO_FIRINGPIN, DSO_GATE, DSO_FORK, DSO_ARMS};
	
	enum kSwitches		{SW_FORK, SW_ELEVATOR, SW_CPRESSURE};
	enum KJoysticks		{JS_LEFT, JS_RIGHT, JS_ACTION};
	enum kEncoders		{EN_ELEVATOR, EN_DRIVELEFT, EN_DRIVERIGHT};
	enum kSpikes		{SP_CONVEYOR}; // todo figure out if dump is used
	
	enum kFanPos		{FAN_UP, FAN_MIDDLE, FAN_DOWN};
public:
	Cyberhawk(void);
	~Cyberhawk(void);
	
	void resetStates();
	
	void Autonomous(void);
	void OperatorControl(void);
	
	void Drive(float, float);
	virtual void Dump(); // implement this eventually and remove virtual
};

#endif
