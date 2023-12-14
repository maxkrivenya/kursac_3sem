#pragma once
#include <iostream>
using namespace std;

class Exception	
{
protected:
	string message;
public:
	virtual void show() = 0;
};