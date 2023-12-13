#include <string>
#include "user.h"
#include "Question.h"
#include "kursac_functions.h"
#include <fstream>
#define n 80
using namespace std;
int main() {
	User max;
	max.auth();
	ifstream fptr("driver.txt");
	Tree<q_driver> test;
	do {
		q_driver temp;
		fptr >> temp;
		test.push_question(temp);
	} while (!fptr.eof());
	//DriverTest(test, max);
	test.log();
	fptr.close();
	return 0;
}


//int main() {
//	User max;
//	max.auth();
//	ifstream fptr("data.txt");
//	List<q_mbti> list;
//	int flg = 0;
//	string x;
//	int y;
//	getline(fptr, x);
//	do {
//		fptr >> y;
//		if (!fptr.eof()) {
//			getline(fptr, x);
//			getline(fptr, x);
//			if (x[0] != '\0') {
//				list.push(q_mbti(y, x));
//			}
//		}
//	} while (!fptr.eof());
//	mbti_test(list, max);
//	fptr.close();
//	return 0;
//}