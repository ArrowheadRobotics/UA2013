

#ifndef FORKLIFTDEFAULT_H
#define FORKLIFTDEFAULT_H


#include "Commands/Subsystem.h"
#include "../Robot.h"

class ForkLiftDefault: public Command {
public:
	ForkLiftDefault();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
	
};

#endif
