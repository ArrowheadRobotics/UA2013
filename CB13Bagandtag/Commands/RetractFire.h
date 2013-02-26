

#ifndef RETRACTFIRE_H
#define RETRACTFIRE_H


#include "Commands/Subsystem.h"
#include "../Robot.h"

class RetractFire: public Command {
public:
	RetractFire();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
	
};

#endif
