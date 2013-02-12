/*
 * TCP Socket functionality for intersystemic communication.
 * 
 * TODO Stress test this to hell.
 * TODO See if we're using this at all.
 */

#ifndef TORTELLINI
#define TORTELLINI

#include "WPILib.h"
#include "stdio.h" // standard i/o
#include "arpa/inet.h" // inet functions
#include "netinet/in.h" // inet functions
#include "sys/types.h" // socket types
#include "sys/socket.h" // core socket functions
#include "netdb.h" // error ids for network functions
#include "errno.h" // error handling for network functions
#include "ioctl.h"  //input output flag stuff

class RoboSock {  //socket connection
	int sock, port, error;  //socket ID, port #, most recent error
	struct sockaddr_in addr; //server info
public:
	RoboSock(){sock=0;};  //shit
	// ip, port, blocking, connect on creation
	RoboSock(char*, int, bool=true, bool=false);  //init

	// ip, port, blocking, connect on call
	int initConnection(char*, int, bool=true, bool=false);  //init#2 -- returns error
	int connectToServer();  //returns error
	int disconnectFromServer();  //returns error

	int Send(const char*);  //return error
	const char* Get();  //get info from other server
	
	void setBlocking(bool);
	int getError() const;
};

#endif
