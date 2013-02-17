

#ifndef CONVEYORUP_H
#define CONVEYORUP_H


#include "Commands/Subsystem.h"
#include "../Robot.h"

class ConveyorUp: public Command {
public:
	ConveyorUp();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
