#include "ConstParser.h"

ConstParser::ConstParser(const char *filename) {  //initilization
	count = 0;  //reset shit
	this->parseFromFile(filename);  //parse file immediatly
}

std::map<std::string,float> ConstParser::getConstants() const {  //return ouput
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
	consts.clear();  //clear output
	
	FILE *fp = fopen(filename, "rb");  //open file
		
	fseek(fp, 0, SEEK_END);  //go to the end of the file
	int length = ftell(fp);  //get the length of the file
	rewind(fp);  //go back to the beginning
		
	char *buf = new char[length];  //create temporary buffer storage
	
	int i = 0;
	for(; !feof(fp); i++) {  //while still in the file
		char in = fgetc(fp);  //get the character
		if(in > ' ') buf[i] = in;  //actual character
		else i--;  //dont count spaces
	}
	buf[i] = 0;
	
	fclose(fp);  //close file

	bool state = 0; // 0 = key ; 1 = value
	char *buf2 = strtok(buf, "=;"), *key;  //buf2 holds temporary characters, key
	
	do {
		if(!state) key = buf2;  //if stete = 0 set the name of the variable
		else consts[key] = atof(buf2);  //get the value as a float
			
		state = !state;  //inverte state
	} while((buf2 = strtok(NULL, "=;")) != NULL);  //while the next character is not null
	
	delete buf, buf2, key;  //delete temporary stuff
	
	return 0;  //return 0;
}
