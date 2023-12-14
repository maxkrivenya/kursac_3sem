#pragma once
#include "user.h"
#include "List.h"
#include "Stack.h"
#include "tree.h"
#include "Question.h"
#include <string>
using namespace std;
#define CONSOLE_WIDTH 120
#define NEWLINE std::cout << std::endl;
User& Register();
//void q_header(int curr);
//void q_header(string text);
void mbti_test(List<q_mbti>, User& user);
void DriverTest(Tree<q_driver>, User& user);
void REPEAT(char c, int amt);
void SKIP(int amt);
string nthWord(string, int);
void question_failed(Tree<q_driver>::Iterator it, User& user, int& mistakes_amt);