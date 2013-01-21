/*
 * This class (Cyberhawk) is the entry point of the robot.
 * 
 * todo fix everything
 * 
 */

/***************************************************************************/
/*                   DO NOT EDIT ANYTHING IN THIS FILE!                    */
/***************************************************************************/

#ifndef ROBOTH
#define ROBOTH

#include "WPILib.h"

class Cyberhawk : public SimpleRobot {
public:
	Cyberhawk(void) {};
	~Cyberhawk(void) {};
	
	void Autonomous(void);
	void OperatorControl(void);
};

class Delegator {
public:
	void RunAutonomous(Cyberhawk*);
	void RunTeleop(Cyberhawk*);
};


#endif
