#pragma once
#include "kursac_functions.h"

#define addInfo "*Более подробное описание результатов можно найти в файле с названием теста и вашим id*"
using namespace std;

class Interface {
public:
	Interface() {};
	~Interface() {};
	bool MBTItestMenu();
	void q_header(int curr);
	void q_header(string text);
	//void InterfaceMenu();
	//void StartMenuUser();
	//void StartMenuAdmin();
	//void TestingMenu();		
	//void AnalysisMenuAdmin();
	//void AnalysisMenuUser();	
	//void PersonalityTestMenu();
	//void IntelligenceTestMenu();
	//void AbilityTestMenu();		
private:
	User account;
};