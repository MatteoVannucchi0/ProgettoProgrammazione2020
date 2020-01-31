#pragma once
#include <string>
#include "Constant.h"
#include "curses.h"
#include "MapObject.h"
using  namespace std;

void InitScreen();

class Screen {
protected:
	int xOffset;
	int yOffset;
	int cursorXPos;
	int cursorYPos;

public:
	Screen();

	Screen(int xOffset, int yOffset);

	void DrawObjectAt(Object obj, int x, int y);

	void DrawStringAt(string st, int x, int y, int colorPair = 100);

	void MoveCursor(int x, int y, bool relativeToCurrentPosition);

	void ResetCursorPosition();

	int GetCursorXPos();

	int GetCursorYPos();
};
