#pragma once
#include <string>
#include "Containers.h"
using namespace std;

class Question {

protected:
	string data;
public:
	Question(string data = "") {
		this->data = data;
	}
	~Question() {};
	friend ostream& operator<<(ostream& os, Question& q);
	friend istream& operator>>(istream& os, Question& q);
	string getData();
	void setData(string newData);
};
