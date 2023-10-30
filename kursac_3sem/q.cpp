#include "testcd.h"

Test::Test() {
	this->root = NULL;
}
 
Test ::~Test() {
	Test_delete();
}
 
void Test::Test_delete() {
	node* t1 = root;
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
 
void Test::push(node** root, q_mbti val) {
	if (*root == NULL) {
		node_add(&(*root), val);
		return;
	}
	node* temp1 = (*root)->next;
	node* temp2 = (*root);
	while (temp1 != NULL) {
		temp1 = temp1->next;
		temp2 = temp2->next;
	}
	node_add(&temp1, val, &temp2);
}
 
void Test::node_add(node** place, q_mbti val, node** prev) {
	node* temp = new node;
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
 
void Test::push(q_mbti val) {
	push(&(this->root), val);
}
 
void Test::show(node* root) {
	node* temp = root;
	std::cout << std::endl << "Printing..." << std::endl;
	while (temp != NULL) {
		std::cout << std::setw(2);
		std::cout << temp->data;
		temp = temp->next;
	}
}
 
void Test::show() {
	show(this->root);
}
 
void Test::test(User user) {
	if (this->root == NULL) {
		std::cout << std::endl << "Empty list." << std::endl;
		return;
	}
	int result = 0;
	std::cout << std::endl << "Welcome to the MBTI Test."
		<< std::endl << "The rules are simple:"
		<< std::endl << "\tYou will be shown a statement."
		<< std::endl << "\tPlease input a number from -3 to 3 as your answer depending on how much you agree with the statement."
		<< std::endl << "To start the Test, input any number." << std::endl << std::endl << "Your answer:  ";;
	cin >> result;
	result = 0;
	node* temp = this->root;
	while (temp != NULL) {
		int choice = 0;
		system("CLS");
		cout << temp->data;
		std::cout << std::endl << "Your answer:  ";
		std::cin >> choice;
		user.upd_mbti(choice, temp->data);
		temp = temp->next;
	}
	system("CLS");
	std::cout << std::endl << "Your result is: " << user << std::endl;
}