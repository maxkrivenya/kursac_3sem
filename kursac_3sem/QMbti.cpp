#include "qMbti.h"

void qMbti::setType(int newType) {
	this->type = newType;
}

int qMbti::getType() {
	return this->type;
}

istream& operator>>(istream& is, qMbti& q) {
	is >> q.type;
	getline(is, q.data);
	return is;
}
