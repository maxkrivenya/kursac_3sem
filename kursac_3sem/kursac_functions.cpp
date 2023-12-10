#include "kursac_functions.h"
#include "List.h"
#include <fstream>
using namespace std;
User& Register() {
	ifstream fptr{ "users.txt" };
	if (!fptr) {
		cout << endl << "file open error in register" << endl;
		exit(1);
	}
	int str_amt = 0;
	str login{ N };
	str password{ N };
	str password2{ N };
	int id;
	bool male;
	str temp{ 80 };

	for (; !fptr.eof(); str_amt++) {
		fptr.getline(temp.string, 79);
	}
	id = 1111 + (str_amt / 2);
	cout << endl << "stramt = " << str_amt << endl;
	fptr.close();
	fstream fptr2{ "users.txt", std::ios::app };
	cout << endl << "Login: ";
	cin >> login.string;
	login = login.nthWord();
	cout << endl << "Are you male or female? (0/1): ";
	cin >> male;
	do {
		cout << endl << "Password: ";
		cin >> password.string;
		password = password.nthWord();
		cout << endl << "Repeat password: ";
		cin >> password2.string;
		password2 = password2.nthWord();

		if (!(password == password2))
			cout << endl << "Passwords don't match" << endl;
	} while (!(password == password2));

	fptr2 << endl <<
		login << " " <<
		password << " " <<
		id << endl <<
		male << " " <<
		0 << " " << 0 << " " << 0 << " " << 0;

	User new_user{ login, password, id, male };
	return new_user;
}

void mbti_test(List<q_mbti> list, User& user){
	if (list.isEmpty()) {
		std::cout << std::endl << "Empty List." << std::endl;
		return;
	}
	int curr = 0;
	int choice = 0;
	std::cout << std::endl << "Welcome to the MBTI Test."
		<< std::endl << "The rules are simple:"
		<< std::endl << "\tYou will be shown a statement."
		<< std::endl << "\tTo quit the test, input a negative number."
		<< std::endl << "\tTo return to the previous question, input 0."
		<< std::endl << "\tPlease input a number from 1 to 5 as your answer depending on how much you agree with the statement."
		<< std::endl << "To start the Test, input any number." << std::endl 
		<< std::endl << "To return, input a negative number." << std::endl
		<< std::endl << "Your answer:  ";
	cin >> choice;
	if (choice < 0) {
		return;
	}

	choice = 0;
	bool flg = false;
	for (List<q_mbti>::Iterator it = list.begin(); it != list.end(); it++) {
		if (flg) {
			it--;
		}
		else {
			curr++;
		}
		flg = false;
		choice = 0;
		q_header(curr);
		(*it).value.sout();
		std::cout << std::endl << "Your answer:  ";
		std::cin >> choice;

		if (choice < 0) {
			return;
		}
		if (!choice) {
			flg = true;    
			curr--;
			if (curr < 1) {
				curr = 1;
			}
			if (it != list.begin()) {
				it--;
			}
		}
		else {
			user.upd_mbti(choice-3, (*it).value.Type());
		}
	}

	system("CLS");
	std::cout << "Your result is: " << user << std::endl;
	user.save();
}

void q_header(int curr) {
	system("CLS");
	for (int i = 0; i < CONSOLE_WIDTH; i++)
		cout << '=';
	cout << endl;
	cout << setw(CONSOLE_WIDTH/2) << "Question #" << curr << endl;
	for (int i = 0; i < CONSOLE_WIDTH; i++)
		cout << '=';
}