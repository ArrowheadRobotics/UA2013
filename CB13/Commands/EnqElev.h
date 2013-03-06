

#ifndef ENQELEV_H
#define ENQELEV_H


#include "Commands/Subsystem.h"
#include "../Robot.h"

class EnqElev: public Command {
public:
	EnqElev();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
