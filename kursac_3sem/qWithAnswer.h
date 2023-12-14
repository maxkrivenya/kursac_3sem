#pragma once
#include "Question.h"

class qWithAnswer : public virtual Question {
protected:
	int answer;
public:
	qWithAnswer(string s = "", int answ = 1) :Question(s) {
		this->answer = answ;
	}
	~qWithAnswer() {};
	int getAnswer();
	void setAnswer(int newAnswer);
};