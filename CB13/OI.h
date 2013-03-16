#ifndef OI_H
#define OI_H
#include "WPILib.h"
class OI {
private:
	Joystick* gamepad;
	Joystick* joy1;
	Joystick* joy2;
	JoystickButton* upButton;
	JoystickButton* dnButton;
	JoystickButton* stButton;
	JoystickButton* trButton;
	JoystickButton* rsButton;
	JoystickButton* gateButton;
	JoystickButton*	shootButton;
	JoystickButton* highExtendButton;
	JoystickButton* highRetractButton;
	JoystickButton* lowExtendButton;
	JoystickButton* lowRetractButton;
	JoystickButton* climberups;
public:
	JoystickButton* climberdowns;//see driver.cpp
	OI();
	Timer *matchTimer;
#ifdef USE_NETWORK
	NetworkTable* server;
	NetworkTable* server2;
#endif
	Joystick* getjoy1();
	Joystick* getjoy2();
	Joystick* getgamepad();
};
#endif
