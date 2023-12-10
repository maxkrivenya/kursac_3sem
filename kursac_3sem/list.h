#pragma once
#include <iostream>

template <typename List>
class ListIterator {
	using NodeType = typename List::NodeType;
	using PointerType = NodeType*;
	using ReferenceType = NodeType&;

public:
	ListIterator(PointerType ptr)
		:m_Ptr(ptr){}
	ListIterator& operator++(){
		m_Ptr = m_Ptr->next;
		return *this;
	}
	ListIterator operator++(int) {
		ListIterator iterator = *this;
		++(*this);
		return iterator;
	}
	ListIterator& operator--() {
		m_Ptr--;
		return *this;
	}
	ListIterator operator--(int) {
		ListIterator iterator = *this;
		--(*this);
		return iterator;
	}
	ReferenceType operator[](int index) {
		return *(m_Ptr + index);
	}
	PointerType operator->() {
		return m_Ptr;
	}
	ReferenceType operator*() {
		return *m_Ptr;
	}
	bool operator==(const ListIterator& other) {
		return (m_Ptr == other.m_Ptr);
	}
	bool operator!=(const ListIterator& other) {
		return (m_Ptr != other.m_Ptr);
	}
private:
	PointerType m_Ptr;
};

template <class T> class List {
public:
	class Node {
		friend class List;
		template <class what>
		friend class ListIterator;
	public:
		T value;
		Node(T value) {
			this->value = value;
			this->next = NULL;
			this->prev = NULL;
		}
	protected:
		Node* next;
		Node* prev;
	};
//public:
	using ValueType = T;
	using NodeType = class Node;
	using Iterator = ListIterator<List<T>>;
	List() {
		this->head = NULL;
	}
	virtual ~List() { ; }
	void push(T value);
	void out();
	bool isEmpty();
	Iterator begin() {
		return Iterator(head);
	}
	Iterator end() {
		return Iterator(tail->next);
	}
protected:
	Node* head;
	Node* tail;
};

template <class T>
void List<T>::out() {
	Node* temp = this->head;
	do {
		std::cout << temp->value << "";
		temp = temp->next;
	} while (temp != NULL);
}

template <class T>
void List<T>::push(T value) {
	Node* node = new Node(value);

	if (this->head == NULL) {
		this->head = node;
		return;
	}

	Node* temp = this->head;
	while (temp->next != NULL)
		temp = temp->next;
	
	temp->next = node;
	node->prev = temp;
	this->tail = node;
	return;
}

template <class T>
bool List<T>::isEmpty() {
	return (this->head == NULL);
}