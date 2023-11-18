#pragma once
#include <iostream>
#include <iomanip>
#include <fstream>
#include "stroki.h"
#include "Question.h"
#include "test.h"
#define ket_size 19
#define shmish_size 8
class User {
	friend Test;
	struct mbti {
		int ei;
		int sn;
		int tf;
		int	jp;
	};
public:
	User(str& name, bool female = false) {
		//std::cout << std::endl << "Const User..." << std::endl 
		this->name = name;
		this->male = female;
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
	bool male = 0;
	void save();
private:
	str name;
	struct mbti type;
	int ket[ket_size];
	int shmish[shmish_size];
protected:
	void upd_mbti(int, q_mbti q);
	void upd_kettel(int, q_mbti q);
};