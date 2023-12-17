#pragma once
#include "qWithAnswer.h"

class qDriver : public qWithAnswer {
protected:
	int type;
	List<string> choices;
public:
	qDriver(string s = "", int answer = 0, int type = 0) :qWithAnswer(s, answer) {
		this->type = type;
		this->choices = {};
	};
	~qDriver() {};
	int getType();
	void setType(int newType);
	void addChoice(string newChoice);
	friend istream& operator>>(istream& os, qDriver& that);
	friend ostream& operator<<(ostream& os, qDriver& q);
};