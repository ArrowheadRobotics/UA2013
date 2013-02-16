

#ifndef CONVEYOR_H
#define CONVEYOR_H


#include "Commands/Subsystem.h"
#include "../Robot.h"

class ConveyorDefault: public Command {
public:
	ConveyorDefault();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
