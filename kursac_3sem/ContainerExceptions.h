#pragma once
#include "Exception.h"

class ContainerException : public Exception	
{
public:
	ContainerException(string text = "Container is empty, oopsie");
	void show() override;	
};

