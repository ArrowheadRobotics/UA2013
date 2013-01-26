#include "ConstParser.h"

ConstParser::ConstParser(const char *filename) {
	count = 0;
	this->parseFromFile(filename);
}

std::map<std::string,float> ConstParser::getConstants() const {
	return consts;
}

/*
 * FORMAT:
 * 
 * name = value;
 * 
 * There can be an arbitrary amount of spacing around the equals sign.
 * There can be blank lines.
 * Names cannot have spaces.
 * Values will always be floats.
 * 
 * todo actually write this
 * 
 */

int ConstParser::parseFromFile(const char *filename) {
	ifstream fp;
	fp.open(filename, )
	
	return 0;
}
