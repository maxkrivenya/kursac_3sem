#include"user.h"
using namespace std;
void User::upd_ei(int a) {
	this->type.ei += a;
}

void User::upd_sn(int a) {
	this->type.sn += a;
}
void User::upd_tf(int a) {
	this->type.tf += a;
}
void User::upd_jp(int a) {
	this->type.jp += a;
}

 ostream& operator<<(ostream& o, const User& user) {
	o << endl << "MBTI: ";
	//<< user.type.ei << ' ' << user.type.sn << ' ' << user.type.tf << ' ' << user.type.jp << endl;
	if (user.type.ei >= 0) {
		o << 'E';
	}
	else {
		o << 'I';
	}
	if (user.type.sn >= 0) {
		o << 'S';
	}
	else {
		o << 'N';
	}
	if (user.type.tf >= 0) {
		o << 'T';
	}
	else {
		o << 'F';
	}
	if (user.type.jp >= 0) {
		o << 'J';
	}
	else {
		o << 'P';
	}

	return o;
}