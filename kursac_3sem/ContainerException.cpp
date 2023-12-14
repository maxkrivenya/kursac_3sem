#include "ContainerExceptions.h"

ContainerException::ContainerException(string text){
	this->message = text;
}

void ContainerException::show()
{
	cout << endl << message << endl;
}