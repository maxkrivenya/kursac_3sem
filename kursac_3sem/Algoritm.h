#pragma once
#include "Containers.h"
#include "AllExceptions.h"
#include "QDriver.h"
#include "qSport.h"

class Algoritm {
public:
	Algoritm() {};
	~Algoritm() {};

	template <class T>
	List<T> TestInit(const char* filename);

	Tree<qDriver> DriverTestInit();

};