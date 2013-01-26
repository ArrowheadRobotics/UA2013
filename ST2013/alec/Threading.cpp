#include "Threading.h"

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
	if(handle!=0 || (checkThread() && !force)) return -1; // TODO verify stability
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
