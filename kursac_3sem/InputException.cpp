#include "InputException.h"

InputException::InputException(string text)	// ���������� ��� �����
{
	this->message = text;
}

void InputException::Show()	// �����
{
	cout << endl << message << endl;
}