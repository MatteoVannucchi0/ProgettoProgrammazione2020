#pragma once
#include <string>
#include "Constant.h"
#include "curses.h"
#include "MapObject.h"
using  namespace std;

void InitScreen();	//NOTA: Funzione che non dipende tanto dalla classe ma che va chiamata per inizializzare le funzioni dello schermo di PDCurses

class Screen {
protected:
	int xOffset;			//Mantiene l'offset della schermata rispetto all'asse x e quello sotto rispetto all'asse y
	int yOffset;
	int cursorXPos;			//Cursore virtuale che serve in caso si vogliano fare cose particolari, è anche dove vengono stampati nel terminale i caratterri/oggetti.
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

	static void ScreenClear();
};