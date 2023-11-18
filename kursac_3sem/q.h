#pragma once
#include <iostream>
#include <iomanip>
using namespace std;
template <class T>
class Q {
	struct node {
		struct node* next;
		struct node* prev;
		T value;
	};
	struct node* head;
	struct node* tail;

public:
	Q() {
		this->head = NULL;
		this->tail = NULL;
		cout << endl << "Constr Q" << endl;
	}
	~Q() {
		cout << endl << "Destr Q" << endl;
	}
	void Q_delete();
	void show();
	void push(node** head, T val);
	void node_add(node** place, T val, node** prev = NULL);
	void push(T val);
	void show(node* head);
};

template <class T>
void Q<T>::Q_delete() {
	node* t1 = head;
	this->head = NULL;
	this->tail = NULL;

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
void Q<T>::push(node** head, T val) {
	if (*head == NULL) {
		node_add(&(*head), val);
		return;
	}
	node* temp1 = (*head)->next;
	node* temp2 = (*head);
	while (temp1 != NULL) {
		temp1 = temp1->next;
		temp2 = temp2->next;
	}
	node_add(&temp1, val, &temp2);
}

template <class T>
void Q<T>::node_add(node** place, T val, node** prev) {
	node* temp = new node;
	temp->value = val;
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
	push(&(this->head), val);
}

template <class T>
void Q<T>::show(node* head) {
	node* temp = head;
	cout << endl << "Printing..." << endl;
	while (temp != NULL) {
		//cout << setw(2);
		cout << temp->value;
		temp = temp->next;
	}
}

template <class T>
void Q<T>::show() {
	show(this->head);
}