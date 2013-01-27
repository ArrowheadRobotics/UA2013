#include "Threading.h"

Thread::Thread(void*(*funcPointer)(void*), bool spawn, void *args) {  //inizilazation call
	handle = 0;  //clears pointer ID
	this->initThread(funcPointer, spawn, args);  //runs thread initilization
}

void Thread::initThread(void*(*funcPointer)(void*), bool spawn, void *args) {  //initilizes thread
	this->funcPointer = funcPointer;  //sets thread function
	if(spawn) this->spawnThread(args);  //if spwan=true runs thread spawning
}

void Thread::setFunction(void*(*funcPointer)(void*)) {  //sets thread function
	this->funcPointer = funcPointer;  //sets thread function
}

int Thread::spawnThread(void *args, bool force) {  //spawns new thread if it doesn't exist or force=true
	//the handle!=0 makes it so that each instance of the thread class can only ever run one thread -- i dont thint you should have it
	//TODO verify stability
	if(handle!=0 || (checkThread() && !force)) return -1; //if the thread exists and you aren't forcing it return -1
	return pthread_create(&handle, NULL, funcPointer, args);  //creates a new thread running funcPointer with arugments args, sets handle to the thread ID, and returns 0
}

void Thread::waitForThread() {  //waits for thread
	//the if is redundant -- the pthread_join will exit immediatly if the tread doesn't exist
	if(handle!=0) pthread_join(handle, NULL);  //if a thread has been created wait for it to die
}

bool Thread::checkThread() {  //check if the thread exists
	return pthread_kill(handle, 0)!=ESRCH;  //sends a signal to the thread named handle, if the thead doesn't exist it will reutrn ESRCH and the function will return false
}

void Thread::killThread() {  //murder the thread
	pthread_kill(handle, 9);  //sends a kill signal to the thread
}

pthread_t Thread::getHandle() const {  //returns the thread ID
	return handle;
}
