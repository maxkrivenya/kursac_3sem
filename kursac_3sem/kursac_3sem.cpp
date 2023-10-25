#include "q.h"
#include "stroki.h"
#include "user.h"
#include <fstream>
#define n 80
using namespace std;
int main() {
	str m{ 3, "Max" };
	User max { m };
	ifstream fptr("data.txt");
	Q<str> shit;
	int flg = 0;
	char* x = new char[n];
	char* y = new char[10];
	fptr.getline(y, 5);
	do {
		fptr.getline(y, 5);
		fptr.getline(x, n);
		str poo{ static_cast<int>(strlen(x)), x};
		if (poo[0] == '0');
		shit.push(poo, atoi(y));
	} while (!fptr.eof());
	shit.test(max);
	fptr.close();
	delete[] x;
	return 0;
}				