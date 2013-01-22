/*
 * Parser class:
 * 
 * Parses autonomous functions read from file that
 * exists within the cRIO's filesystem. 
 * 
 * TODO Check to see if filesystem clears on reboot.
 */

#pragma once

#include <stdio.h>
#include <stdlib.h>

struct RobotCommand {
	double v1, v2;
	int type;
};

class Parser {
	RobotCommand *cmds;
	int count;
public:
	Parser(){cmds = NULL;count=0;};
	Parser(const char*);
	
	int parseFromFile(const char*);
	RobotCommand* getCommands() const;
	int getCount() const;
};

Parser::Parser(const char *filename) {
	cmds = NULL;
	count=0;
	this->parseFromFile(filename);
}

RobotCommand* Parser::getCommands() const {
	return cmds;
}

int Parser::getCount() const {
	return count;
}

int Parser::parseFromFile(const char *filename) {
	FILE *fp = NULL;
	if((fp = fopen(filename, "rb")) == NULL) return -1;
	
	fseek(fp, 0, SEEK_END);
	int length = ftell(fp);
	rewind(fp);
	
	char *buf = (char*)malloc(length);
	fread(buf, 1, length, fp);
	fclose(fp);
	
	for(int i = 0; i <= length; i++)
		count += (buf[i]==',')?1:0;
	count /= 3;
	
	cmds = (RobotCommand*)malloc((count) * sizeof(RobotCommand));
	
	for(int i = 0; i < count; i++) {
		cmds[i].v1 = atof(strtok(((i==0)?buf:NULL), ","));
		cmds[i].v2 = atof(strtok(NULL, ","));
		cmds[i].type = atoi(strtok(NULL, ","));
	}
	
	return 0;
}
