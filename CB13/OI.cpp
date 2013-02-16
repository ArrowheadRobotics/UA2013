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
<<<<<<< HEAD
#include "Commands/Dump.h"
=======
#include "Commands/gateToggle.h"
#include "Commands/highExtend.h"
#include "Commands/highRetract.h"
#include "Commands/lowExtend.h"
#include "Commands/lowRetract.h"
#include "Commands/fire.h"
#include "Commands/fire.h"
>>>>>>> Added commands to smartDashboard

OI::OI() {
	// Joysticks *****************************************************
	gamepad1 = new Joystick(1);
	gamepad2 = new Joystick(2);
	upButton = new JoystickButton(gamepad1, 1);
	upButton->WhileHeld(new move_up());
	dnButton = new JoystickButton(gamepad1, 2);
	dnButton->WhileHeld(new move_dn());
	stButton = new JoystickButton(gamepad1, 3);
	stButton->WhileHeld(new move_st());
	trButton = new JoystickButton(gamepad1, 4);
	trButton->WhileHeld(new TrackTarget());

	// SmartDashboard Buttons ***************************************
	
	//FrisbeeHandler commands
	SmartDashboard::PutData("frisbeeToggle", new frisbeeToggle());
	SmartDashboard::PutData("Dump", new Dump());
	
	
	
	//Climber commands
	SmartDashboard::PutData("climberMove", new climberMove());
	SmartDashboard::PutData("climberToggle", new climberToggle());

	
	
	//Gate commands
	SmartDashboard::PutData("gateToggle", new gateToggle());
	
	
	//Solenoid commands
	SmartDashboard::PutData("highExtend", new highExtend());
	SmartDashboard::PutData("highRetract", new highRetract());
	SmartDashboard::PutData("lowExtend", new lowExtend());
	SmartDashboard::PutData("lowRetract", new lowRetract());
	
	
	//Shooter commands
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
	SmartDashboard::PutData("Tank Drive (drive3)", new drive3());
	SmartDashboard::PutData("stop", new stop());
	SmartDashboard::PutData("square", new square());

	
	//Firing Pin commands
	SmartDashboard::PutData("fire", new fire());
	SmartDashboard::PutData("recoil", new recoil());
	
	
	// Network Tables *************************************************
	server = NetworkTable::GetTable("SmartDashboard");
	server2 = NetworkTable::GetTable("");

}
Joystick* OI::getgamepad1() {
	return gamepad1;
}
Joystick* OI::getgamepad2() {
	return gamepad2;
}
