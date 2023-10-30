#pragma once
#include <iostream>
#include <iomanip>
#include "stroki.h"
#include "Question.h"
class User {
	friend q_mbti;
	friend Test;
	struct mbti {
		int ei;
		int sn;
		int tf;
		int	jp;
	};
public:
	User(str& name) {
		//std::cout << std::endl << "Const User..." << std::endl 
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
	friend ostream& operator<<(ostream& o, const User& user);
private:
	str name;
	struct mbti type;
protected:
	void upd_mbti(int, q_mbti q);
};