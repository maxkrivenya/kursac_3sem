#pragma once
#include "Question.h"

class qMbti : public Question {
	friend class User;
protected:
	int type;
public:
	qMbti(int type = 1, string data = "Hello World!") :Question(data) {
		this->type = type;
	}
	~qMbti() {};
	friend istream& operator>>(istream& is, qMbti& q);
	int getType();
	void setType(int newType);
};