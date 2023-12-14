#include "question.h"
using namespace std;

ostream& operator<<(ostream& os, Question& q) {
	os << '\n' << q.data << '\n';
	return os;
}

istream& operator>>(istream& is, Question& q) {
	is >> q.data;
	return is;
}

string Question::getData() {
	return this->data;
}

void Question::setData(string newData) {
	this->data = newData;
}