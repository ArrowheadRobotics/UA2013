#ifndef CLIMBERTOGGLE_H
#define CLIMBERTOGGLE_H


#include "Commands/Subsystem.h"
#include "../Robot.h"

/**
 *
 *
 * @author ExampleAuthor
 */
class ClimberToggle: public Command {
public:
	ClimberToggle();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
