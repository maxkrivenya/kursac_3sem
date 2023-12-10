#pragma once
#include "user.h"
#include "List.h"
#define CONSOLE_WIDTH 120
User& Register();
void q_header(int curr);
void mbti_test(List<q_mbti>, User& user);