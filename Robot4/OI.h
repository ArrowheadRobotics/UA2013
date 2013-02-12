#ifndef OI_H
#define OI_H
#include "WPILib.h"
class OI {
private:
	Joystick* gamepad;
	JoystickButton* upButton;
	JoystickButton* dnButton;
	JoystickButton* stButton;
	JoystickButton* trButton;
	JoystickButton* rsButton;
public:
	OI();
	NetworkTable* server;
	NetworkTable* server2;
	Joystick* getJoy1();
};
#endif
