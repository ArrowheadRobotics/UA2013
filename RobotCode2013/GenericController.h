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

#ifndef GENERICCONTROLLERH
#define GENERICCONTROLLERH

#include "WPILib.h"
#include <stdarg.h>

template <class T>
class GenericController {
	T **objects;
	int count;
public:
	GenericController(){};
	GenericController(int, int, ...);

	void initController(int, int, ...);
	
	int getCount() const;
	T* getObject(int) const;
	T* operator[](int) const;
};

template <class T>
GenericController<T>::GenericController(int count, int arg1, ...) {
	objects = (T**)calloc(count,sizeof(T));
	this->count = count;
	
	va_list args;
	va_start(args, arg1);
	
	for(int i = 0; i < count; i++)
		objects[i] = new T(va_arg(args,int));
	
	va_end(args);
}

template <class T>
void GenericController<T>::initController(int count, int arg1, ...) {
	objects = (T**)calloc(count,sizeof(T));
	this->count = count;
	
	va_list args;
	va_start(args, arg1);

	for(int i = 0; i < count; i++)
		objects[i] = new T(va_arg(args,int));
	
	va_end(args);
}

template <class T>
int GenericController<T>::getCount() const {
	return count;
}

template <class T>
T* GenericController<T>::getObject(int index) const {
	return objects[index];
}

template <class T>
T* GenericController<T>::operator[](int index) const {
	return objects[index];
}

#endif
