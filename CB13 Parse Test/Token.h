//TOKENIZER

#ifndef _TOKEN_H
#define _TOKEN_H

#include "WPILib.h"
#include "Commands/Command.h"
#include "RobotMap.h"
#include "LiveWindow/LiveWindow.h"
#include "Commands/AutonomousCommand.h"
#include "OI.h"
#include <String>

struct Pair {
	char *	name;
	float value;
};

class Token {

public:

	int parse(const char*, Pair**);
};
#endif
