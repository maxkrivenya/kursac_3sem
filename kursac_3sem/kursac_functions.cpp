#include "kursac_functions.h"
#include "List.h"
#include <fstream>
User& Register() {
	ifstream fptr{ "users.txt" };
	if (!fptr) {
		std::cout << std::endl << "file open error in register" << std::endl;
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
	NEWLINE;
	std::cout << "stramt = " << str_amt;
	NEWLINE;
	fptr.close();
	fstream fptr2{ "users.txt", std::ios::app };
	std::cout << std::endl << "Login: ";
	cin >> login.string;
	login = login.nthWord();
	NEWLINE;
	std::cout << "Are you male or female? (0/1): ";
	cin >> male;
	do {
		NEWLINE;
		std::cout << "Password: ";
		cin >> password.string;
		password = password.nthWord();
		NEWLINE;
		std::cout << "Repeat password: ";
		cin >> password2.string;
		password2 = password2.nthWord();

		if (!(password == password2)) {
			NEWLINE;
			std::cout <<"Passwords don't match";
			NEWLINE;
		}
	} while (!(password == password2));

	fptr2 << std::endl <<
		login << " " <<
		password << " " <<
		id << std::endl <<
		male << " " <<
		0 << " " << 0 << " " << 0 << " " << 0;

	User new_user{ login, password, id, male };
	return new_user;
}

void mbti_test(List<q_mbti> list, User& user){
	if (list.isEmpty()) {
		NEWLINE;
		std::cout << "Empty List.";
		NEWLINE;
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
	stack<int> answ;
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
		NEWLINE;
		std::cout << "Your answer:  ";
		std::cin >> choice;
		if (choice < 0) {
			return;
		}
		if (!choice) {
			flg = true;    
			if (curr > 1 || !(answ.isEmpty())) {
				user.upd_mbti(answ.pop(), (*it).value.Type());
			}
			curr--;
			if (curr < 1) {
				curr = 1;
			}
			if (it != list.begin()) {
				it--;
			}
			
		}
		else {
			choice -= 3;
			answ.push((-1) * choice);
			user.upd_mbti(choice, (*it).value.Type());
		}
	}

	system("CLS");
	std::cout << "Your result is: " << user;
	bool wannasave = true;
	NEWLINE;
	std::cout << "If you don't want to save, type 0: ";
	std::cin >> wannasave;
	if (wannasave) {
		user.save();
	}
}

void q_header(int curr) {
	system("CLS");
	SKIP(CONSOLE_WIDTH / 2 - 11);
	REPEAT('-', 15);
	NEWLINE;
	SKIP(CONSOLE_WIDTH / 2);
	std::cout << "| Question #" << curr << " |";
	NEWLINE;
	SKIP(CONSOLE_WIDTH / 2 - 11);
	REPEAT('-', 15);
}

void REPEAT(char c, int amt) {
	for (int i = 0; i < amt; i++)
		std::cout << c;
}

void SKIP(int amt) {
	std::cout << setw(amt);
}
