#pragma once
#include "Exception.h"

class ContainerException : public Exception	// ����� ���������� � ����������
{
public:
	ContainerException(string text = "Container is empty, try again");	// ���������� � ����������
	void Show() override;	// �����
};

