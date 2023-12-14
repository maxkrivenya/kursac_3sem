#include "user.h"
#include "kursac_functions.h"

using namespace std;

void User::setId(string newId) {
	this->id = newId;
}
void User::setName(string newName) {
	this->name = newName;
}
void User::setPassword(string newPass) {
	this->pass = newPass;
}
void User::setGender(char newGender) {
	this->gender = newGender;
}
void User::setMbti(string newMbti) {
	this->curr_mbti = newMbti;
}
void User::setDriver(bool newDriver) {
	this->driver = newDriver;
}
void User::setSports(float newSports) {
	this->sports = newSports;
}

string User::getId() {
	return this->id;
}
string User::getName() {
	return this->name;
}
char   User::getGender() {
	return this->gender;
}
string User::getMbti() {
	return this->curr_mbti;
}
bool   User::getDriver() {
	return this->driver;
}
float  User::getSports() {
	return this->sports;
}


void User::updMbti(int val, qMbti data){
	switch (data.type) {
	case 1: {this->type.ei += val; break; }
	case 2: {this->type.sn += val; break; }
	case 3: {this->type.tf += val; break; }
	case 4: {this->type.jp += val; break; }
	default: {cout << endl << "Unexpected error" << endl; exit(1); break; }
	}
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

	string temp;
	string temp2;

	do {
		
		getline(old_fptr, temp);
		temp2 = nthWord(temp, 1);
		if (temp2 == this->id) {
			break;
		}
		new_fptr << temp << endl;
	} while (!(old_fptr.eof()));

	new_fptr << this->id << " " << setw(10) << this->name << " " << setw(10) << this->pass << "   ";
	if (this->type.ei != 0) { new_fptr << (*this); }
	else { new_fptr << this->curr_mbti; }

	while (!(old_fptr.eof())) {
		getline(old_fptr, temp);
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

void User::auth() {
	string login;
	string password;
	string login_s;
	string password_s;
	string temp;
	string id;
	int attempts = 4;
	do{
		cout << endl << "Login: ";
		cin >> login;

		ifstream fptr{ "users.txt" };
		if (!fptr) {
			cout << endl << "ERROR: file not open in user::auth";
			return;
		}

		do {
			getline(fptr, temp);
			id			= nthWord(temp, 1);
			login_s		= nthWord(temp, 2);
			password_s	= nthWord(temp, 3);

			if (login == login_s || login == id) {
				do {
					if (attempts != 4) {
						cout << endl << "Attempts left: " << attempts;
					}
					cout << endl << "Password: ";
					cin >> password;
					if (password == password_s) {
						fptr.close();
						this->name = login_s;
						this->pass = password_s;
						this->id = id;
						system("CLS");
						return;
					}
					attempts--;
				}while(attempts);
				cout << endl << "Too many attempts." << endl;
				exit(1);
			}
		} while (!fptr.eof());
		fptr.close();
	}while (1);
}
