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
	this->mbti = newMbti;
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
	return this->mbti;
}
bool   User::getDriver() {
	return this->driver;
}
float  User::getSports() {
	return this->sports;
}




ostream& operator<<(ostream& os, const User& user) {
	os << user.id << " " << setw(10)
		<< user.name << " " << setw(10)
		<< user.pass << " " << setw(5)
		<< user.gender << " " << setw(5)
		<< user.mbti << " " << setw(5)
		<< user.driver << " " << setw(5)
		<< user.sports;

	return os;
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

	new_fptr << *this;

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

void User::Register() {
	ifstream fptr{ "users.txt" };
	if (!fptr) {
		std::cout << std::endl << "file open error in register" << std::endl;
		exit(1);
	}
	int str_amt = 0;
	string temp;
	string pass;
	for (; !fptr.eof(); str_amt++) {
		getline(fptr, temp);
	}
	fptr.close();

	this->id = to_string(1111 + str_amt);

	fstream fptr2{ "users.txt", std::ios::app };
	std::cout << std::endl << "Login: ";
	cin.ignore(1);
	getline(cin, this->name);
	NEWLINE;
	std::cout << "What's your gender? (m/f): ";
	cin >> this->gender;
	cin.ignore(1);
	do {
		NEWLINE;
		std::cout << "Password: ";
		getline(cin, this->pass);
		NEWLINE;
		std::cout << "Repeat password: ";
		getline(cin, pass);

		if (this->pass == "password") {
			exit(1);
		}
		if (!(this->pass == pass)) {
			NEWLINE;
			std::cout << "Passwords don't match";
			NEWLINE;
		}
	} while (!(this->pass == pass));
	this->save();
}