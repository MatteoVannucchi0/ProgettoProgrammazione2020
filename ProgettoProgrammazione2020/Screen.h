#pragma once
#include "Constant.h"
#include "curses.h"
#include "MapObject.h"

class Screen {
public:
	void DrawObjectAt(Object obj, int x, int y, bool relativeToMap = true);

	void DrawCharat(char ch, int x, int y);
};
