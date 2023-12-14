#pragma once
#include "Exception.h"

class ContainerException : public Exception	// класс исключений в контейнере
{
public:
	ContainerException(string text = "Container is empty, try again");	// исключение в контейнере
	void Show() override;	// вывод
};

