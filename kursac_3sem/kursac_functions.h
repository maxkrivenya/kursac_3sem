#pragma once
#include "user.h"
#include "Containers.h"
#include "qSport.h"
#include <string>
#include <vector>
using namespace std;
#define CONSOLE_WIDTH 120
#define NEWLINE std::cout << std::endl;

string nthWord(string, int);
void REPEAT(char c, int amt);
void SKIP(int amt);

template <class T>
List<T> TestInit(const char* filename);



void mbtiTest(User& user);
void ShmishekTest(User& user);
void SportsTest(User& user);


Tree<qDriver> DriverTestInit();
void DriverTest(User& user);
void question_failed(Tree<qDriver>::Iterator it, User& user, int& mistakes_amt);

string VectToMbti(vector<int>);

