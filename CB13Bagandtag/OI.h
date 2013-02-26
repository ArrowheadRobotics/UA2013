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
	JoystickButton* WinchInButton;
	JoystickButton* WinchOutButton;
	
public:
	OI();
	NetworkTable* server;
	NetworkTable* server2;
	Joystick* getjoy1();
	Joystick* getjoy2();
};
#endif
