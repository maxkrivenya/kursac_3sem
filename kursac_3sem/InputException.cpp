#include "InputException.h"

InputException::InputException(string text)	// исключения при вводе
{
	this->message = text;
}

void InputException::Show()	// вывод
{
	cout << endl << message << endl;
}