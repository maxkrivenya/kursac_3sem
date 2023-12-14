#include "QDriver.h"

istream& operator>>(istream& is, qDriver& that) {
	setlocale(LC_ALL, "RUSSIAN");
	int temp = 0;
	is >> temp;
	if (temp == 0) {
		is >> temp;
	}
	that.type = temp / 100;
	that.answer = (temp % 100) / 10;
	temp %= 100;
	temp %= 10;
	cout << temp;
	getline(is, that.data);
	getline(is, that.data);
	string x;
	for (int i = 0; i < temp; i++) {
		getline(is, x);
		that.choices.push(x);
	}
	return is;
}

ostream& operator<<(ostream& os, qDriver& that) {
	os << endl << that.data << endl;
	for (List<string>::Iterator it = that.choices.begin(); it != that.choices.end(); it++) {
		os << it->value << endl;
	}
	return os;
}

int qDriver::getType() {
	return this->type;
}
void qDriver::setType(int newType) {
	this->type = newType;
}

void qDriver::addChoice(string newChoice) {
	this->choices.push(newChoice);
}