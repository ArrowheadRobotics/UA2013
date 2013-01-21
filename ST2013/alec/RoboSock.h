/*
 * TCP Socket functionality for intersystemic communication.
 * 
 * TODO Stress test this to hell.
 */

#ifndef SOCKSH
#define SOCKSH

#include "stdio.h" // standard i/o
#include "stdlib.h" // standard functions
#include "arpa/inet.h" // inet functions
#include "netinet/in.h" // inet functions
#include "sys/types.h" // socket types
#include "sys/socket.h" // core socket functions
#include "netdb.h" // error ids for network functions
#include "errno.h" // error handling for network functions
#include "ioctl.h" // (non)blocking functionality

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

RoboSock::RoboSock(char *ip, int port, bool blocking, bool conn) {
	sock = 0;
	initConnection(ip, port, blocking, conn);
}

int RoboSock::initConnection(char *ip, int port, bool blocking, bool conn) {
	sock = socket(AF_INET, SOCK_STREAM, 0);
	if(sock <= 0) return -1;
	
	memset((char*)&addr, 0, sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = inet_addr(ip);
	addr.sin_port = htons(port);
	
	//fcntl(sock, (blocking)?O_BLOCK:O_NONBLOCK); // TODO fix this
	
	return 0;
}

#endif
