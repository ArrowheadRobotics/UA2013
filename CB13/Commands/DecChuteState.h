

#ifndef DECCHUTE_H
#define DECHUTE_H


#include "Commands/Subsystem.h"
#include "../Robot.h"

class DecChuteState: public Command {
public:
	DecChuteState();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
