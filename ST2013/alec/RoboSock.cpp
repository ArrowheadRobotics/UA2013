#include "RoboSock.h"

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
