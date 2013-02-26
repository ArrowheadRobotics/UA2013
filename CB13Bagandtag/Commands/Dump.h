

#ifndef DUMP_H
#define DUMP_H


#include "Commands/Subsystem.h"
#include "../Robot.h"

class Dump: public Command {
public:
	Dump();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
