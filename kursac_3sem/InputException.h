#pragma once
#include "Exception.h"

class InputException : public Exception // класс исключений при вводе
{
public:
	InputException(string text = "Input error, try again");	// исключения при вводе
	void Show() override;	// вывод
};