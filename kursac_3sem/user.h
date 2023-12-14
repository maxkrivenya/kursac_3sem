#pragma once
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

#include "qSport.h"
#include "QDriver.h"

using namespace std;

#define ket_size 19
#define shmish_size 8
#define id_size 5
class User {
	friend class qDriver;
	struct mbti {
		int ei;
		int sn;
		int tf;
		int	jp;
	};
protected:
	string name;
	string pass;
	string id;
	string curr_mbti;
	bool male = 0;
	struct mbti type;
	int ket[ket_size];
	int shmish[shmish_size];
	bool driver;
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
		this->driver = false;
	}
	User(const User& that) {
		this->name = that.name;
		this->pass = that.pass;
		this->id = that.id;
		this->male = that.male;
		this->driver = that.driver;
		this->type.ei = that.type.ei;
		this->type.sn = that.type.sn;
		this->type.tf = that.type.tf;
		this->type.jp = that.type.jp;
	}
	~User() {;}
	friend ostream& operator<<(ostream& os, const User& user);
	template<class qMbti>
	friend void mbti_test(List<qMbti> list, User& user);
	void save();
	void auth();
	void updMbti(int, qMbti q);
	void upd_driver(bool);
	//void upd_kettel(int, qMbti q);
};