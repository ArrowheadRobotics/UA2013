#ifndef OI_H
#define OI_H
#include "WPILib.h"
class OI {
private:
	Joystick* gamepad1;
	Joystick* gamepad2;
	JoystickButton* upButton;
	JoystickButton* dnButton;
	JoystickButton* stButton;
	JoystickButton* trButton;
	JoystickButton* rsButton;
public:
	OI();
	NetworkTable* server;
	NetworkTable* server2;
	Joystick* getgamepad1();
	Joystick* getgamepad2();
};
#endif
