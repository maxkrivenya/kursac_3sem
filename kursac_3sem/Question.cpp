#include "question.h"
using namespace std;
void Question::sout() {
	cout << endl << this->data << endl;
}
ostream& operator<<(ostream& os, Question& q) {
	os << '\n' << q.data << '\n';
	return os;
}