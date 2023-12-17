#include "Algoritm.h"

Tree<qDriver> Algoritm::DriverTestInit() {
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

template <class T>
List<T> Algoritm::TestInit(const char* filename) {
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