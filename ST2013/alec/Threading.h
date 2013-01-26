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

#endif
