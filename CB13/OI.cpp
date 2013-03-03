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
#include "Commands/ClimberMove.h"
#include "Commands/ClimberToggle.h"
#include "Commands/gateToggle.h"
#include "Commands/highExtend.h"
#include "Commands/highRetract.h"
#include "Commands/lowExtend.h"
#include "Commands/lowRetract.h"
#include "Commands/fire.h"
#include "Commands/Dump.h"
#include "Commands/ConveyorUp.h"
#include "Commands/RetractFire.h"
#include "Commands/LoadFire.h"
#include "Commands/Dump.h"
#include "Commands/ClimberStop.h"
#include "Commands/IncChuteState.h"
#include "Commands/DecChuteState.h"


 
OI::OI() {
	// Joysticks *****************************************************
	gamepad = new Joystick(1);
	joy1 = new Joystick(2);
	joy2 = new Joystick(3);
	upButton = new JoystickButton(gamepad, 1);
	upButton->WhileHeld(new move_up());
	dnButton = new JoystickButton(gamepad, 2);
	dnButton->WhileHeld(new move_dn());
	stButton = new JoystickButton(gamepad, 3);
	stButton->WhileHeld(new move_st());
	trButton = new JoystickButton(gamepad, 4);
	trButton->WhileHeld(new TrackTarget());
	highExtendButton = new JoystickButton(gamepad, 5);//Todo Rename
	highExtendButton->WhileHeld(new IncChuteState());
	highRetractButton = new JoystickButton(gamepad, 6);//Todo Rename
	highRetractButton->WhileHeld(new DecChuteState());
	lowExtendButton= new JoystickButton(gamepad, 7);
	lowExtendButton->WhileHeld(new lowExtend());
	lowRetractButton = new JoystickButton(gamepad, 8);
	lowRetractButton->WhileHeld(new lowRetract());
	
	gateButton = new JoystickButton(joy1, 1);
	gateButton->WhenPressed(new gateToggle());
	
	gateButton = new JoystickButton(joy1, 1);
	gateButton->WhenPressed(new gateToggle());
	
	shootButton = new JoystickButton(joy2, 1);
	shootButton->WhileHeld(new Fire());

	// SmartDashboard Buttons ***************************************
	
	//Frisbee commands
	SmartDashboard::PutData("frisbeeToggle", new FrisbeeToggle());
	SmartDashboard::PutData("Dump", new Dump());
	
	
	//Climber commands
	SmartDashboard::PutData("ClimberMove", new ClimberMove());
	SmartDashboard::PutData("ClimberStop", new ClimberStop());
	SmartDashboard::PutData("ClimberToggle", new ClimberToggle());
	SmartDashboard::PutData("Convey", new ConveyorUp());

	
	
	//Gate commands
	SmartDashboard::PutData("gateToggle", new gateToggle());
	SmartDashboard::PutData("Dump", new Dump());
	
	
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
	SmartDashboard::PutData("fire", new Fire());
	SmartDashboard::PutData("LoadFire", new LoadFire());
	SmartDashboard::PutData("RetractFire", new RetractFire());
	
	
	// Network Tables *************************************************
	server = NetworkTable::GetTable("SmartDashboard");
	server2 = NetworkTable::GetTable("");

}
Joystick* OI::getjoy1() {
	return joy1;
}
Joystick* OI::getjoy2() {
	return joy2;
}
Joystick* OI::getgamepad() {
	return gamepad;
}
