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
	//mbtiTest(max);
	//SportsTest(max);
	DriverTest(max);
	//Tree<qDriver> test = DriverTestInit();
	//test.log();
	return 0;
}