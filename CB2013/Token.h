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


class Token {
public:
	int parse(const char*, const char*[1000][20]);
};
#endif
