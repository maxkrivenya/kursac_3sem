#pragma once
#include "qWithAnswer.h"

class qDriver : public qWithAnswer {
	friend class user;
protected:
	int type;
	List<string> choices;
public:
	qDriver(string s, int answer, int type = 0) :qWithAnswer(s, answer) {
		this->type = type;
	};
	~qDriver() {};
	int getType();
	void setType(int newType);
	void addChoice(string newChoice);
	friend istream& operator>>(istream& os, qDriver& that);
	friend ostream& operator<<(ostream& os, qDriver& q);
};