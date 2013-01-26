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

int Token::parse(const char* fname, const char* token[1000][20]) {


	  // create a file-reading object
	  ifstream fin;
	  fin.open(fname); // open a file														
	  if (!fin.good()){
		  for(;;){
	    
		  }
		  return 1; // exit if file not found
	  }
	  // read each line of the file
	  int idx = 0;
	  while (!fin.eof())
	  {
	    // read an entire line into memory
	    char buf[MAX_CHARS_PER_LINE];
	    fin.getline(buf, MAX_CHARS_PER_LINE);
	    
	    // parse the line into blank-delimited tokens
	    int n = 0; // a for-loop index
	    
	    // array to store memory addresses of the tokens in buf
	   
	    
	    // parse the line
	    token[idx][0] = strtok(buf, DELIMITER); // first token
	    if (token[idx][0]) // zero if line is blank
	    {
	      for (n = 1; n < MAX_TOKENS_PER_LINE; n++)
	      {
	        token[idx][n] = strtok(0, DELIMITER); // subsequent tokens
	        if (!token[idx][n]) break; // no more tokens
	      }
	    }

	    // process (print) the tokens
//	    for (int i = 0; i < n; i++) // n = #of tokens
//	      cout << "Token[" << idx << ","<<i<<"] = " << token[idx][i] << endl;
//	    cout << endl;
	  idx++;
	  }
	return 0;
}
