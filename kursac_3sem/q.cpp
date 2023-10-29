#include "q.h"

//template <class T> 
Test::Test() {
	this->root = NULL;
}
//template <class T> 
Test ::~Test() {
	Test_delete();
}
//template <class T> 
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
//template <class T> 
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
//template <class T> 
void Test::node_add(node** place, q_mbti val, node** prev) {
	node* temp = new node;
	temp->data = val;
	temp->next = NULL;
	//temp->type = type;
	if (prev != NULL) {
		(*prev)->next = temp;
		temp->prev = *prev;
	}
	else {
		temp->prev = NULL;
	}
	*place = temp;
}
//template <class T> 
void Test::push(q_mbti val) {
	push(&(this->root), val);
}
//template <class T> 
void Test::show(node* root) {
	node* temp = root;
	std::cout << std::endl << "Printing..." << std::endl;
	while (temp != NULL) {
		std::cout << std::setw(2);
		std::cout << temp->data;
		temp = temp->next;
	}
}
//template <class T> 
void Test::show() {
	show(this->root);
}
//template <class T> 
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
		<< std::endl << "To start the Test, input any number." << std::endl;
	cin >> result;
	result = 0;
	node* temp = this->root;
	while (temp != NULL) {
		int choice = 0;
		system("CLS");
		//std::cout << temp->data;
		temp->data.sout();
		std::cout << std::endl << "//Input number" << std::endl;
		std::cin >> choice;
		user.upd_mbti(choice, temp->data);
		//this->choice(user, choice);
		temp = temp->next;
		//switch (choice) {
		//case -1: {temp = temp->prev; break; }
		//case 0: {std::cout << std::endl << "Test ended." << std::endl; break; }
		//case 1: {result += 1; temp = temp->next;  break; };
		//case 2: {result -= 2; temp = temp->next;  break; };
		//case 3: {result *= 3; temp = temp->next;  break; };
		//default:{std::cout << std::endl << "Wrong input." << std::endl; }
		//}
	}
	std::cout << std::endl << "Your result is: " << user << std::endl;
}