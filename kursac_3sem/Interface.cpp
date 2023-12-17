#include "Interface.h"
#define MISTAKES_AMT 3

bool Interface::MBTItestMenu() {
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
	if (choice <= 0) {
		return 0;
	}
	return 1;
}

bool Interface::DriverTestMenu() {
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
	if (choice <= 0) {
		return 0;
	}
	return 1;
}

void Interface::qHeader(int curr) {
	system("CLS");
	SKIP(CONSOLE_WIDTH / 2 - 11);
	REPEAT('-', 15);
	NEWLINE;
	SKIP(CONSOLE_WIDTH / 2);
	std::cout << "| Question #" << curr << " |";
	NEWLINE;
	SKIP(CONSOLE_WIDTH / 2 - 11);
	REPEAT('-', 15);
	NEWLINE;
}

void Interface::qHeader(string text) {
	system("CLS");
	SKIP(CONSOLE_WIDTH / 2 - text.length());
	REPEAT('-', text.length() + 4);
	NEWLINE;
	SKIP(CONSOLE_WIDTH / 2 - text.length() + 1);
	std::cout << "| " << text << " |";
	NEWLINE;
	SKIP(CONSOLE_WIDTH / 2 - text.length());
	REPEAT('-', text.length() + 4);
	NEWLINE;
}

void Interface::eot() {
	NEWLINE;
	std::cout << "If you don't want to save, type 0: ";
}

void Interface::MainMenuHeader() {
	system("CLS");
	cout << "Welcome to Max's Tests!" << endl
		<< "If you're a new user, type 0" << endl
		<< "If you already have an accout, type 1" << endl
		<< "Your choice: ";
}

void Interface::MainMenu() {
	MainMenuHeader();
	int choice = 0;
	cin >> choice;
	if (choice) {
		this->user.auth();
	}
	else {
		this->user.Register();
	}
	this->TestMenu();
}

void Interface::TestMenuHeader() {
	system("CLS");
	cout << "Welcome to Max's Tests!" <<
		endl << "To return, input a negative number" <<
		endl << "Input choices:" <<
		endl << "\t1: MBTI test" <<
		endl << "\t2: Shmishek test" <<
		endl << "\t3: Driver's test" <<
		endl << "\t4: Sports test" <<
		endl << "Your answer: ";
}

void Interface::TestMenu(){
	int choice = 0;
	TestMenuHeader();
	cin >> choice;
	if (choice < 0) { return; }
	switch (choice) {
	case 1: {
		mbtiTest(this->user);
		break;
	}
	case 2: {
		ShmishekTest(this->user);
		break;
	}
	case 3: {
		DriverTest(this->user);
		break;
	}
	case 4: {
		SportsTest(this->user);
		break;
	}
	default:
		InputException exc("Please choose from 1-4.\nOr input a negative number to exit\n");
		exc.show();
	}
	
}

