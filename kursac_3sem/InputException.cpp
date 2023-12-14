#include "InputException.h"

InputException::InputException(string text)
{
	this->message = text;
}

void InputException::show()
{
	cout << endl << message << endl;
}