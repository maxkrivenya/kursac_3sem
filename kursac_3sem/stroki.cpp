#include "stroki.h"
using namespace std;

char str::operator[](int n) {
	if (n < this->len) {
		return this->string[n];
	}
	return '\0';
}
str str::operator+ (const str& s) {						  
	str st{ this->len + s.len };
	int i = 0;
	for (int j = 0; j < len - 1; j++, i++) {
		st.string[i] = this->string[j];
	}
	for (int j = 0; j < s.len; j++, i++) {
		st.string[i] = s.string[j];
	}
	return st;
}

void str::operator=(const str& n) {						
	this->len = n.len;
	this->string = new char[this->len];
	strcpy_s(this->string, this->len, n.string);
}

str str::operator*= (const char* abc) {					   
	int len = strlen(abc);
	str temp{ len + 1, abc };
	cout << temp;
	return ((*this) + temp);
}

ostream& operator<<(ostream& os, str& obj) {				 
	os <<
		//'[' << obj.len << "]\t"  << 
		obj.string
		// << endl
		;
	return os;
}

istream& operator>>(istream& is, str& obj) {			
	is >> obj.len;
	obj.string = new char[obj.len];
	is >> obj.string;
	return is;
}

void str::operator++() {								
	for (int i = 0; i < this->len && this->string[i] != '\0'; i++) {
		this->string[i]++;
	}
}

void str::operator--() {									
	for (int i = 0; i < this->len - 2 && this->string[i] != '\0'; i++) {
		this->string[i]--;
	}
}

str str::operator()(int a, int b) {						 
	if (a >= b) { return NULL; }
	if (a < 0 || b > this->len) { cout << "Wrong input" << endl; return NULL; }
	str s{ b - a + 1 };
	int i = 0;
	for (int i = a; i < b; i++) {
		s.string[i - a] = this->string[i];
	}
	s.string[b - a] = '\0';
	return s;
}

int str::operator>(str cmp) {							
	return this->len > cmp.len;
}

int str::operator<(str cmp) {							
	return this->len <= cmp.len;
}