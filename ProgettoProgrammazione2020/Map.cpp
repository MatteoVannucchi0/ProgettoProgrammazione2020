#include <iostream>
#include "Map.h"
#include "curses.h"
#include "Constant.h"
#include "Screen.h"
using namespace std;

int mod(int a, int b) {
	return (a % b + b) % b;
}

int RandomInt(int min, int max) {
	return rand() % (max - min + 1) + min;
}

void InitScreen() {
	initscr();
	nodelay(stdscr, TRUE);
	start_color();
	
	init_pair(ObstaclePair, COLOR_RED, COLOR_BLACK); // DEFINITI I COLORI DEGLI OGGETTI
	init_pair(WallPair, COLOR_WHITE, COLOR_BLACK);
	init_pair(AirPair, COLOR_BLUE, COLOR_BLACK);
}

Map::Map() {
	//INIZIALIZZA LO SCHERMO
	InitScreen();

	//INIZIALIZZA LA MAPPA 
	this->StartLine = 0;
	this->EndLine = MAP_HEIGHT - 1;
	for (int i = 0; i < MAP_HEIGHT; i++) {
		this->mapGrid[i][0] = this->mapGrid[i][MAP_WIDTH - 1] = Object(wall);
		for (int j = 1; j < MAP_WIDTH - 1; j++) {
			this->mapGrid[i][j] = Object(air);
		}
	}
}

void Map::DrawLine(int y) {
	Screen screen = Screen();
	int realLineIndex = mod(this->StartLine + y, MAP_HEIGHT);
	for (int i = 0; i < MAP_WIDTH; i++) {
		screen.DrawObjectAt(this->mapGrid[realLineIndex][i], i, y);
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