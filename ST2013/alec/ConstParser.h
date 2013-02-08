#ifndef BOGATTI
#define BOGATTI

#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <string.h>
#include <string>
#include <map>

class ConstParser {
	std::map<std::string,float> consts;  //makes new map that holds two elements, a string and a float
	int count;  //counter
public:
	ConstParser(){};  //does nothing
	ConstParser(const char*);  //initilization
	
	int parseFromFile(const char*);  //parse form file -- returns 0
	std::map<std::string,float> getConstants() const;  //returns ouput
};

#endif
