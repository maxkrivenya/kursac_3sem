#pragma once
#include "qWithAnswer.h"
#include "qShmishek.h"

class qSport:public qShmishek, public qWithAnswer {
protected:
	int record;
public:
	qSport(string data = "", float male = 1, float female = 1, int answer = 0, int record = 0):qShmishek(0, data, male, female), qWithAnswer(data, answer) {
		this->record = record;
	};
	~qSport() {};
	int getRecord();
	void setRecord(int record);
};