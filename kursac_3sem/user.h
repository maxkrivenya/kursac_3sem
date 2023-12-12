#pragma once
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "Question.h"
#include "test.h"
#include "list.h"
#define ket_size 19
#define shmish_size 8
#define id_size 5
class User {
	struct mbti {
		int ei;
		int sn;
		int tf;
		int	jp;
	};
public:
	User(string name = "Guest", string pass = " ", int id = 0, bool female = false) {
		this->name = name;
		this->pass = pass;
		this->id = id;
		this->male = female;
		this->type.ei = 0;
		this->type.sn = 0;
		this->type.tf = 0;
		this->type.jp = 0;
	}
	User(const User& u) {
		this->name = u.name;
		this->pass = u.pass;
		this->id = u.id;
		this->male = u.male;
		//this->type.ei = u.type.ei;
		//this->type.sn = u.type.sn;
		//this->type.tf = u.type.tf;
		//this->type.jp = u.type.jp;
	}
	~User() {;}
	friend ostream& operator<<(ostream& os, const User& user);
	friend void mbti_test(List<q_mbti> list, User& user);
	bool male = 0;
	void save();
	void auth();
protected:
	string name;
	string pass;
	string id;	
	struct mbti type;
	int ket[ket_size];
	int shmish[shmish_size];
	void upd_mbti(int, q_mbti q);
	void upd_kettel(int, q_mbti q);
};