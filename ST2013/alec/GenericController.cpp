#include "GenericController.h"

template <class T>
GenericController<T>::GenericController(int count, ...) {
	objects = new T*[count];
	this->count = count;
	
	va_list args;
	va_start(args, count);
	
	for(int i = 0; i < count; i++)
		objects[i] = new T(va_arg(args,int));
	
	va_end(args);
}

template <class T>
GenericController<T>::~GenericController() {
	for(int i = 0; i < count; i++) delete objects[i];
}

template <class T>
void GenericController<T>::initController(int count, ...) {
	objects = new T*[count];
	this->count = count;
	
	va_list args;
	va_start(args, count);

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
