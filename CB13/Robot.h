#ifndef _ROBOT_H
#define _ROBOT_H
#include "WPILib.h"
#include "Commands/Command.h"
#include "RobotMap.h"
#include "LiveWindow/LiveWindow.h"
#include "Subsystems/gate.h"
#include "Commands/AutonomousCommand.h"
#include "Subsystems/Elevation.h"
#include "Subsystems/driver.h"
#include "Subsystems/frisbeeHandler.h"
#include "Subsystems/climber.h"
#include "Subsystems/Chute.h"
#include "Subsystems/Conveyor.h"
#include "OI.h"
class Robot : public IterativeRobot {
public:
	Command *autonomousCommand;
	static ::gate* gate;
	static OI *oi;
	LiveWindow *lw;
	static ::Elevation* elevation;
	static ::Conveyor* conveyor;
	static ::driver* driver;
	static ::frisbeeHandler* frisbeeHandler;
	static ::climber* climber;
	static ::Chute* chute;
	virtual void RobotInit();
	virtual void AutonomousInit();
	virtual void AutonomousPeriodic();
	virtual void TeleopInit();
	virtual void TeleopPeriodic();
	virtual void TestPeriodic();
	
};
#endif
