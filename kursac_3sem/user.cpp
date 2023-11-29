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

	ifstream old_fptr{ "users.txt" };
	ofstream new_fptr{ "users2.txt" };
	
	if (!old_fptr) { std::cout << "\nError open users\n"; return; }
	if (!new_fptr) { std::cout << "\nError open users2\n"; return; }

	str temp{ 80 };
	str temp2{ 80 };
	
	do {
		
		old_fptr.getline(temp.string, 70);
		if (!temp[0]) {
			old_fptr.getline(temp.string, 70);
		}
		
		
		temp2 = temp.firstWord();

		if (temp2 == this->name) {
			break;
		}

		new_fptr << temp << endl;

		old_fptr.getline(temp.string, 70);
		if (!temp[0] && !temp[1]) {
			old_fptr.getline(temp.string, 70);
		}
		new_fptr << temp << endl;
	} while (!(old_fptr.eof()));

	//no id copy
	new_fptr << this->name << " " << this->id << endl << this->male << " " << this->type.ei << " " << this->type.sn << " " << this->type.tf << " " << this->type.jp << '\n';
	old_fptr.getline(temp.string, 70);

	while (!(old_fptr.eof())) {
		old_fptr.getline(temp.string, 70);
		new_fptr << temp << endl;
	}
	old_fptr.close();
	new_fptr.close();

	rename("users.txt", "shit.txt");
	rename("users2.txt", "users.txt");
	rename("shit.txt", "users2.txt");
}

User& User::auth() {
	str login2{ 10 };
	str login;
	str temp{ 80 };
	int i = 3;
	bool flag = false;
	do{
		cout << endl << "Login: ";
		cin >> login2.string;
		login = { login2 };
		ifstream fptr{ "users.txt" };
		if (!fptr) {
			cout << endl << "ERROR: file not open in user::auth";
			User u{ login };
			return u;
		}

		do {
			fptr >> temp.string;
			
			temp = temp.firstWord();
			
			cout << endl << "result: " << (temp == login) << endl << temp;
			if (login == temp) {
				flag = true;
				fptr.close();
				User u{ login };
				return u;
			}

			fptr >> temp.string;
		} while (!fptr.eof());
		fptr.close();
		i--;
	}while (!flag && i);
}