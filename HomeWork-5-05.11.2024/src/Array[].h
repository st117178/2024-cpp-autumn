#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>

template<class T>
class Array
{
	T array[7];
public:
	Array() : array(nullptr) {};
	Array(T* b);
	void show();
	T minimum(Array<T>& m);
};

#include "Array_header.h"

#endif