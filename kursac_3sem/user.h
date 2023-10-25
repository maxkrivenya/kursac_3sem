#pragma once
#include <iostream>
#include <iomanip>
#include "stroki.h"
class User {
	struct mbti {
		int ei;
		int sn;
		int tf;
		int	jp;
	};
public:
	User(str& name) {
		//std::cout << std::endl << "Const User..." << std::endl;
		this->name = name;
		this->type.ei = 0;
		this->type.sn = 0;
		this->type.tf = 0;
		this->type.jp = 0;
		//std::cout << std::endl << "User Constructed" << std::endl;
	}
	~User() {
		//std::cout << std::endl << "Destr User" << std::endl;
	}
	friend ostream& operator<<(ostream& o, const User& user) {
		o << std::endl << "MBTI: ";
		//<< user.type.ei << ' ' << user.type.sn << ' ' << user.type.tf << ' ' << user.type.jp << std::endl;
		if (user.type.ei >= 0) {
			o << 'E';
		}
		else {
			o << 'I';
		}
		if (user.type.sn>=0) {
			o << 'S';
		}
		else {
			o << 'N';
		}
		if (user.type.tf >= 0) {
			o << 'T';
		}
		else {
			o << 'F';
		}
		if (user.type.jp >= 0) {
			o << 'J';
		}
		else {
			o << 'P';
		}

		return o;
	}
private:
	str name;
	struct mbti type;
//protected:
public:
	void upd_ei(int);
	void upd_sn(int);
	void upd_tf(int);
	void upd_jp(int);
};