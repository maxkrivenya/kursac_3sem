#pragma once
#include "Exception.h"

class FileException :public Exception {
public:
	FileException(string text = "File open error, sorry");
	void show() override;
	void close(string s = "File close error");
};