#pragma once
#include <iostream>

template <class T> class List {
	struct Node {
		T value;
		struct Node* next;
		struct Node* prev;
	};
protected:
	struct Node* head;
public:
	List() {
		this->head = NULL;
	}
	~List() { ; }
	void push(T value);
	void out();
};

template <class T>
void List<T>::out() {
	struct Node* temp = this->head;
	do {
		std::cout << temp->value << "";
		temp = temp->next;
	} while (temp != NULL);
}

template <class T>
void List<T>::push(T value) {
	struct Node* node = new struct Node;
	node->value = value;
	node->next = NULL;
	node->prev = NULL;
	if (this->head == NULL) {
		this->head = node;
		return;
	}
	struct Node* temp = head;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = node;
	node->prev = temp;
	return;
}
