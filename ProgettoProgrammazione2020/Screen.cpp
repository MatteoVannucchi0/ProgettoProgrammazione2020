#include "Screen.h"
#include <iostream>

using  namespace std;

void Screen::DrawObjectAt(Object obj, int x, int y, bool relativeToMap) {
	if (relativeToMap)
		move(MAP_OFFSET_Y + y, MAP_OFFSET_X + x);
	else
		move(y, x);

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

void Screen::DrawCharat(char ch, int x, int y) {
	move(y, x);
	printw("%c", ch);
}