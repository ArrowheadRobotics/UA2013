

#ifndef DRIVEDEADZONE_H
#define DRIVEDEADZONE_H


#include "Commands/Subsystem.h"
#include "../Robot.h"

class DriveDeadZone: public Command {
public:
	DriveDeadZone();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
