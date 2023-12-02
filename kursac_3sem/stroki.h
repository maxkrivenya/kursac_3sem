#pragma once
#include <iostream>
#include <iomanip>
#define N 20
using namespace std;

class str {
	friend class User;
//protected:
public:
	int len;
	char* string;

	str(int l = 0, const char* s = NULL) {
		if (!l) { return; }
		l++;
		this->len = l;
		this->string = new char[len];
		if (s != NULL) {
			strcpy_s(string, len, s);
		}
		else {
			//cout << "Empty string" << endl;
		}
		//cout << "Const str" << endl;
	}			//???????????
	str(const str& s) {
		this->len = s.len;
		this->string = new char[len];
		strcpy_s(this->string, len, s.string);
		//cout << "Copied str" << endl;
	}								//??????????? ???????????
	~str() {
		delete[] this->string;
		//cout << "Destr str" << endl;
	}											//??????????
	char operator[](int n);
	str operator+ (const str& s);							//???????? ? ????????
	str operator*= (const char*);							//???????? ? ????? ???????
	void operator= (const str& s);							//????????????
	void operator++();										//?????????
	void operator--();										//?????????
	str operator()(int, int);								//????????? ?????????
	int operator>(str);										//?????????
	friend std::istream& operator>>(istream& is, str& obj);	//????
	friend std::ostream& operator<<(ostream& os, str& obj);	//?????
	int operator<(str cmp);

	int operator==(str& temp) {
		for (int i = 0; i < temp.len && i < this->len; i++) {
			if (this->string[i] != temp[i]) {
				return 0;
			}
		}
		return 1;
	}
/*
	str firstWord() {
		str temp{ 20 };
		int i = 0;
		while (!isalpha(this->string[i]) && i < this->len) {
			i++;
		}
		int j = 0;
		while (isalpha(this->string[i]) && j < temp.len && i < this->len) {
			temp.string[j] = this->string[i];
			j++; i++;
		}
		temp.string[j] = '\0';
		str temp2{ j, temp.string };
		return temp2;
	}
*/
	str nthWord(int n = 1) {
		str temp{ N };
		int i = 0;
		int j = 0;

		for (int k = 1; k < n; k++) {
			while (!isalpha(this->string[i]) && i < this->len) {
				i++;
			}
			while (isalpha(this->string[i]) && i < this->len) {
				i++;
			}
		}

		while (!isalpha(this->string[i]) && i < this->len) {
			i++;
		}
		while (isalpha(this->string[i]) && j < temp.len && i < this->len) {
			temp.string[j] = this->string[i];
			i++; j++;
		}
		temp.string[j] = '\0';
		str temp2{ j, temp.string };
		return temp2;
	}
};

//template<typename T> class String;
//template<typename T> str operator+(const str& a);

