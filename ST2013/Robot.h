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

#ifndef RAVIOLI
#define RAVIOLI

#include "WPILib.h"
#include "alec/AutoParser.h"
#include "alec/ConstParser.h"
#include "alec/GenericController.h"
#include "alec/RoboSock.h"
#include "alec/Threading.h"
#include "alec/DoubleNoid.h"
#include "alec/stderr.h"
#include "alec/ugly.h"
#include <vector>

class Cyberhawk : public SimpleRobot {
public:
	NetworkTable *server;
	
	std::vector<Talon*>			drive;
	std::vector<Victor*> 		vics;
	std::vector<Solenoid*>		noids;
	std::vector<DigitalInput*>	switches;
	std::vector<Joystick*>		sticks;
	std::vector<Relay*>			spikes;
	std::vector<Encoder*>		encoders;
	
	Compressor							compressor;
	Counter								cshooter;
	
	DoubleNoid							*dnoids;
	
	ErrorContext						cerr;
	
	bool canAdjustState[4];
	
	enum kAdjustableStates	{AS_GATE, AS_FORK, AS_FIRINGPIN, AS_ELEVATOR};
	
	enum kDrive				{DR_LEFT, DR_RIGHT};
	enum kVictors			{VI_ELEVATOR, VI_SHOOTER, VI_WINCH};
	
	enum kSolenoids			{SO_LOFAN_EXTEND	, SO_LOFAN_RETRACT,
							 SO_HIFAN_EXTEND	, SO_HIFAN_RETRACT,
							 SO_FIRINGPIN_IN	, SO_FIRINGPIN_OUT,
							 SO_GATE_EXTEND		, SO_GATE_RETRACT,
							 SO_FORK_UP			, SO_FORK_DOWN,
							 SO_ARMS_UP			, SO_ARMS_DOWN};

	enum kDoubleNoids		{DSO_LOFAN, DSO_HIFAN, DSO_FIRINGPIN, DSO_GATE, DSO_FORK, DSO_ARMS};
	
	enum kSwitches			{SW_FORK, SW_ELEVATOR};
	enum KJoysticks			{JS_GAMEPAD, JS_LEFT, JS_RIGHT};
	enum kEncoders			{EN_ELEVATOR, EN_DRIVELEFT, EN_DRIVERIGHT};
	enum kSpikes			{SP_CONVEYOR}; // todo figure out if dump is used
	
	enum kFanPos			{FAN_UP, FAN_MIDDLE, FAN_DOWN};
	kFanPos fanPosition;
	
	enum kRobotStates		{RS_DRIVING_OFF, RS_DRIVING_DEF, RS_SHOOTING, RS_LOADING, RS_DEFAULT};
	kRobotStates currentRobotState;
	
// BELOW BE FUNCTIONS
	
	Cyberhawk(void);
	~Cyberhawk(void);
	
	void setRobotState(kRobotStates);
	int getRobotState();
	void setAdjustableStates(bool,bool,bool,bool);
	
	void Autonomous(void);
	void OperatorControl(void);

	void setFan(kFanPos);
	int getFanPosition();
	
	void Drive(float, float);
	void Dump(); // implement this eventually and remove virtual
};

#endif
