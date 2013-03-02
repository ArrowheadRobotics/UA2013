#ifndef MOVE_DN_H
#define MOVE_DN_H


#include "Commands/Subsystem.h"
#include "../Robot.h"


class move_dn: public Command {
public:
	Timer* t;
	move_dn();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
