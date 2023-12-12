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
		
		temp2 = temp.nthWord();

		if (!strcmp(temp2.string, this->name)) {
			break;
		}

		new_fptr << temp << endl;
	} while (!(old_fptr.eof()));

	new_fptr << this->name << " " << this->pass << " " << this->id << " " << (*this);
	while (!(old_fptr.eof())) {
		old_fptr.getline(temp.string, 70);
		new_fptr << endl << temp ;
		if (old_fptr.eof())
			break;
	}
	old_fptr.close();
	new_fptr.close();

	rename("users.txt", "shit.txt");
	rename("users2.txt", "users.txt");
	rename("shit.txt", "users2.txt");
}

User& User::auth() {
	str login{ N };
	str password{ N };
	str login_s;
	str password_s;
	str temp{ 80 };
	int newid = 0;
	int hui = 0;
	int i = 3;
	do{
		cout << endl << "Login: ";
		cin >> login.string;
		login = login.nthWord();

		ifstream fptr{ "users.txt" };
		if (!fptr) {
			cout << endl << "ERROR: file not open in user::auth";
			User u{ login, login };
			return u;
		}

		do {
			newid = 0;
			fptr.getline(temp.string, 40);
			login_s = temp.nthWord(1);
			password_s = temp.nthWord(2);
			for (i = 0; !isdigit(temp[i]) && i < temp.len; i++);
			int j = 3;
			for (; j >= 0 && i < temp.len && isdigit(temp[i]); j--, i++) {
				hui = temp[i] - '0';
				for(int k = j; k > 0; k--)
					hui *= 10;
				newid += hui;
			}

			if (login == login_s) {
				do {
					cout << endl << "Password: ";
					cin >> password.string;
					if (password == password_s) {
						fptr.close();
						User u{ login_s, password_s, newid };
						system("CLS");
						return u;
					}
				}while(1);
			}
		} while (!fptr.eof());
		fptr.close();
		i--;
	}while (i);
}