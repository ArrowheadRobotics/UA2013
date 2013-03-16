

#ifndef AUTONOMOUS_COMMAND_H
#define AUTONOMOUS_COMMAND_H

#include "ForkLiftDefault.h"
#include "ConveyorUp.h"
#include "Commands/Command.h"
#include "Commands/Subsystem.h"
#include "../Robot.h"

class AutonomousCommand: public Command {
public:
	Command* fk;
	Command* cu;
	AutonomousCommand();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
