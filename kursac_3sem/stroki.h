#pragma once
#include <iostream>
#include <iomanip>
#define N 20
using namespace std;

class str {
	friend class User;
protected:
public:
	int len;
	char* string;
public:
	str(int l = 0, const char* s = NULL) {
		if (!l) { return; }
		l++;
		this->len = l;
		this->string = new char[len];
		if (s != NULL) {
			strcpy_s(string, len, s);
		}
	}
	str(const str& s) {
		this->len = s.len;
		this->string = new char[len];
		strcpy_s(this->string, len, s.string);
	}								
	~str() {
		delete[] this->string;
	}											
	char operator[](int n);
	str operator+ (const str& s);							
	str operator*= (const char*);							   
	void operator= (const str& s);							
	void operator++();										
	void operator--();										
	str operator()(int, int);								 
	int operator>(str);										
	friend std::istream& operator>>(istream& is, str& obj);	
	friend std::ostream& operator<<(ostream& os, str& obj);	
	int operator<(str cmp);
	void encode();
	void decode();
	int operator==(str& temp);

	str nthWord(int n = 1);
};
