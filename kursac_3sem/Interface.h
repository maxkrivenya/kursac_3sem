#pragma once
#include "kursac_functions.h"
#include "InputException.h"

#define addInfo "*����� ��������� �������� ����������� ����� ����� � ����� � ��������� ����� � ����� id*"
using namespace std;

class Interface {
public:
	Interface() {};
	~Interface() {};
	void Menu();
	void MenuHeader();
	bool MBTItestMenu();
	bool DriverTestMenu();
	void q_header(int curr);
	void q_header(string text);
	void eot();
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
	User user;
};