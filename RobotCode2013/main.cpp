#include "WPILib.h"
#include "GenericController.h"
#include "Threading.h"
#include "Parser.h"

void* testThread(void*);

class Cyberhawk : public SimpleRobot {
	GenericController<Joystick> sticks;
	GenericController<Victor> gjkgf;
	GenericController<CANJaguar> asdfsd;
	Thread hi;
public:
	Cyberhawk(void) : sticks(2, 0, 1),
					  hi(testThread) 
	{
		hi.spawnThread();
		sticks[1]->GetRawButton(3);
	}

	void Autonomous(void) {
		// actual final draft of autonomous
	}

	void OperatorControl(void) {
		while (IsOperatorControl()) {

		}
	}
	
	void Test() {
		
	}
};

START_ROBOT_CLASS(Cyberhawk);

void* testThread(void *args) {
	printf("matlab");
	return 0;
}
