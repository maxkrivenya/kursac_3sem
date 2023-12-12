#pragma once
#include "user.h"
#include "List.h"
#include "Stack.h"
using namespace std;
#define CONSOLE_WIDTH 120
#define NEWLINE std::cout << std::endl;
User& Register();
void q_header(int curr);
void mbti_test(List<q_mbti>, User& user);
void REPEAT(char c, int amt);
void SKIP(int amt);