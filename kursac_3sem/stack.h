#pragma once
#include <iostream>
#include <iomanip>
#include "kursac_functions.h"

template <class T> class stack {
	struct node {
		struct node* next;
		T val;
	};
	struct node* root;

public:
	stack(){
		this->root = NULL;
		std::cout << std::endl << "Constr stack" << std::endl;
	}
	~stack() {
		deleteStack();
	}
	void push(T val);
	T pop();
	void show();
	bool isEmpty();
private:
	void deleteStack();
};

template <class T>
void stack<T>::deleteStack() {
	std::cout << std::endl << "Stack deleted" << std::endl;
}

template <class T>
void stack<T>::push(T s) {
	struct node* temp = new struct node;
	temp->val = s;
	temp->next = this->root;
	this->root = temp;
}

template <class T>
void stack<T>::show() {
	std::cout << std::endl << "Showing stack..." << std::endl;
	struct node* temp = this->root;
	while (temp != NULL) {
		std::cout << temp->val << std::endl;
		temp = temp->next;
	}
	std::cout << "End of stack" << std::endl;
}

template <class T>
T stack<T>::pop() {
	if (this->root == NULL) {
		std::cout << std::endl << "stack empty";
		exit(1);
	}
	T temp = this->root->val;
	this->root = this->root->next;
	return temp;
}

template <class T>
bool stack<T>::isEmpty() {
	if (this->root == NULL) {
		return true;
	}
	return false;
}