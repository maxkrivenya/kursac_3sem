#include "question.h"
using namespace std;

void Question::sout() {
	cout << endl << this->data << endl;
}

ostream& operator<<(ostream& os, Question& q) {
	os << '\n' << q.data << '\n';
	return os;
}

istream& operator>>(istream& is, q_driver& that) {
	setlocale(LC_ALL, "RUSSIAN");
	int temp = 0;
	is >> temp;
	if (temp == 0) {
		is >> temp;
	}
	that.type = temp / 100;
	that.answer = (temp%100) / 10;
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

ostream& operator<<(ostream& os, q_driver& that) {
	os << endl << that.data << endl;
	for (List<string>::Iterator it = that.choices.begin(); it != that.choices.end(); it++) {
		os << it->value << endl;
	}
	//os << "Type: " << that.type << " Ans: " << that.answer << endl;
	return os;
}