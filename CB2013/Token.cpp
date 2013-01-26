#include "Token.h"

#define ever() for(;;)

#include <iostream>
#include <String>

#include <fstream>
using std::ifstream;

#include <cstring>

const int MAX_CHARS_PER_LINE = 512;
const int MAX_TOKENS_PER_LINE = 20;
const int MAX_LINES_PER_FILE = 1000;
const char* const DELIMITER = " ";


int Token::parse(const char* fname, Pair** f) {

	// create a file-reading object
	ifstream fin;
	fin.open(fname); // open a file
	if (!fin.good()) {
		for (;;) {

		}
		return 1; // exit if file not found
	}
	// read each line of the file
	int idx = 0;
	while (!fin.eof()) {
		// read an entire line into memory
		char buf[MAX_CHARS_PER_LINE];
		fin.getline(buf, MAX_CHARS_PER_LINE);

		// parse the line into blank-delimited tokens
		int n = 0; // a for-loop index

		// array to store memory addresses of the tokens in buf

try{
		// parse the line
		f[idx]->name = strtok(buf, DELIMITER); // first token
		if (f[idx]->name) // zero if line is blank
		{
			
				f[idx]->value = atof(strtok(0, DELIMITER)); // subsequent tokens

//				if (!token[idx][n])  //Do we need this?
//					break; // no more tokens

			
		}
		
		
		printf("String: %s ", f[idx]->name);
		printf("Data: %f\n", f[idx]->value);
}
catch(...){
	printf("There was issue!");
}
		idx++;
	}
	return 0;
}
