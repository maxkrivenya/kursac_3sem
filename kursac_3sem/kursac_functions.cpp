#include "kursac_functions.h"
#include <fstream>
#include <string>
#define MISTAKES_AMT 3
User& Register() {
	ifstream fptr{ "users.txt" };
	if (!fptr) {
		std::cout << std::endl << "file open error in register" << std::endl;
		exit(1);
	}
	int str_amt = 0;
	string login;
	string password;
	string password2;
	int id;
	bool male;
	string temp;

	for (; !fptr.eof(); str_amt++) {
		getline(fptr, temp);
	}
	id = 1111 + (str_amt / 2);
	NEWLINE;
	std::cout << "stramt = " << str_amt;
	NEWLINE;
	fptr.close();
	fstream fptr2{ "users.txt", std::ios::app };
	std::cout << std::endl << "Login: ";
	cin >> login;
	NEWLINE;
	std::cout << "Are you male or female? (0/1): ";
	cin >> male;
	do {
		NEWLINE;
		std::cout << "Password: ";
		cin >> password;
		NEWLINE;
		std::cout << "Repeat password: ";
		cin >> password2;

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
		<< std::endl << "To return now, input a negative number." << std::endl
		<< std::endl << "Your answer:  ";
	cin >> choice;
	if (choice < 0) {
		return;
	}

	choice = 0;
	bool flg = false;
	Stack<int> answ;
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
				user.upd_mbti(answ.pop(), (*it).value);
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
			user.upd_mbti(choice, (*it).value);
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

void q_header(string text) {
	system("CLS");
	SKIP(CONSOLE_WIDTH / 2 - 11);
	REPEAT('-', 15);
	NEWLINE;
	SKIP(CONSOLE_WIDTH / 2);
	std::cout << "| " << text << " |";
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

string nthWord(string that, int n) {
	string temp;
	int i = 0;
	int j = 0;

	for (int k = 1; k < n; k++) {
		while (that[i] == ' ' && i < that.length()) {
			i++;
		}
		while (that[i] != ' ' && i < that.length()) {
			i++;
		}
	}

	while (that[i] == ' ' && i < that.length()) {
		i++;
	}
	while (that[i] != ' ' && i < that.length()) {
		temp.push_back(that[i]);
		i++;
	}
	return temp;

}

void DriverTest(Tree<q_driver> test, User& user) {
	if (test.isEmpty()) {
		NEWLINE;
		std::cout << "Empty List.";
		NEWLINE;
		return;
	}
	int mistakes = 0;
	int curr = 0;
	int choice = 0;
	std::cout << std::endl << "Welcome to the Driver Test."
		<< std::endl << "The rules are simple:"
		<< std::endl << "\tYou will be shown a statement and several answer options."
		<< std::endl << "\tTo quit the test, input a negative number."
		<< std::endl << "\tTo answer, input a number corresponding to the answer option you think is correct."
		<< std::endl << "\tYou can make " << MISTAKES_AMT << " mistakes" << std::endl
		<< std::endl << "To start the Test, input any number." << std::endl
		<< std::endl << "To return now, input a negative number." << std::endl
		<< std::endl << "Your answer:  ";
	cin >> choice;
	if (choice < 0) {
		return;
	}
	for (Tree<q_driver>::Iterator it = test.begin(); it != test.end(); +it) {
		curr++;
		choice = 0;
		q_header(curr);
		cout << (*it).value;
		NEWLINE;
		std::cout << "Your answer:  ";
		std::cin >> choice;
		if (choice < 0) {
			return;
		}
		if (choice != (*it).value.getAnswer()) {
			mistakes++;
			if (mistakes == MISTAKES_AMT) {
				user.upd_driver(false);
				user.save();
				SKIP(CONSOLE_WIDTH / 2 + 10);
				cout << "YOU FAILED" << endl;
				return;
			}
			cout << mistakes;
			question_failed(it, user, mistakes);
			cout << mistakes;
		}
	}
	user.upd_driver(true);
	user.save();
	SKIP(CONSOLE_WIDTH / 2 + 10);
	cout << "YOU WON!" << endl;
	return;
}

void question_failed(Tree<q_driver>::Iterator it, User& user, int& mistakes_amt) {
	int cat = (*it).value.getType();
	do {
		+it;
	} while ((*it).value.getType() != cat && (*it).IsntNull(4) != NULL);
	if ((*it).value.getType() != cat) {
		cout << "type error!";
		exit(1);
	}
	q_header("Bonus round!");
	cout << (*it).value;
	NEWLINE;
	std::cout << "Your answer:  ";
	std::cin >> cat;
	if (cat < 0) {
		return;
	}
	if (cat != (*it).value.getAnswer()) {
		mistakes_amt++;
	}
	while ((*it).value.getType() != 0) {
		-it;
	}
	return;
}
