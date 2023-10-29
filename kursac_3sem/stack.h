#pragma once
#include <iostream>
#include <iomanip>

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
	void show();
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