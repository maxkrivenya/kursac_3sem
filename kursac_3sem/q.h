#pragma once
#include <iostream>
#include <iomanip>
//using namespace std;

template <class T> class Q {
	struct node {
		T data;
		struct node* prev;
		struct node* next;
	};
	struct node* root;
	void push(struct node**, T val);
	void node_add(struct node**, T, struct node** = NULL);
	void show(struct node*);
public:
	Q();
	~Q();
	void Q_delete();
	void push(T val);
	void show();
	void test();
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
void Q<T>::push(struct node** root, T val) {
	if (*root == NULL) {
		node_add(&(*root), val);
		return;
	}
	struct node* temp1 = (*root)->next;
	struct node* temp2 = (*root);
	while (temp1 != NULL) {
		temp1 = temp1->next;
		temp2 = temp2->next;
	}
	node_add(&temp1, val, &temp2);
}
template <class T>
void Q<T>::node_add(struct node** place, T val, struct node** prev) {
	struct node* temp = new struct node;
	temp->data = val;
	temp->next = NULL;
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
void Q<T>::push(T val) {
	push(&(this->root), val);
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
void Q<T>::test() {
	if (this->root == NULL) {
		std::cout << std::endl << "Empty list." << std::endl;
		return;
	}
	struct node* temp = this->root;
	int result = 0;
	while (temp != NULL) {

		int choice = 0;
		system("CLS");
		std::cout << std::endl << temp->data << std::endl;
		std::cout << std::endl << "//Input number" << std::endl;
		std::cin >> choice;
		switch (choice) {
		case -1: {temp = temp->prev; break; }
		case 0: {std::cout << std::endl << "Test ended." << std::endl; break; }
		case 1: {result += 1; temp = temp->next;  break; };
		case 2: {result -= 2; temp = temp->next;  break; };
		case 3: {result *= 3; temp = temp->next;  break; };
		default:{std::cout << std::endl << "Wrong input." << std::endl; }
		}
	}
	std::cout << std::endl << "Your result is: " << result << std::endl;
}