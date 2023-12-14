#pragma once
#include "qMbti.h"

class qShmishek : public qMbti {
	float value_multiplier_male;
	float value_multiplier_female;
public:
	qShmishek(int type = 0, string data = "", float Male = 1, float Female = 1) :qMbti(type, data) {
		this->value_multiplier_male = Male;
		this->value_multiplier_female = Female;
	}
	~qShmishek() {};
};

