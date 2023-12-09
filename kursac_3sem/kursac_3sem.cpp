#include "test.h"
#include "stroki.h"
#include "user.h"
#include "Question.h"
#include "stack.h"
#include "List.h"
#include "kursac_functions.h"
#include <fstream>
#define n 80
using namespace std;
int main() {
	User max = max.auth(); 
	//User max = Register();
	cout << endl << "thefuck #2" << endl;
	ifstream fptr("data.txt");
	Test test;
	List<q_mbti> list;
	int flg = 0;
	char* x = new char[n];
	char* y = new char[6];
	fptr.getline(y, 5);
	do {
		fptr.getline(y, 5);
		fptr.getline(x, n);
		str temp{ static_cast<int>(strlen(x)), x };
		if (temp[0] != '\0') {
			list.push(q_mbti(atoi(y), temp));
			test.push(q_mbti(atoi(y), temp));
		}
	} while (!fptr.eof());
	test.test(max);
	fptr.close();
	delete[] x;

	return 0;
}