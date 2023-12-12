#pragma once
#include <iostream>
#include <iomanip>
#include <fstream>
#include "stroki.h"
#include "Question.h"
#include "test.h"
#include "list.h"
#define ket_size 19
#define shmish_size 8
#define id_size 5
class User {
	friend class str;
	friend class Test;
	struct mbti {
		int ei;
		int sn;
		int tf;
		int	jp;
	};
public:
	User(str& name, str& pass, int id = 0, bool female = false) {
		strcpy_s(this->name, N - 1, name.string);
		strcpy_s(this->pass, N - 1, pass.string);
		this->id = id;
		this->male = female;
		this->type.ei = 0;
		this->type.sn = 0;
		this->type.tf = 0;
		this->type.jp = 0;
	}
	~User() {;}
	friend ostream& operator<<(ostream& os, const User& user);
	friend void mbti_test(List<q_mbti> list, User& user);
	bool male = 0;
	void save();
	User& auth();
protected:
	char name[N];
	char pass[N];
	int id;	
	struct mbti type;
	int ket[ket_size];
	int shmish[shmish_size];
	void upd_mbti(int, q_mbti q);
	void upd_kettel(int, q_mbti q);
};