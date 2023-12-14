#pragma once
#include "user.h"
#include "Containers.h"
#include "qSport.h"
#include <string>
using namespace std;
#define CONSOLE_WIDTH 120
#define NEWLINE std::cout << std::endl;

User& Register();
string nthWord(string, int);
void REPEAT(char c, int amt);
void SKIP(int amt);

List<qMbti> mbtiTestInit(const char* fileName = "mbtiQuestions.txt");
void mbtiTest(User& user);


void DriverTest(Tree<qDriver>, User& user);
void question_failed(Tree<qDriver>::Iterator it, User& user, int& mistakes_amt);

List<qSport> sportsTestInit(const char* fileName = "sports.txt");
void sportsTest(User& user);