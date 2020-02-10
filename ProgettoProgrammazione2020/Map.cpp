#include <iostream>
#include "Map.h"
#include "curses.h"
#include "Constant.h"
#include "Screen.h"
#include "Utilities.h"
using namespace std;


Map::Map() {
	//INIZIALIZZA LA MAPPA 
	this->StartLine = 0;
	this->EndLine = MAP_HEIGHT - 1;
	for (int i = 0; i < MAP_HEIGHT - 1; i++) {
		this->mapGrid[i][0] = this->mapGrid[i][MAP_WIDTH - 1] = Object(wall);
		for (int j = 1; j < MAP_WIDTH - 1; j++) {
			this->mapGrid[i][j] = Object(air);
		}
	}
	//Inizializza lo schermo della mappa
	this->mapScreen = Screen(MAP_OFFSET_X, MAP_OFFSET_Y);
}

void Map::DrawLine(int y) {
	int realLineIndex = mod(this->StartLine + y, MAP_HEIGHT);
	for (int i = 0; i < MAP_WIDTH; i++) {
		Object objectToDraw = this->mapGrid[realLineIndex][i];
		this->mapScreen.DrawObjectAt(objectToDraw, i, y);
	}
}

void Map::DrawMap() {
	for (int y = 0; y < MAP_HEIGHT - 1; y++) {
		this->DrawLine(y);
	}
}

Object* Test_TranslateToBigObject(Object line[]) {
	int sizeOfTile = 3;
	Object newLine[MAP_WIDTH];
	newLine[0] = newLine[MAP_WIDTH - 1] = Object(wall);
	for (int i = 1; i < (MAP_WIDTH / 3) - 1; i++) {
		int index = i * 3;
		newLine[index] = newLine[index + 1] = newLine[index + 2] = line[i];
	}
	return newLine;
}

void Map::PushNewRow(Object line[]) {
	Object* bigLine = Test_TranslateToBigObject(line);
	for (int i = 0; i < MAP_WIDTH; i++) {
		this->mapGrid[this->EndLine][i] = bigLine[i];
	}
	this->StartLine = mod(this->StartLine - 1, MAP_HEIGHT);
	this->EndLine = mod(this->EndLine - 1, MAP_HEIGHT);
}

Object Map::GetObjectAt(int x, int y) {
	int realLineIndex = mod(this->StartLine + y, MAP_HEIGHT);
	return this->mapGrid[x][y];
}
