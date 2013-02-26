

#ifndef CLIMBERUP_H
#define CLIMBERUP_H


#include "Commands/Subsystem.h"
#include "../Robot.h"

class ClimberUp: public Command {
public:
	ClimberUp();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
