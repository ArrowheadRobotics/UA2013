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
	
	int opts = fcntl(sock, F_GETFL);
	opts = (blocking)? opts|O_NONBLOCK : opts&(~O_NONBLOCK);
	fcntl(sock, F_SETFL, opts);
	
	return 0;
}

int RoboSock::connectToServer() {
	if(sock <= 0) return 0xDEAD;
	return (error = connect(sock, (struct sockaddr*)&addr, sizeof(addr)));
}

int RoboSock::disconnectFromServer() {
	if(sock <= 0) return 0xDEAD;
	return shutdown(sock, SHUT_RDWR);
}

void RoboSock::setBlocking(bool blocking) {
	int opts = fcntl(sock, F_GETFL);
	opts = (blocking)? opts|O_NONBLOCK : opts&(~O_NONBLOCK);
	fcntl(sock, F_SETFL, opts);
}

int RoboSock::getError() const {
	return error;
}

int RoboSock::Send(const char *msg) {
	return (error = send(sock, msg, sizeof(msg), 0));
}

/*
 * If you're using nonblocking and you need to check
 * if EAGAIN was returned by Get, call GetError to
 * check the most recent error.
 */
const char* RoboSock::Get() {
	char *msg;
	error = recv(sock, msg, 512, 0);
	return msg;
}
