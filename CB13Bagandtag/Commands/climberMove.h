#ifndef CLIMBERMOVE_H
#define CLIMBERMOVE_H


#include "Commands/Subsystem.h"
#include "../Robot.h"

/**
 *
 *
 * @author ExampleAuthor
 */
class ClimberMove: public Command {
public:
	ClimberMove();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
