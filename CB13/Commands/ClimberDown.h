

#ifndef CLIMBERDOWN_H
#define CLIMBERDOWN_H


#include "Commands/Subsystem.h"
#include "../Robot.h"

class ClimberDown: public Command {
public:
	ClimberDown();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
