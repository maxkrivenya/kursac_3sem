#pragma once
#include "stroki.h"
class Question {
	friend class Test;
public:
	Question(str data) {
		this->data = data;
	}
	~Question() {};
	void sout() {
		std::cout << std::endl << this->data << std::endl;
	}
	friend ostream& operator<<(ostream& os, Question& q) {
		os << '\n' << q.data << '\n';
		return os;
	}
protected:
	str data;
};


class q_mbti : public Question {
	int type;
public:
	q_mbti(int type = 0, str data = {1, "\n"}) :Question(data) {
		//this->data = data;
		this->type = type;
	}
	~q_mbti() {};
};