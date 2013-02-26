#ifndef FRISBEETOGGLE_H
#define FRISBEETOGGLE_H


#include "Commands/Subsystem.h"
#include "../Robot.h"

/**
 *
 *
 * @author ExampleAuthor
 */
class FrisbeeToggle: public Command {
public:
	FrisbeeToggle();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
