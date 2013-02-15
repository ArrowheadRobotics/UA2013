#ifndef CLIMBERTOGGLE_H
#define CLIMBERTOGGLE_H


#include "Commands/Subsystem.h"
#include "../Robot.h"

/**
 *
 *
 * @author ExampleAuthor
 */
class climberToggle: public Command {
public:
	climberToggle();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
