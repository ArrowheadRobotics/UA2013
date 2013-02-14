#ifndef STOP_H
#define STOP_H


#include "Commands/Subsystem.h"
#include "../Robot.h"

class stop: public Command {
public:
	stop();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
