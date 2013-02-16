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
public:
	OI();
	NetworkTable* server;
	NetworkTable* server2;
	Joystick* getjoy1();
	Joystick* getjoy2();
};
#endif
