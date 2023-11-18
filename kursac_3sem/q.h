#pragma once
#include <iostream>
#include <iomanip>
template <class T>
class Q{
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
		std::cout << std::endl << "Constr Q" << std::endl;
	}
	~Q() {
		std::cout << std::endl << "Destr Q" << std::endl;
	}
};