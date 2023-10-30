#include"usercd.h"
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

/*void User::upd_kettel(int val, q_kettel data) {
	switch (data.type) {
	case 1: {this->ket.anxiety += val; break; }
	case 2: {this->ket.balance += val; break; }
	case 3: {this->ket.brave += val; break; }
	case 4: {this->ket.diplomacy += val; break; }
	case 5: {this->ket.dreamy += val; break; }
	case 6: {this->ket.em_stability += val; break; }
	case 7: {this->ket.expressiveness += val; break; }
	case 8: {this->ket.extraversy += val; break; }
	case 9: {this->ket.independence += val; break; }
	case 10: {this->ket.intellect += val; break; }
	case 11: {this->ket.nonconform += val; break; }
	case 12: { this->ket.normativity += val; break; }
	case 13: {this->ket.radical += val; break; }
	case 14: {this->ket.selfcontrol += val; break; }
	case 15: {this->ket.sens += val; break; }
	case 16: {this->ket.stress += val; break; }
	case 17: {this->ket.sus += val; break; }
	case 18: {this->ket.talk += val; break; }
	case 19: {this->ket.uncalm += val; break; }
	default: {cout << endl << "Unexpected error" << endl; exit(1); break; }
	}
}*/


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