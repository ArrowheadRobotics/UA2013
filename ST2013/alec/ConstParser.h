#ifndef BOGATTI
#define BOGATTI

#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <string.h>
#include <string>
#include <map>

class ConstParser {
	std::map<std::string,float> consts;
	int count;
public:
	ConstParser(){};
	ConstParser(const char*);
	
	int parseFromFile(const char*);
	std::map<std::string,float> getConstants() const;
};

#endif
