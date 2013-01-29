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
	consts.clear();
	
	FILE *fp = fopen(filename, "rb");
		
	fseek(fp, 0, SEEK_END);
	int length = ftell(fp);
	rewind(fp);
		
	char *buf = new char[length];
	
	int i = 0;
	for(; !feof(fp); i++) {
		char in = fgetc(fp);
		if(in > ' ') buf[i] = in;
		else i--;
	}
	buf[i] = 0;
	
	fclose(fp);

	bool state = 0; // 0 = key ; 1 = value
	char *buf2 = strtok(buf, "=;"), *key;
	
	do {
		if(!state) key = buf2;
		else consts[key] = atof(buf2);
			
		state = !state;
	} while((buf2 = strtok(NULL, "=;")) != NULL);
	
	delete buf, buf2, key;
	
	return 0;
}
