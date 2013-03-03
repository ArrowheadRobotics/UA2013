

#ifndef INCCHUTE_H
#define INCHUTE_H


#include "Commands/Subsystem.h"
#include "../Robot.h"

class IncChuteState: public Command {
public:
	IncChuteState();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
