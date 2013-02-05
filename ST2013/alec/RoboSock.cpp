#include "RoboSock.h"

RoboSock::RoboSock(char *ip, int port, bool blocking, bool conn) {  //initializtion
	sock = 0;  //socket ID
	initConnection(ip, port, blocking, conn);  //next function
}

int RoboSock::initConnection(char *ip, int port, bool blocking, bool conn) {  //initialization #2 -- returns 0 if it worked and -1 if it failed
	sock = socket(AF_INET, SOCK_STREAM, 0);  //create socket that connect through the intranet and uses a TCP connection
	if(sock <= 0) return -1;  //if the socket wasn't created return -1
	
	memset((char*)&addr, 0, sizeof(addr));  //empties a space in memory for addr
	addr.sin_family = AF_INET;  //uses INET protocol meaning its not 20+ years old
	addr.sin_addr.s_addr = inet_addr(ip);  //set ip adress as long, second function traslates char into long
	addr.sin_port = htons(port);  //sets port in host byte order
	
	int opts = fcntl(sock, F_GETFL);  //gets socket parameters aka flags
	//if blocking is false then set O_NONBLOCK to true otherwise set to false
	//O_NONBLOCK points to the bit in the flag byte eg.  00010000  (~ bitwise not)
	opts = (!blocking)? opts|O_NONBLOCK : opts&(~O_NONBLOCK);
	fcntl(sock, F_SETFL, opts);  //sets socket flags
	
	return 0;
}

int RoboSock::connectToServer() {  //return error upon trying to connect or 0xDEAD if the socket is imaginary/complex/undefined
	if(sock <= 0) return 0xDEAD;  //if it doesnt exist DIE
	return (error = connect(sock, (struct sockaddr*)&addr, sizeof(addr)));  //returns and sets error value upon attempting to connect addr with socket  no one knows why we need the sizeof(addr) argument to be passeed into the funciton but alec says we need it to it must be so
}

int RoboSock::disconnectFromServer() {  //returns possible error upon shutodwn or 0xDEAD if you suck
	if(sock <= 0) return 0xDEAD;  //see above
	return shutdown(sock, SHUT_RDWR);  //KILL READING AND WRITING!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
}

void RoboSock::setBlocking(bool blocking) {
	int opts = fcntl(sock, F_GETFL);  //see initConnection(...)
	opts = (!blocking)? opts|O_NONBLOCK : opts&(~O_NONBLOCK);
	fcntl(sock, F_SETFL, opts);
}

int RoboSock::getError() const {
	return error;
}

int RoboSock::Send(const char *msg) {
	return (error = send(sock, msg, sizeof(msg), 0));  //return error upon trying to send a msg
}

/*
 * If you're using nonblocking and you need to check
 * if EAGAIN was returned by Get, call GetError to
 * check the most recent error.
 */
const char* RoboSock::Get() {
	char *msg;
	error = recv(sock, msg, 512, 0);  //socket ID, storage location, max length, SHHHH
	return msg;  //end the world
}
