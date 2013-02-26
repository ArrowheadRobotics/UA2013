#ifndef CLIMBERMOVERELEASE_H
#define CLIMBERMOVEREKEASE_H


#include "Commands/Subsystem.h"
#include "../Robot.h"

/**
 *
 *
 * @author ExampleAuthor
 */
class ClimberRelease: public Command {
public:
	ClimberRelease();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
