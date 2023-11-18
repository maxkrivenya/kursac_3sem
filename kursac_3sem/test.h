#pragma once
#include <iostream>
#include <iomanip>
#include "user.h"
#include "Question.h"

class Test {
	friend class User;
	friend class Question;
	struct  node {
		q_mbti data;
		node* prev = NULL;
		node* next = NULL;
		//node() {};
	};
	node* root;
	void push(node**, q_mbti val);
	void node_add(node**, q_mbti val, node** = nullptr);
	void show(node*);
	void Test_delete();
public:
	Test();
	~Test();
	void push(q_mbti val);
	void show();
	void test(User&);
	void choice(User&, int, int);
	//friend void User::upd_ei(int);
};

class Test_Shmisheka : public Test {
public:
	Test_Shmisheka();
	~Test_Shmisheka();
	void test(User&);
};