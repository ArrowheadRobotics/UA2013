#ifndef FETUCCINI
#define FETUCCINI

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

class ErrorContext {
	FILE *fp;
public:
	ErrorContext(){};
	ErrorContext(char*);
	void openContext(char*);
	
	void write(char*,bool=true);
	
	~ErrorContext();
};

#endif
