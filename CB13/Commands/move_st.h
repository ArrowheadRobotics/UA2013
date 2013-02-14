#ifndef MOVE_ST_H
#define MOVE_ST_H


#include "Commands/Subsystem.h"
#include "../Robot.h"

class move_st: public Command {
public:
	move_st();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
