#pragma once
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
template <typename Stack>
class StackIterator {
	using NodeType = typename Stack::NodeType;
	using PointerType = NodeType*;
	using ReferenceType = NodeType&;
	friend class q_driver;

public:
	StackIterator(PointerType ptr)
		:m_Ptr(ptr) {}
	StackIterator& operator++() {
		m_Ptr = m_Ptr->next;
		return *this;
	}
	StackIterator operator++(int) {
		StackIterator iterator = *this;
		++(*this);
		return iterator;
	}
	PointerType operator->() {
		return m_Ptr;
	}
	ReferenceType operator*() {
		return *m_Ptr;
	}
	bool operator==(const StackIterator& other) {
		return (m_Ptr == other.m_Ptr);
	}
	bool operator!=(const StackIterator& other) {
		return (m_Ptr != other.m_Ptr);
	}
private:
	PointerType m_Ptr;
};

template <class T> class Stack {
	template <class T>
	friend class StackIterator;
	friend class q_driver;
	friend ostream& operator<<(ostream& os, q_driver& that);
	using ValueType = T;
	using NodeType = class Node;
	using Iterator = StackIterator<Stack<T>>;

	class Node {
		friend class Stack;
		friend class q_driver;
		template <class T>
		friend class StackIterator;
	protected:
		Node* next;
		T value;
	public:
		Node(T val, Node* next = NULL) {
			this->value = val;
			this->next = next;
		}
		~Node() {};
	};
	Node* root;
	Node* last;
	friend class q_driver;
public:
	Stack() {
		this->root = NULL;
	}
	~Stack() {
		;
	}
	void push(T val);
	T pop();
	void show();
	bool isEmpty();
	Iterator begin() {
		return Iterator(this->root);
	}
	Iterator end() {
		return Iterator(this->last->next);
	}
};


template <class T>
void Stack<T>::push(T s) {
	Node* temp = new Node(s, this->root);
	this->root = temp;
	if (this->last == NULL) {
		this->last = temp;
	}
}

template <class T>
void Stack<T>::show() {
	cout << endl << "Showing Stack..." << endl;
	for (Stack<T>::Iterator it = this->begin(); it != this->end(); it++) {
		cout << (*it).value;
	}
	cout << "End of Stack" << endl;
}

//template<class T>
//ostream& operator<<(ostream& os, Stack<T> Stack) {
//	for (Stack<T>::Iterator it = Stack.begin(); it != Stack.end(); it++) {
//		os << (*it)->value << endl;
//	}
//	return os;
//}

template <class T>
T Stack<T>::pop() {
	if (this->root == NULL) {
		cout << endl << "Stack empty";
		exit(1);
	}
	T temp = this->root->value;
	this->root = this->root->next;
	return temp;
}

template <class T>
bool Stack<T>::isEmpty() {
	if (this->root == NULL) {
		return true;
	}
	return false;
}