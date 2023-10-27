#pragma once
#include <iostream>
#include <iomanip>
#include "user.h"
#include "Question.h"
//using namespace std;

template <class T>  
class Q{
	friend class User;
	friend class Question;
	struct  node {
		T data;
		
		  node* prev = NULL;
		  node* next = NULL;
		  node() {};
	};
	node* root;
	void push(  node**,T val);
	void node_add(  node**, T,   node** = nullptr);
	void show(  node*);
public:
	Q();
	~Q();
	void Q_delete();
	void push(T val );
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
Q<T> ::~Q() {
	Q_delete();
}
template <class T> 
void Q<T> ::Q_delete() {
	  node* t1 = root;
	if (t1 == NULL) {
		return;
	}
	  node* t2 = NULL;
	while (t1 != NULL) {
		t2 = t1->next;
		delete t1;
		t1 = t2;
	}
}
template <class T> 
void Q<T> ::push(  node** root,T val) {
	if (*root == NULL) {
		node_add(&(*root), val);
		return;
	}
	  node* temp1 = (*root)->next;
	  node* temp2 = (*root);
	while (temp1 != NULL) {
		temp1 = temp1->next;
		temp2 = temp2->next;
	}
	node_add(&temp1, val, &temp2);
}
template <class T> 
void Q<T> ::node_add(  node** place,T val,  node** prev) {
	node* temp = new node;
	temp->data = val;
	temp->next = NULL;
	//temp->type = type;
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
void Q<T> ::push(T val) {
	push(&(this->root), val);
}
template <class T> 
void Q<T> ::show(  node* root) {
	  node* temp = root;
	std::cout << std::endl << "Printing..." << std::endl;
	while (temp != NULL) {
		std::cout << std::setw(2);
		std::cout << temp->data;
		temp = temp->next;
	}
}
template <class T> 
void Q<T> ::show() {
	show(this->root);
}
template <class T> 
void Q<T> ::test(User user) {
	if (this->root == NULL) {
		std::cout << std::endl << "Empty list." << std::endl;
		return;
	}
	int result = 0;
	std::cout << std::endl << "Welcome to the MBTI Q." 
		<< std::endl << "The rules are simple:" 
		<< std::endl << "\tYou will be shown a statement." 
		<< std::endl << "\tPlease input a number from -3 to 3 as your answer depending on how much you agree with the statement." 
		<< std::endl <<"To start the Q, input any number." << std::endl;
		cin >> result;
	result = 0;
	  node* temp = this->root;
	while (temp != NULL) {
		int choice = 0;
		system("CLS");
		//std::cout << temp->data;
		temp->data.sout();
		std::cout << std::endl << "//Input number" << std::endl;
		std::cin >> choice;
		//this->choice(user, choice);
		temp = temp->next;
		//switch (choice) {
		//case -1: {temp = temp->prev; break; }
		//case 0: {std::cout << std::endl << "Q ended." << std::endl; break; }
		//case 1: {result += 1; temp = temp->next;  break; };
		//case 2: {result -= 2; temp = temp->next;  break; };
		//case 3: {result *= 3; temp = temp->next;  break; };
		//default:{std::cout << std::endl << "Wrong input." << std::endl; }
		//}
	}
	std::cout << std::endl << "Your result is: " << user << std::endl;
}

//template <class T> 
//void Q<T> ::choice(User& user, T val) {
//	switch (type) {
//	case 1: {user.upd_ei(val); break; }
//	case 2: {user.upd_sn(val); break; }
//	case 3: {user.upd_tf(val); break; }
//	case 4: {user.upd_jp(val); break; }
//	}
//}