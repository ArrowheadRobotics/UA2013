/*
 * This class (Cyberhawk) is the entry point of the robot.
 */

#include "WPILib.h"
#include "GenericController.h"
#include "Threading.h"
#include "Parser.h"
#include "RoboSock.h"

void* testThread(void*);

class Cyberhawk : public SimpleRobot {
	GenericController<Joystick> sticks;
	Parser test;
	Thread hi;
public:
	Cyberhawk(void) : sticks(2, 0, 1),
					  test("file.txt"),
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

void* testThread(void *args) {
	printf("matlab");
	return 0;
}

/***************************************************************************/
/*                            DO NOT TOUCH THIS                            */
/* DO NOT TOUCH THIS */ START_ROBOT_CLASS(Cyberhawk); /* DO NOT TOUCH THIS */
/*                            DO NOT TOUCH THIS                            */
/***************************************************************************/
/*                                                                         */
/*          !!! END OF FILE, DO NOT PUT ANYTHING BELOW THIS !!!            */
/*                                                                         */
/***************************************************************************/
