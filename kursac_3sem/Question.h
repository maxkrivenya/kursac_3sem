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

class q_shmishek : public q_mbti {
	//friend class User;
	float value_multiplier_male;
	float value_multiplier_female;
public:
	q_shmishek(int type = 0, str data = { 1, "\n" }, float v1=  0, float v2 = 0) :q_mbti(type, data) {
		this->value_multiplier_female = v2;
		this->value_multiplier_male = v1;
	}
	~q_shmishek() {};
};