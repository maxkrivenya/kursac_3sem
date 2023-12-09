#pragma once
#include <iostream>
#include <iomanip>

template <class T>
class binTree {
	struct node {
		int depth;
		int shift;
		T value;
		struct node* left;
		struct node* right;
		struct node* prev;
	};
public:
	binTree();										//конструктор
	~binTree();										//деструктор
	int size() { return this->treeSize; }			//геттер размера
	int groot() { return this->root->value; }		//геттер значения корня
	int gbegin() { return this->begin; }			//геттер мин. значения
	int gend() { return this->end; }				//геттер макс значения
	void push_s(T value, int depth = 0);			//доюавление элемента
	void log();										//вывод дерева
	void deleteLog(struct node* node);				//удаление дерева
	void deleteBranch(struct node* node);			//удаление ветви
	void find(T);									//поиск элемента
private:
	struct node* root;								//корень дерева
	int treeSize;									//колво элементов дерева
	int begin;										//мин. элемент
	int end;										//макс. элемент
	void push(struct node** node_left, struct node** prev, T val, int depth = 0, int shift = 0);	//поиск позиции нового элемента в дереве
	void node_add(struct node** node, T val, int depth = 0, int shift = 0);							//добавление нового элемента на позицию
};
template  <class T>
void binTree<T>::find(T value) {
	struct node* temp = root;
	while (temp != NULL && temp->value != value) {
		if (value == temp->value) {
			std::cout << std::endl << "Found! " << temp->value;
			if (temp->left == NULL) {
				std::cout << "NULL";
			}
			else {
				std::cout << temp->left->value;
			}
			std::cout << " ";
			if (temp->right == NULL) {
				std::cout << "NULL";
			}
			else {
				std::cout << temp->right->value;
			}
			std::cout << std::endl;
			return;
		}
		if (value < temp->value) {
			temp = temp->left;
		}
		else {
			temp = temp->right;
		}
	}
	std::cout << std::endl << "Haven't found " << value << std::endl;
}

template <class T>
binTree<T>::binTree() {
	this->root = NULL;
	this->treeSize = 0;
}
template <class T>
binTree<T>::~binTree() {
	deleteLog(this->root);
}
template <class T>
void binTree<T>::deleteLog(struct node* node) {
	struct node* temp1 = node;
	struct node* temp2 = NULL;
	while (temp1 != NULL) {

		if (temp1->left != NULL) {
			struct node* temp2 = temp1->left;
		}
		deleteBranch(temp1);
		temp1 = temp2;
	}
}

template <class T>
void binTree<T>::deleteBranch(struct node* node) {
	if (node != NULL) {
		deleteBranch(node->right);
	}
	delete node;
}

template <class T>
void binTree<T>::push_s(T val, int shift) {
	if (this->root == NULL) {
		this->begin = val;
		this->end = val;
	}
	if (val < this->begin) {
		this->begin = val;
		struct node* temp = this->root;
		while (temp->left != NULL) {
			temp = temp->left;
		}
		node_add(&(temp->left), val, temp->depth + 1);
		return;
	}
	if (val > this->end) {
		this->end = val;
		struct node* temp = this->root;
		while (temp->right != NULL) {
			temp = temp->right;
		}
		node_add(&(temp->right), val, temp->depth + 1, temp->shift + 1);
		return;
	}
	if (this->root == NULL) {
		node_add(&(this->root), val);
		return;
	}
	push(&(this->root->left), &(this->root), val, shift);
}

template <class T>
void binTree<T>::push(struct node** node_left, struct node** prev, T value, int depth, int shift) {

	if (*node_left == NULL && prev == NULL) {
		std::cout << std::endl << "Sorry! Unexpected error" << std::endl;
		return;
	}
	if ((*node_left)->right == NULL) {
		node_add(&((*node_left)->right), value, depth + 1, shift + 1);
		(*prev)->right->left = (*node_left)->right;
		return;
	}
	if ((*node_left) == NULL && ((*prev)->right != NULL)) {
		std::cout << std::endl << "Unexpected error: node is NULL" << std::endl;
		return;
	}


	if (value <= (*node_left)->value) {
		push((&(*node_left)->left), node_left, value);
	}
	if (value > (*node_left)->value) {
		push((&(*node_left)->right), node_left, value, (*node_left)->depth + 1, (*node_left)->shift + 1);
	}
}
template <class T>
void binTree<T>::node_add(struct node** node, T val, int depth, int shift) {
	struct node* temp = new struct node;
	temp->value = val;
	temp->left = NULL;
	temp->right = NULL;
	temp->depth = depth;
	temp->shift = shift;
	*node = temp;
	this->treeSize++;
}

template <class T>
void binTree<T>::log() {
	std::cout << std::endl << "Size: " << this->treeSize << std::endl << "Begin = " << this->begin << ", End = " << this->end << std::endl;
	struct node* temp1 = root;
	while (temp1 != NULL) {
		struct node* temp2 = temp1;
		while (temp2 != NULL) {
			std::cout << " " << temp2->value;
			temp2 = temp2->right;
		}
		temp1 = temp1->left;
		std::cout << std::endl;
	}
}
