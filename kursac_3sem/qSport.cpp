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