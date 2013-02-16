/*
 * Operator Interface Code
 * This set of code links commands to the driverstation
 * Dashboard
 * Controllers
 * DSeIO
 * Networktables
 */
#include "OI.h"
#include "SmartDashboard/SmartDashboard.h"
#include "Commands/AutonomousCommand.h"
#include "Commands/TrackTarget.h"
#include "Commands/move_dn.h"
#include "Commands/move_up.h"
#include "Commands/move_st.h"
#include "Robot.h"
#include "Subsystems/Elevation.h"
#include "Commands/drive1.h"
#include "Commands/drive2.h"
#include "Commands/drive3.h"
#include "Commands/square.h"
#include "Commands/stop.h"
#include "Commands/ShootController.h"
#include "Commands/frisbeeToggle.h"
#include "Commands/climberMove.h"
#include "Commands/climberToggle.h"
#include "Commands/Dump.h"

OI::OI() {
	// Joysticks *****************************************************
	gamepad = new Joystick(1);
	upButton = new JoystickButton(gamepad, 1);
	upButton->WhileHeld(new move_up());
	dnButton = new JoystickButton(gamepad, 2);
	dnButton->WhileHeld(new move_dn());
	stButton = new JoystickButton(gamepad, 3);
	stButton->WhileHeld(new move_st());
	trButton = new JoystickButton(gamepad, 4);
	trButton->WhileHeld(new TrackTarget());

	// SmartDashboard Buttons ***************************************
	
	//FrisbeeHandler commands
	SmartDashboard::PutData("frisbeeToggle", new frisbeeToggle());
	SmartDashboard::PutData("Dump", new Dump());
	
	
	
	//Climber commands
	SmartDashboard::PutData("climberMove", new climberMove());
	SmartDashboard::PutData("climberToggle", new climberToggle());
	
	
	//Shooter elevation commands
	SmartDashboard::PutData("Autonomous Command", new AutonomousCommand());
	SmartDashboard::PutData("move_up", new move_up());
	SmartDashboard::PutData("move_dn", new move_dn());
	SmartDashboard::PutData("stop", new move_st());
	SmartDashboard::PutData("TrackTarget", new TrackTarget());
	SmartDashboard::PutData("Go",new ShootController());


	//Drivebase commands
	SmartDashboard::PutData("Autonomous Command", new AutonomousCommand());
	SmartDashboard::PutData("drive1", new drive1());
	SmartDashboard::PutData("drive2", new drive2());
	SmartDashboard::PutData("drive3", new drive3());
	SmartDashboard::PutData("stop", new stop());
	SmartDashboard::PutData("square", new square());

	// Network Tables *************************************************
	server = NetworkTable::GetTable("SmartDashboard");
	server2 = NetworkTable::GetTable("");

}
Joystick* OI::getJoy1() {
	return gamepad;
}
