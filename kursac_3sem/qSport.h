#pragma once
#include "qWithAnswer.h"
#include "qShmishek.h"

class qSport:public qShmishek, public qWithAnswer {
protected:
	int record;
public:
	qSport(string data = "", int answer = 0, int record = 0, float kMale = 1.0, float kFem = 0.8):qShmishek(0, data, kMale, kFem), qWithAnswer(data, answer), Question(data) {
		this->record = record;
	};
	~qSport() {};
	int getRecord();
	void setRecord(int record);
	friend ostream& operator<<(ostream& os, qSport& that);
	friend istream& operator>>(istream& is, qSport& that);
};