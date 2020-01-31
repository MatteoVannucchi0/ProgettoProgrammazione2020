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

void Map::PushNewRow(Object line[]) {
	for (int i = 0; i < MAP_WIDTH; i++) {
		this->mapGrid[this->EndLine][i] = line[i];
	}
	this->StartLine = mod(this->StartLine - 1, MAP_HEIGHT);
	this->EndLine = mod(this->EndLine - 1, MAP_HEIGHT);
}

Object Map::GetObjectAt(int x, int y) {
	int realLineIndex = mod(this->StartLine + y, MAP_HEIGHT);
	return this->mapGrid[x][y];
}