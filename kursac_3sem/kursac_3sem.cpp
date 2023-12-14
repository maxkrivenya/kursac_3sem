#include <string>
#include "user.h"
#include "Question.h"
#include "kursac_functions.h"
#include <fstream>
#define n 80
using namespace std;
//int main() {
//	User max;
//	max.auth();
//	ifstream fptr("driver.txt");
//	Tree<qDriver> test;
//	do {
//		qDriver temp;
//		fptr >> temp;
//		test.push_question(temp);
//	} while (!fptr.eof());
//	//DriverTest(test, max);
//	test.log();
//	fptr.close();
//	return 0;
//}


int main() {
	User max;
	max.auth();
	//mbtiTest(max);
	sportsTest(max);
	return 0;
}