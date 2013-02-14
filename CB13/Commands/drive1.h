

#ifndef DRIVE1_H
#define DRIVE1_H


#include "Commands/Subsystem.h"
#include "../Robot.h"

/**
 *
 *
 * @author ExampleAuthor
 */
class drive1: public Command {
private:
	virtual void accelerate(float spd, float dist);
	
public:
	drive1();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
