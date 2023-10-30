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
	int answer;
};


class q_mbti : public Question {
	friend class User;
protected:
	int type;
public:
	q_mbti(int type = 0, str data = {1, "\n"}) :Question(data) {
		//this->data = data;
		this->type = type;
	}
	~q_mbti() {};
};

class q_kettel : public q_mbti {
	//friend class User;
	int value_multiplier_male;
	int value_multiplier_female;
public:
	q_kettel(int type = 0, str data = { 1, "\n" }) :q_mbti(type, data) {

	}
	~q_kettel() {};
};