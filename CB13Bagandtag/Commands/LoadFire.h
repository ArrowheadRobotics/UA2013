

#ifndef LOADFIRE_H
#define LOADFIRE_H


#include "Commands/Subsystem.h"
#include "../Robot.h"

class LoadFire: public Command {
public:
	LoadFire();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
	
};

#endif
