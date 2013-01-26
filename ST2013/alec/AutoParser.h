/*
 * Parser class:
 * 
 * Parses autonomous functions read from file that
 * exists within the cRIO's filesystem. 
 * 
 * TODO Check to see if filesystem clears on reboot.
 */

#ifndef MASTACHOLI
#define MASTACHOLI

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct RobotCommand {  //one set of data
	double v1, v2;
	int type;
};

class AutoParser {
	RobotCommand *cmds;
	int count;
public:
	AutoParser(){};
	AutoParser(const char*);
	
	int parseFromFile(const char*);
	RobotCommand* getCommands() const;
	int getCount() const;
};

#endif
