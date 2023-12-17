#pragma once
#include "Question.h"

class qMbti : public virtual Question {
	friend class User;
protected:
	int type;
public:
	qMbti(int type = 1, string data = ""):Question(data) {
		this->type = type;
		this->data = data;
	}
	~qMbti() {};
	friend istream& operator>>(istream& is, qMbti& q);
	int getType();
	void setType(int newType);
};