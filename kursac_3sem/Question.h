#pragma once
#include "stroki.h"
class Question {
	friend class Test;
public:
	Question(str data) {
		this->data = data;
	}
	~Question() {};
	void sout();
	friend ostream& operator<<(ostream& os, Question& q);
protected:
	str data;
};


class q_mbti : public Question {
	friend class User;
	int type;
public:
	q_mbti(int type = 0, str data = {1, "\n"}) :Question(data) {
		//this->data = data;
		this->type = type;
	}
	~q_mbti() {};
};