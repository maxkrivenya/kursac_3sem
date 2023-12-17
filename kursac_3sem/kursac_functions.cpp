#include "Interface.h"
#include "FileException.h"
#include <fstream>
#include <string>
#include <vector>
#define MISTAKES_AMT 3



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
		do {
			qDriver temp;
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
		huh.qHeader(curr);
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
	huh.qHeader("Bonus round!");
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
	List<T> list;
	int i = 0;
	ifstream fptr(filename);
	if (!fptr) {
		FileException oops;
		oops.show();
		return {};
	}
	while (!fptr.eof()) {
		i++;
		T temp;
		fptr >> temp;
		list.push(temp);
	}
	fptr.close();
	return list;
}

void mbtiTest(User& user){
	cout << "test started" << endl;
	List<qMbti> list = TestInit<qMbti>("mbti.txt");
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
	vector<int> mbti(4, 0);
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
		huh.qHeader(curr);
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
				mbti[(*it).value.getType()-1] += answ.pop();
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
			mbti[(*it).value.getType()-1] += choice;
		}
	}

	system("CLS");
	string result = VectToMbti(mbti);
	std::cout << "Your result is: " << result;
	huh.eot();
	bool wannasave = true;
	std::cin >> wannasave;
	if (wannasave) {
		user.setMbti(result);
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
	vector<int> shmishek(4, 0);
	for (List<qShmishek>::Iterator it = list.begin(); it != list.end(); it++) {
		if (flg) {
			it--;
		}
		else {
			curr++;
		}
		flg = false;
		choice = 0;
		huh.qHeader(curr);
		std::cout << (*it).value;
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
				shmishek[(*it).value.getType() - 1] += answ.pop();
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
			shmishek[(*it).value.getType() - 1] += choice;

		}
	}

	system("CLS");
	std::cout << "Your result is: ";
	for (vector<int>::iterator it = shmishek.begin(); it != shmishek.end(); it++) {
		std::cout << (*it) << " ";
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
		huh.qHeader(curr);
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

string VectToMbti(vector<int> that) {
	string result = "XXXX";
	if (that[0] > 0) {
		result[0] = 'E';
	}
	else {
		result[0] = 'I';
	}
	if (that[1] > 0)
	{
		result[1] = 'S';
	}
	else {
		result[1] = 'N';
	}
	if (that[2] > 0) {
		result[2] = 'T';
	}
	else {
		result[2] = 'F';
	}
	if (that[3] > 0) {
		result[3] = 'J';
	}
	else {
		result[3] = 'P';
	}
	return result;
}