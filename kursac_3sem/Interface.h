#pragma once
#include "kursac_functions.h"
#include "InputException.h"

#define addInfo "*Более подробное описание результатов можно найти в файле с названием теста и вашим id*"
using namespace std;

class Interface {
public:
	Interface() {};
	~Interface() {};
	void MainMenu();
	void MainMenuHeader();
	void TestMenu();
	void TestMenuHeader();
	bool MBTItestMenu();
	bool DriverTestMenu();
	void qHeader(int curr);
	void qHeader(string text);
	void eot();	
private:
	User user;
};