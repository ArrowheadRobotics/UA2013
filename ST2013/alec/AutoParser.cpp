#include "AutoParser.h"

AutoParser::AutoParser(const char *filename) {
	cmds = NULL;
	count = 0;
	this->parseFromFile(filename);
}

RobotCommand* AutoParser::getCommands() const {
	return cmds;
}

int AutoParser::getCount() const {
	return count;
}

int AutoParser::parseFromFile(const char *filename) {
	FILE *fp = NULL;
	if((fp = fopen(filename, "rb")) == NULL) return -1;  //open file
	
	fseek(fp, 0, SEEK_END);  //find end of file
	int length = ftell(fp);  //set length fo file
	rewind(fp);  //start at beginning of file again
	
	char *buf = (char*)malloc(length);  //define new buffer to dump file into
	fread(buf, 1, length, fp);  //dump file into buffer
	fclose(fp);  //close file
	
	for(int i = 0; i <= length; i++)
		count += (buf[i]==',')?1:0;  //count delimiters
	count /= 3;  //devide by three because data comes in clumps of three
	//The counter assumes that the file starts or ends with a comma
	
	cmds = (RobotCommand*)malloc((count) * sizeof(RobotCommand));  //group of data sets we will output to
	
	for(int i = 0; i < count; i++) {
		cmds[i].v1 = atof(strtok(((i==0)?buf:NULL), ","));  //convert first string into double
		cmds[i].v2 = atof(strtok(NULL, ","));  //convert second string into double
		cmds[i].type = atoi(strtok(NULL, ","));  //convert third sting into int
	}
	
	return 0;
}
