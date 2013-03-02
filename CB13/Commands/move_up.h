#ifndef MOVE_UP_H
#define MOVE_UP_H

#include "../Robot.h"

class move_up: public Command {
public:
	move_up();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
	Timer* t;
};

#endif
