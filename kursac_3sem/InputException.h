#pragma once
#include "Exception.h"

class InputException : public Exception 
{
public:
	InputException(string text = "Input error, try again");
	void show() override;	
};