#pragma once
#include <iostream>
#include <iomanip>
#include "user.h"
#include "Question.h"
//using namespace std;

template <class T> class Q  {
	friend class User;
	struct node {
		T data;
		int type;
		struct node* prev = NULL;
		struct node* next = NULL;
	};
	struct node* root;
	void push(struct node**, T val, int type);
	void node_add(struct node**, T, int type = 0, struct node** = NULL);
	void show(struct node*);
public:
	Q();
	~Q();
	void Q_delete();
	void push(T val, int type);
	void show();
	void test(User);
	void choice(User&, int, int);
	//friend void User::upd_ei(int);
};

template <class T>
Q<T>::Q(){
	this->root = NULL;
}
template <class T>
Q<T>::~Q() {
	Q_delete();
}
template <class T>
void Q<T>::Q_delete() {
	struct node* t1 = root;
	if (t1 == NULL) {
		return;
	}
	struct node* t2 = NULL;
	while (t1 != NULL) {
		t2 = t1->next;
		delete t1;
		t1 = t2;
	}
}
template <class T>
void Q<T>::push(struct node** root, T val, int type) {
	if (*root == NULL) {
		node_add(&(*root), val, type)	;
		return;
	}
	struct node* temp1 = (*root)->next;
	struct node* temp2 = (*root);
	while (temp1 != NULL) {
		temp1 = temp1->next;
		temp2 = temp2->next;
	}
	node_add(&temp1, val, type, &temp2);
}
template <class T>
void Q<T>::node_add(struct node** place, T val, int type, struct node** prev) {
	struct node* temp = new struct node;
	temp->data = val;
	temp->next = NULL;
	temp->type = type;
	if (prev != NULL) {
		(*prev)->next = temp;
		temp->prev = *prev;
	}
	else {
		temp->prev = NULL;
	}
	*place = temp;
}
template <class T>
void Q<T>::push(T val, int type) {
	push(&(this->root), val, type);
}
template <class T>
void Q<T>::show(struct node* root) {
	struct node* temp = root;
	std::cout << std::endl << "Printing..." << std::endl;
	while (temp != NULL) {
		std::cout << std::setw(2);
		std::cout << temp->data;
		temp = temp->next;
	}
}
template <class T>
void Q<T>::show() {
	show(this->root);
}
template <class T>
void Q<T>::test(User user) {
	if (this->root == NULL) {
		std::cout << std::endl << "Empty list." << std::endl;
		return;
	}
	int result = 0;
	std::cout << std::endl << "Welcome to the MBTI test." 
		<< std::endl << "The rules are simple:" 
		<< std::endl << "\tYou will be shown a statement." 
		<< std::endl << "\tPlease input a number from -3 to 3 as your answer depending on how much you agree with the statement." 
		<< std::endl <<"To start the test, input any number." << std::endl;
		cin >> result;
	result = 0;
	struct node* temp = this->root;
	while (temp != NULL) {
		int choice = 0;
		system("CLS");
		std::cout << std::endl << temp->data << std::endl;
		std::cout << std::endl << "//Input number" << std::endl;
		std::cin >> choice;
		this->choice(user, choice, temp->type);
		temp = temp->next;
		//switch (choice) {
		//case -1: {temp = temp->prev; break; }
		//case 0: {std::cout << std::endl << "Test ended." << std::endl; break; }
		//case 1: {result += 1; temp = temp->next;  break; };
		//case 2: {result -= 2; temp = temp->next;  break; };
		//case 3: {result *= 3; temp = temp->next;  break; };
		//default:{std::cout << std::endl << "Wrong input." << std::endl; }
		//}
	}
	std::cout << std::endl << "Your result is: " << user << std::endl;
}

template <class T>
void Q<T>::choice(User& user, int val, int type) {
	switch (type) {
	case 1: {user.upd_ei(val); break; }
	case 2: {user.upd_sn(val); break; }
	case 3: {user.upd_tf(val); break; }
	case 4: {user.upd_jp(val); break; }
	}
}