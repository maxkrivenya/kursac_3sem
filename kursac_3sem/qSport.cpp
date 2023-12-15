#include "qSport.h"

int qSport::getRecord() {
	return this->record;
}
void qSport::setRecord(int newRecord) {
	this->record = newRecord;
}

ostream& operator<<(ostream& os, qSport& that) {
	os << that.data << endl << "Norm: " << that.answer << " Record: " << that.record;
	return os;
}

istream& operator>>(istream& is, qSport& that) {
	is >> that.answer;
	is >> that.record;
	is.ignore(1);
	getline(is, that.data);
	return is;
}