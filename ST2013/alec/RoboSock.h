/*
 * TCP Socket functionality for intersystemic communication.
 * 
 * TODO Stress test this to hell.
 */

#ifndef TORTELLINI
#define TORTELLINI

#include "WPILib.h"
#include "stdio.h" // standard i/o
#include "arpa/inet.h" // inet functions
#include "netinet/in.h" // inet functions
#include "stdio.h" // standard i/o (again)
#include "sys/types.h" // socket types
#include "sys/socket.h" // core socket functions
#include "netinet/in.h" // inet functions (again)
#include "netdb.h" // error ids for network functions
#include "errno.h" // error handling for network functions
#include "pthread.h" // POSIX threading
#include "ioctl.h"

class RoboSock {
	int sock, port, error;
	struct sockaddr_in addr;
public:
	RoboSock(){sock=0;};
	// ip, port, blocking, connect on creation
	RoboSock(char*, int, bool=true, bool=false);

	// ip, port, blocking, connect on call
	int initConnection(char*, int, bool=true, bool=false);
	int connectToServer();
	int disconnectFromServer();

	int Send(const char*) const;
	const char* Get() const;
	
	void setBlocking(bool);
	int getError() const;
};

#endif
