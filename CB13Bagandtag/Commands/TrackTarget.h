#ifndef TRACKTARGET_H
#define TRACKTARGET_H

#include "../Robot.h"

class TrackTarget: public Command {
public:
	TrackTarget();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	double height;
	virtual void Interrupted();
};

#endif
