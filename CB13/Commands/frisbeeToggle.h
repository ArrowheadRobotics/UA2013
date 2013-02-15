#ifndef FRISBEETOGGLE_H
#define FRISBEETOGGLE_H


#include "Commands/Subsystem.h"
#include "../Robot.h"

/**
 *
 *
 * @author ExampleAuthor
 */
class frisbeeToggle: public Command {
public:
	frisbeeToggle();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
