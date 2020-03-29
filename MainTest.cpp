#include <iostream>
using namespace std;

#include "Map.h"
#include "Constant.h"
#include "curses.h"
#include "Screen.h"
#include "MainMenu.h"

#include <chrono>
#include <thread>
#include <windows.h>


void Update();
void Draw();


Map map = Map();
MainMenu menu = MainMenu();

int main() {

	InitScreen();
}
	/*
	int testTime = 0;

	bool readyToStart = false;
	while (!readyToStart) {
			readyToStart = menu.MenuUpdateCall();
			//Screen().ScreenClear();
	}

	while (1) {
		Update();
		Draw();
		this_thread::sleep_for(chrono::milliseconds(10));
		//Screen().ScreenClear();
	}

}


void Update() {
	int ch = getch();
	if (ch != -1 && ch == (int)'w') {
		Object riga[MAP_WIDTH];
		riga[0] = riga[MAP_WIDTH - 1] = Object(pit);
		for (int i = 1; i < (MAP_WIDTH - 1) / 3; i++) {
			Object oggetto;
			int random = rand() % (2 - 0 + 1) + 0;


			switch (random)
			{
			case 0:
				oggetto = Object(air);
				break;
			case 1:
				oggetto = Object(pit);
				break;
			case 2:
				oggetto = Object(obstacle);
				break;
			default:
				break;
			}
			riga[i] = oggetto;
		}
		map.PushNewRow(riga);
		map.PushNewRow(riga);
		map.PushNewRow(riga);
	}
	return;
}

void Draw() {
	map.DrawMap();
}
*/