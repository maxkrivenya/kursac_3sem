#include "QShmishek.h"

istream& operator>>(istream& is, qShmishek& that) {
	is >> that.type;
	is >> that.value_multiplier_male;
	is >> that.value_multiplier_female;
	is.ignore(1);
	getline(is, that.data);
	return is;
}