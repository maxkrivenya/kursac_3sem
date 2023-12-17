#pragma once
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "qSport.h"
#include "QDriver.h"
#define shmish_size 8

using namespace std;

class User {
	friend class qDriver;
	struct mbti {
		int ei;
		int sn;
		int tf;
		int	jp;
	};
private:
	string pass;
protected:
	string id;
	string name;
	char gender;
	string curr_mbti;
	struct mbti type;
	int shmish[shmish_size];
	bool driver;
	float sports;
public:
	User(string name = "Guest", string pass = " ", int id = 0, char gender = 'm') {
		this->name = name;
		this->pass = pass;
		this->id = id;
		this->gender = gender;
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
		this->gender = that.gender;
		this->driver = that.driver;
		this->type.ei = that.type.ei;
		this->type.sn = that.type.sn;
		this->type.tf = that.type.tf;
		this->type.jp = that.type.jp;
	}
	~User() {;}
	friend ostream& operator<<(ostream& os, const User& user);
	void save();
	void auth();
	void updMbti(int type, qMbti q);
	void updShmishek(int val, qShmishek q);

	void setId(string newId);
	void setName(string newName);
	void setPassword(string newPass);
	void setGender(char newGender);
	void setMbti(string newMbti);
	void setDriver(bool newDriver);
	void setSports(float newSports);


	string getId();
	string getName();
	char getGender();
	string getMbti();
	bool getDriver();
	float getSports();
};