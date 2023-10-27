#pragma once
#include "stroki.h"
class Question {
	str data;
	Question* next;
	Question* prev;
};
class q_mbti :Question {
	int type;
};