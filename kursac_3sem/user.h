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
private:
	string id;
	string name;
	string pass;
protected:
	char gender;
	string mbti;
	bool driver;
	float sports;
public:
	User(string name = "Guest", string pass = " ", string id = "0000", string mbti = "XXXX", char gender = 'm', int sports = 0) {
		this->name = name;
		this->pass = pass;
		this->id = id;
		this->gender = gender;
		this->mbti = mbti;
		this->driver = false;
		this->sports = sports;
	}
	User(const User& that) {
		this->name = that.name;
		this->pass = that.pass;
		this->id = that.id;
		this->gender = that.gender;
		this->mbti = that.mbti;
		this->driver = that.driver;
		this->sports = that.sports;
	}
	~User() {;}
	friend ostream& operator<<(ostream& os, const User& user);
	void save();
	void auth();
	void Register();

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