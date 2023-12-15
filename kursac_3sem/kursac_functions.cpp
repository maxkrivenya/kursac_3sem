#include "Interface.h"
#include "FileException.h"
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

Tree<qDriver> DriverTestInit() {
		ifstream fptr("driver.txt");
		if (!fptr) {
			FileException oops;
			oops.show();
			return {};
		}
		Tree<qDriver> that;
		string x;
		qDriver temp;
		do {
			fptr >> temp;
			that.push_question(temp);
		} while (!fptr.eof());
		fptr.close();
		return that;
	}

void DriverTest(User& user){
	Interface huh;
	Tree<qDriver> test = DriverTestInit();
	if (test.isEmpty()) {
		FileException empty;
		empty.show();
		return;
	}
	int mistakes = 0;
	int curr = 0;
	int choice = 0;
	if (!huh.DriverTestMenu()) { return; }
	for (Tree<qDriver>::Iterator it = test.begin(); it != test.end(); +it) {
		curr++;
		choice = 0;
		huh.q_header(curr);
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
				user.setDriver(false);
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
	user.setDriver(true);
	user.save();
	SKIP(CONSOLE_WIDTH / 2 + 10);
	cout << "YOU WON!" << endl;
	return;
}

void question_failed(Tree<qDriver>::Iterator it, User& user, int& mistakes_amt) {
	Interface huh;
	int cat = (*it).value.getType();
	do {
		+it;
	} while ((*it).value.getType() != cat && (*it).IsntNull(4) != NULL);
	if ((*it).value.getType() != cat) {
		cout << "type error!";
		exit(1);
	}
	huh.q_header("Bonus round!");
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


template <class T>
List<T> TestInit(const char* filename){
	ifstream fptr(filename);
	if (!fptr) {
		FileException oops;
		oops.show();
		return {};
	}
	List<T> list;
	string x;
	do {
		T temp;
		fptr >> temp;
		list.push(temp);
	} while (!fptr.eof());
	fptr.close();
	return list;
}

void mbtiTest(User& user){
	List<qMbti> list = TestInit<qMbti>("mbtiQuestions.txt");
	if (list.isEmpty()) {
		FileException exc;
		exc.show();
		return;
	}
	Interface huh;
	if (!huh.MBTItestMenu()) { return; }

	int choice = 0;
	int curr = 0;
	bool flg = false;
	Stack<int> answ;
	for (List<qMbti>::Iterator it = list.begin(); it != list.end(); it++) {
		if (flg) {
			it--;
		}
		else {
			curr++;
		}
		flg = false;
		choice = 0;
		huh.q_header(curr);
		cout << (*it).value;
		NEWLINE;
		std::cout << "Your answer:  ";
		std::cin >> choice;
		if (choice < 0) {
			return;
		}
		if (!choice) {
			flg = true;    
			if (curr > 1 || !(answ.isEmpty())) {
				user.updMbti(answ.pop(), (*it).value);
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
			user.updMbti(choice, (*it).value);
		}
	}

	system("CLS");
	std::cout << "Your result is: " << user;
	huh.eot();
	bool wannasave = true;
	std::cin >> wannasave;
	if (wannasave) {
		user.save();
	}
}
void ShmishekTest(User& user) {
	List<qShmishek> list = TestInit<qShmishek>("shmishek.txt");
	if (list.isEmpty()) {
		FileException exc;
		exc.show();
		return;
	}
	Interface huh;
	if (!huh.MBTItestMenu()) { return; }

	int choice = 0;
	int curr = 0;
	bool flg = false;
	Stack<int> answ;

	for (List<qShmishek>::Iterator it = list.begin(); it != list.end(); it++) {
		if (flg) {
			it--;
		}
		else {
			curr++;
		}
		flg = false;
		choice = 0;
		huh.q_header(curr);
		cout << (*it).value;
		NEWLINE;
		std::cout << "Your answer:  ";
		std::cin >> choice;
		if (choice < 0) {
			return;
		}
		if (!choice) {
			flg = true;
			curr--;
			if (it != list.begin()) {
				it--;
			}
			if (curr < 1) {
				curr = 1;
			}
			if (!(answ.isEmpty())) {
			//	user.updShmishek(answ.pop(), (*it).value);
			}
		}
		else {
			if (user.getGender() == 'f') {
				choice /= (*it).value.value_multiplier_female;
			}
			else {
				choice /= (*it).value.value_multiplier_male;
			}
			answ.push((-1) * choice);
			user.updShmishek((*it).value.getType(), choice);

		}
	}

	system("CLS");
	//std::cout << "Your result is: " << result << endl;
	//std::cout << "The best is: " << best << endl;
	huh.eot();
	bool wannasave = true;
	std::cin >> wannasave;
	if (wannasave) {
		//user.setSports(result);
		user.save();
	}
}
void SportsTest(User& user) {
	//List<qSport> list = sportsTestInit();
	List<qSport> list = TestInit<qSport>("sports.txt");
	if (list.isEmpty()) {
		FileException exc;
		exc.show();
		return;
	}
	Interface huh;
	if (!huh.MBTItestMenu()) { return; }

	float result = 0;
	float best = 0;
	int choice = 0;
	int curr = 0;
	bool flg = false;
	Stack<int> answ;

	for (List<qSport>::Iterator it = list.begin(); it != list.end(); it++) {
		if (flg) {
			it--;
		}
		else {
			curr++;
		}
		flg = false;
		choice = 0;
		huh.q_header(curr);
		cout << (*it).value;
		NEWLINE;
		std::cout << "Your answer:  ";
		std::cin >> choice;
		if (choice < 0) {
			return;
		}
		if (!choice) {
			flg = true;
			if (curr > 1 || !(answ.isEmpty())) {
				best += answ.pop();
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
			if (user.getGender() == 'f') {
				choice /= (*it).value.value_multiplier_female;
			}
			else {
				choice /= (*it).value.value_multiplier_male;
			}
			answ.push((-1) * choice);
			if(choice > (*it).value.getAnswer()){
				result++;
				if (choice > (*it).value.getRecord()) {
					result++;
				}
			}
			best += 2;
		}
	}

	system("CLS");
	std::cout << "Your result is: " << result << endl;
	std::cout << "The best is: " << best << endl;
	huh.eot();
	bool wannasave = true;
	std::cin >> wannasave;
	if (wannasave) {
		user.setSports(result);
		user.save();
	}
}