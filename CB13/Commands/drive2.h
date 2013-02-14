#ifndef DRIVE2_H
#define DRIVE2_H


#include "Commands/Subsystem.h"
#include "../Robot.h"

class drive2: public Command {
private:
	virtual void accelerate(float spd, float dist);
public:
	drive2();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
