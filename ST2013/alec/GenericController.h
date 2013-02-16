/* 
 * QUICK NOTE:
 * Objects used in GenericController can
 * not have a constructor that takes
 * more than one argument.
 * 
 * The compiler will error if this is
 * the case, so don't worry too much
 * about undefined behaviour.
 *
 * Use GenericController2Arg for two arguments
 */

#ifndef PENNE
#define PENNE

#include "WPILib.h"
#include <stdarg.h>

template <class T>  //generic class T
class GenericController {  //handles many objects in an array of the same type
	T **objects;  //makes array of objects
	int count;  //number of arguments
public:
	GenericController(){};  //does nothing
	GenericController(int, ...);  //constructs controller -- number of objects, arguments for the objects
	
	~GenericController();  //deconstructor

	void initController(int, ...);  //same as constructor
	
	int getCount() const;  //get number of objects
	T* getObject(int) const;  //get an object
	T* operator[](int) const;  //same as getObject
};

template <class T>
class GenericController2Arg {  //same as GenericController only with 2 args
	T **objects;
	int count;
public:
	GenericController2Arg(){};
	GenericController2Arg(int, ...);  //number of objects, give arguments 1.1, 1.2, 2.1, 2.2, etc
	
	//same as above
	
	~GenericController2Arg();

	void initController(int, ...);
	
	int getCount() const;
	T* getObject(int) const;
	T* operator[](int) const;
};

#endif
