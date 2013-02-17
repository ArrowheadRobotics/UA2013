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

#ifndef RIGATONI  //pasta
#define RIGATONI

#include <pthread.h>

class Thread {
	pthread_t handle;  //thread ID
	void*(*funcPointer)(void*);  // function pointer for a function that takes and returns a void pointer
public:
	Thread(){handle = 0;};  //pointless
	//Arguments -- function for new thread (funcPointer), spawn thread immediatly, argumets for thread
	Thread(void*(*)(void*), bool=false, void(*)=NULL);  //clears handel and initilizes thread
	
	//Arugments -- same as above
	void initThread(void*(*)(void*), bool=false, void(*)=NULL);  //sets funcPointer and spawns thread if bool = true
	void setFunction(void*(*)(void*));  //sets funcPointer
	
	int spawnThread(void(*)=NULL, bool=false);  //make new thread if it doesnt exist -- takes arguments for thread and force boolean
	//if force is true then the tread will create a new tread regardless of if it already exists
	//returns 0 if it succeeds and -1 if it fails
	void waitForThread();  //function waits until the current tread is done, if it doesnt exist it exits immediatly
	bool checkThread();  //returns true if the thread exists, false if it doesn't
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
	void killThread();  //violently murders the tread in cold blood
	
	pthread_t getHandle() const;  //get current thread ID
};

#endif
