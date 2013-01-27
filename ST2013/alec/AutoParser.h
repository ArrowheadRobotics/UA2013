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
	RobotCommand *cmds;  //parsed data
	int count;  //length of data
public:
	AutoParser(){};  //pointless
	AutoParser(const char*);  //initialization -- takes filename
	
	int parseFromFile(const char*);  //parsing function -- takes filename
	RobotCommand* getCommands() const;  //returns constant parsed data
	int getCount() const;  //returns constant length of data
};

#endif
