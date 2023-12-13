#pragma once
#include <string>
#include "List.h"
#include "Stack.h"
#include "tree.h"
using namespace std;

class Question {
	template <class shit>
	friend class ListIterator;
public:
	Question(string data) {
		this->data = data;
	}
	~Question() {};
	void sout();
	friend ostream& operator<<(ostream& os, Question& q);
protected:
	string data;
};


class q_mbti : public Question {
	friend class User;
protected:
	int type;
public:
	q_mbti(int type = 1, string data = "Hello World!") :Question(data) {
		this->type = type;
	}
	~q_mbti() {};
	void sout() {
		cout << endl << this->data << endl;
	}
	int getType() {
		return this->type;
	}
};

class q_shmishek : public q_mbti {
	float value_multiplier_male;
	float value_multiplier_female;
public:
	q_shmishek(int type, string data, float v1 =  1, float v2 = 1) :q_mbti(type, data) {
		this->value_multiplier_female = v2;
		this->value_multiplier_male = v1;
	}
	~q_shmishek() {};
};


class q_driver : public q_mbti {
	friend class user;
protected:
	int answer;
	List<string> choices;
public:
	q_driver() :q_mbti() {};
	~q_driver() {};
	int getAnswer() {
		return this->answer;
	}
	string getData() {
		return this->data;
	}
	friend istream& operator>>(istream& os, q_driver& that);
	friend ostream& operator<<(ostream& os, q_driver& q);
};