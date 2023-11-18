#include "user.h"
#include "question.h"
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

void User::upd_kettel(int answer, q_mbti q) {
	this->ket[q.type] += answer;
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

void User::save() {
	fstream fptr{ "users.txt" };
	if (!fptr) { std::cout << "\nError open users\n"; return; }
	fptr << this->name << this->male << " " << this->type.ei << " " << this->type.sn << " " << this->type.tf << " " << this->type.jp << '\n';
	fptr.close();
}