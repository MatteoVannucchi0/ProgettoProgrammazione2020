#include "Screen.h"
#include <iostream>
#include <string>
#include <Windows.h>

using  namespace std;

void InitScreen() {
	initscr();
	nodelay(stdscr, TRUE);
	start_color();
	curs_set(0);
	noecho();

	init_pair(ObstaclePair, COLOR_RED, COLOR_BLACK); // DEFINITI I COLORI DEGLI OGGETTI
	init_pair(WallPair, COLOR_WHITE, COLOR_BLACK);
	init_pair(AirPair, COLOR_BLUE, COLOR_BLACK);
	init_pair(SelectedMenuOptionPair, COLOR_YELLOW, COLOR_WHITE);
	init_pair(StandardWriteColorPair, COLOR_WHITE, COLOR_BLACK);

	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r); //stores the console's current dimensions

	MoveWindow(console, 0, 0, 1920, 1080, TRUE);
}

Screen::Screen() {
	this->xOffset = 0;
	this->yOffset = 0;
	this->MoveCursor(0, 0, false);
}

Screen::Screen(int xOffset, int yOffset) {
	this->xOffset = xOffset;
	this->yOffset = yOffset;
	this->MoveCursor(0, 0, false);
}

void Screen::DrawObjectAt(Object obj, int x, int y) {
	this->MoveCursor(x, y, false);

	switch (obj.GetType())
	{
		case wall:
			attron(COLOR_PAIR(WallPair));
			printw("%c", obj.appearence);
			attroff(COLOR_PAIR(WallPair));
			break;
		case obstacle:
			attron(COLOR_PAIR(ObstaclePair));
			printw("%c", obj.appearence);
			attroff(COLOR_PAIR(ObstaclePair));
			break;
		case air:
			attron(COLOR_PAIR(AirPair));
			printw("%c", obj.appearence);
			attroff(COLOR_PAIR(AirPair));
			break;
		default:
			break;
	}
}

void Screen::DrawStringAt(string st, int x, int y, int colorPair) {
	this->MoveCursor(x, y, false);
	attron(COLOR_PAIR(colorPair));
	printw("%s", st.c_str());
	attroff(COLOR_PAIR(colorPair));
}

void Screen::MoveCursor(int x, int y, bool relativeToCurrentPosition) {
	if (relativeToCurrentPosition) {
		this->cursorXPos = this->cursorYPos + x;
		this->cursorYPos = this->cursorXPos + y;
	}
	else {
		this->cursorXPos = x;
		this->cursorYPos = y;
	}
		move(this->yOffset + this->cursorYPos, this->xOffset + this->cursorXPos);
}

void Screen::ResetCursorPosition() {
	this->MoveCursor(0, 0, false);
}

int Screen::GetCursorXPos() {
	return this->cursorXPos;
}

int Screen::GetCursorYPos() {
	return this->cursorYPos;
}