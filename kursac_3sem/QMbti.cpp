#include "qMbti.h"

istream& operator>>(istream& is, qMbti& q) {
	is >> q.type >> q.data;
	return is;
}

void qMbti::setType(int newType) {
	this->type = newType;
}

int qMbti::getType() {
	return this->type;
}