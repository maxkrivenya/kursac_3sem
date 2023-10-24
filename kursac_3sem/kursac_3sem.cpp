#include "q.h"
#include "stroki.h"
#include <fstream>
#define n 20
using namespace std;
int main() {
	ifstream fptr("data.txt");
	Q<str> shit;
	int flg = 0;
	do {
		//cout << endl << "Input next node " << setw(5);
		//cin >> poo;
		char* x = new char[n];
		//fptr >> x;
		fptr.getline(x, n);
		str poo{ n, x };
		if (poo[0] == '0');
		shit.push(poo);
	} while (!fptr.eof());
	//shit.show();
	shit.test();
	fptr.close();
	return 0;
}				