

#ifndef BLANK_H
#define BLANK_H


#include "Commands/Subsystem.h"
#include "../Robot.h"

class Blank: public Command {
public:
	Blank();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
