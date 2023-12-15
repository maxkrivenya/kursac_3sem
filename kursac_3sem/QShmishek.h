#pragma once
#include "qMbti.h"

class qShmishek : public qMbti {
public:
	float value_multiplier_male;
	float value_multiplier_female;
	qShmishek(int type = 0, string data = "", float Male = 1.0, float Female = 0.8) :qMbti(type, data) {
		this->value_multiplier_male = Male;
		this->value_multiplier_female = Female;
	}
	~qShmishek() {};
	friend istream& operator>>(istream&, qShmishek&);
};

