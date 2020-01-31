#pragma once
#include "Screen.h"
#include "Constant.h"
using namespace std;

class MainMenu {
protected:
	Screen MenuScreen;
	int SelectedOption;
public:
	MainMenu();

	void DrawMenu();

	void ManageInput();
};