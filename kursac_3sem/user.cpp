#include"user.h"
#include "Question.h"
using namespace std;

void User::upd_mbti(int val, q_mbti data){
	switch (data.type) {
	case 1: {this->type.ei += val; break; }
	case 2: {this->type.sn += val; break; }
	case 3: {this->type.tf += val; break; }
	case 4: {this->type.jp += val; break; }
	default: {cout << endl << "Unexpected error" << endl; exit(1); break; }
	}
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