#include "ContainerExceptions.h"

ContainerException::ContainerException(string text)
{
	this->message = text;
}

void ContainerException::Show()
{
	cout << endl << message << endl;
}