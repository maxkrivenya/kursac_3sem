#include "Interface.h"

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
	void Interface::q_header(int curr) {
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

	void Interface::q_header(string text) {
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
