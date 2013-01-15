/*
 * A brief introduction to POSIX Threading:
 * It's bad.
 * 
 * To pass arguments to the function, create a
 * structure with the necessary parameters, set
 * them, and typecast it to (void*) when you
 * spawn the thread. If you do not specify an
 * argument, a null pointer will be passed in
 * its place.
 * 
 * The boolean argument in the constructor and
 * initThread determine if the thread should be
 * launched when the object is done initializing.
 * 
 * This class is intended to handle a single
 * thread at a time. spawnThread defaults to
 * checking if the spawned thread exists, and
 * returns an error if this is so. To force
 * spawning (NOT RECOMMENDED), pass true for 
 * the second argument.
 * 
 * Also: heed warning below.
 */

#ifndef THREADINGH
#define THREADINGH

#include <pthread.h>

class Thread {
	pthread_t handle;
	void*(*funcPointer)(void*);
public:
	Thread(){handle = 0;};
	Thread(void*(*)(void*), bool=false, void(*)=NULL);
	
	void initThread(void*(*)(void*), bool=false, void(*)=NULL);
	void setFunction(void*(*)(void*));
	
	int stupid() { return 4; }
	
	int spawnThread(void(*)=NULL, bool=false);
	void waitForThread();
	bool checkThread();
	/*
	 *   ###################
	 *   #~~~~~~~~~~~~~~~~~#
	 *   #~~             ~~#
	 *   #~   WARNING!!   ~#
	 *   #~~             ~~#
	 *   #~~~~~~~~~~~~~~~~~#
	 *   ###################
	 * 
	 * 	 Only use killThread 
	 * 	 in extreme situations.
	 * 	 Can result in undefined
	 * 	 and inconsistent
	 * 	 behaviour.
	 * 	 
	 * 	 This kills the developer.
	 */
	void killThread();
	
	pthread_t getHandle() const;
};

Thread::Thread(void*(*funcPointer)(void*), bool spawn, void *args) {
	handle = 0;
	this->initThread(funcPointer, spawn, args);
}

void Thread::initThread(void*(*funcPointer)(void*), bool spawn, void *args) {
	this->funcPointer = funcPointer;
	if(spawn) this->spawnThread(args);
}

void Thread::setFunction(void*(*funcPointer)(void*)) {
	this->funcPointer = funcPointer;
}

int Thread::spawnThread(void *args, bool force) {
	if(handle==0 || (checkThread() && !force)) return -1; // TODO verify stability
	return pthread_create(&handle, NULL, funcPointer, args);
}

void Thread::waitForThread() {
	if(handle!=0) pthread_join(handle, NULL);
}

bool Thread::checkThread() {
	return pthread_kill(handle, 0)!=ESRCH;
}

void Thread::killThread() {
	pthread_kill(handle, 9);
}

pthread_t Thread::getHandle() const {
	return handle;
}

#endif
