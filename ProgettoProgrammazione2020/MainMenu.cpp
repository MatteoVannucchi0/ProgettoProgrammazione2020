#include "Screen.h"
#include "Constant.h"
#include "MainMenu.h"
#include "Utilities.h"
#include <iostream>
using namespace std;

MainMenu::MainMenu() {
	this->MenuScreen = Screen(MAIN_MENU_OFFSET_X, MAIN_MENU_OFFSET_Y);
	this->SelectedOption = 0;
}

void MainMenu::DrawMenu() {
	for (int i = 0; i < 4; i++) {
		int colorPair = 100;
		if (i == this->SelectedOption)
			colorPair = SelectedMenuOptionPair;
		this->MenuScreen.DrawStringAt(MAIN_MENU_OPTION[i], 0, i * MAIN_MENU_DISTANCE_BETWEEN_OPTION, colorPair);
	}
}
void MainMenu::ManageInput() {
	int ch = getch();
	switch (ch)
	{
	case 's':
		this->SelectedOption = mod(this->SelectedOption + 1, 4);
		break;
	case 'w':
		this->SelectedOption = mod(this->SelectedOption - 1, 4);
		break;
	default:
		break;
	}
}