/* 
 * QUICK NOTE:
 * Objects used in this controller can
 * not have a constructor that takes
 * more than one argument.
 * 
 * The compiler will error if this is
 * the case, so don't worry too much
 * about undefined behaviour.
 */

#ifndef PENNE
#define PENNE

#include "WPILib.h"
#include <stdarg.h>

template <class T>
class GenericController {
	T **objects;
	int count;
public:
	GenericController(){};
	GenericController(int, ...);
	
	~GenericController();

	void initController(int, ...);
	
	int getCount() const;
	T* getObject(int) const;
	T* operator[](int) const;
};

#endif
