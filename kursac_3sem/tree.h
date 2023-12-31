﻿#pragma once
#include <iostream>
#include <iomanip>
template <typename Tree>
class TreeIterator {
	using NodeType = typename Tree::NodeType;
	using PointerType = NodeType*;
	using ReferenceType = NodeType&;

public:
	TreeIterator(PointerType ptr)
		:m_Ptr(ptr) {}

	TreeIterator& operator+() {
		m_Ptr = m_Ptr->next_left;
		return *this;
	}
	TreeIterator& operator++() {
		m_Ptr = m_Ptr->next_right;
		return *this;
	}
	TreeIterator& operator-() {
		m_Ptr = m_Ptr->prev_left;
		return *this;
	}
	TreeIterator& operator--() {
		m_Ptr = m_Ptr->prev_right;
		return *this;
	}
	PointerType operator->() {
		return m_Ptr;
	}
	ReferenceType operator*() {
		return *m_Ptr;
	}
	bool operator==(const TreeIterator& other) {
		return (m_Ptr == other.m_Ptr);
	}
	bool operator!=(const TreeIterator& other) {
		return (m_Ptr != other.m_Ptr);
	}
private:
	PointerType m_Ptr;
};



template <class T>
class Tree {
	class Node {
		friend class Tree;
		template <class T>
		friend class TreeIterator;
	protected:
		Node* next_left;
		Node* next_right;
		Node* prev_left;
		Node* prev_right;
	public:
		int depth;
		int shift;
		T value;
		bool IsntNull(int a) {
			switch (a) {
			case 1: return (this->prev_left == NULL);
			case 2: return (this->prev_right == NULL);
			case 3: return (this->next_left == NULL);
			case 4: return (this->next_right == NULL);
			default:exit(1);
			}
		}
		//public:
		Node(T value, Node** prev_left = NULL, Node** prev_right = NULL) {
			this->value = value;
			this->depth = 0;
			this->shift = 0;
			this->next_left = NULL;
			this->next_right = NULL;
			this->prev_left = NULL;
			this->prev_right = NULL;
			if (prev_left != NULL) {
				if (*prev_left != NULL) {
					this->prev_left = *(prev_left);
					this->depth = (*prev_left)->depth + 1;
					this->shift = (*prev_left)->shift + 1;
				}
			}
			if (prev_right != NULL) {
				if (*prev_right != NULL) {
					this->prev_right = *(prev_right);
					this->depth = (*prev_right)->depth + 1;
					this->shift = (*prev_right)->shift;
				}
			}
		}
		~Node() { ; }
		friend ostream& operator<<(ostream& os, Node that) {
			os << that.value;
			return os;
		}
	};
public:
	Tree();
	~Tree();

	void nodeAdd(T value, Node** prev_left = NULL, Node** prev_right = NULL);

	void push_question(T value);

	void log();
	void deleteLog(Node* node);
	void deleteBranch(Node* node);
	void circle();
	bool isEmpty();
protected:
	Node* test_begin;
	Node* test_end;
public:
	using ValueType = T;
	using NodeType = class Node;
	using Iterator = TreeIterator<Tree<T>>;
	Iterator begin() {
		return Iterator(test_begin);
	}
	Iterator end() {
		return Iterator(test_end);
	}
};

template <class T>
Tree<T>::Tree() {
	this->test_begin = NULL;
	this->test_end = NULL;
}

template <class T>
Tree<T>::~Tree() {
	//deleteLog(this->test_begin);
}

template <class T>
bool Tree<T> :: isEmpty() {
	if (this->test_begin == NULL) {
		return true;
	}
	return false;
}

template <class T>
void Tree<T>::deleteLog(Node* node) {
	Node* temp1 = node;
	Node* temp2 = NULL;
	while (temp1 != NULL) {

		if (temp1->next_left != NULL) {
			Node* temp2 = temp1->next_left;
		}
		deleteBranch(temp1);
		temp1 = temp2;
	}
}

template <class T>
void Tree<T>::deleteBranch(Node* node) {
	if (node != NULL) {
		deleteBranch(node->next_right);
	}
	delete node;
}

template <class T>
void Tree<T>::push_question(T value) {
	if (this->test_begin == NULL) {
		nodeAdd(value);
		return;
	}
	Node* temp1 = this->test_begin;
	if (!(value.getType())) {
		while (temp1->next_left != NULL) {
			temp1 = temp1->next_left;
		}
		nodeAdd(value, NULL, &temp1);
		this->test_end = this->test_end->next_left;
		return;
	}
	if (temp1->next_right == NULL) {
		nodeAdd(value, &temp1);
		return;
	}
	Node* temp2 = this->test_begin;
	temp1 = temp1->next_right;
	temp2 = temp2->next_left;

	while (temp1->value.getType() != value.getType() && temp1->next_right != NULL) {
		temp1 = temp1->next_right;
		temp2 = temp2->next_right;
		if (temp1->value.getType() != value.getType() && temp1->next_right == NULL) {
			break;
		}
	}
	if (temp1->value.getType() != value.getType() && temp1->next_right == NULL) {
		nodeAdd(value, &temp1);
	}
	while (temp1->next_left != NULL) {
		temp1 = temp1->next_left;
		temp2 = temp2->next_left;
	}
	nodeAdd(value, &temp2, &temp1);
	return;
}

template <class T>
void Tree<T>::nodeAdd(T val, Node** prev_left, Node** prev_right) {
	if (prev_left == NULL && prev_right == NULL) {
		Node* temp = new Node(val);
		this->test_begin = temp;
		this->test_end = temp;
		return;
	}
	Node* temp = new Node(val, prev_left, prev_right);
	if (prev_left != NULL) {
		if (*prev_left != NULL) {
			(*prev_left)->next_right = temp;
		}
	}
	if (prev_right != NULL) {
		if (*prev_right != NULL) {
			(*prev_right)->next_left = temp;
		}
	}
}

template <class T>
void Tree<T>::log() {

	Node* temp1 = this->test_begin;

	while (temp1 != NULL) {

		Node* temp2 = temp1;

		while (temp2 != NULL) {
			std::cout << temp2->value << std::endl;
			temp2 = temp2->next_left;
		}

		temp1 = temp1->next_right;
		std::cout << std::endl;
	}
}

template <class T>
void Tree<T>::circle() {
	Node* temp = this->test_begin;
	std::cout << temp->value;
	while (temp->next_left != NULL) {
		temp = temp->next_left;
	}
	std::cout << temp->value;
	while (temp->next_right != NULL) {
		temp = temp->next_right;
	}
	std::cout << temp->value;
	while (temp->prev_right != NULL) {
		temp = temp->prev_right;
	}
	std::cout << temp->value;
	while (temp->prev_left != NULL) {
		temp = temp->prev_left;
	}
	std::cout << temp->value;
}