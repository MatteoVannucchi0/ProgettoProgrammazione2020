#pragma once
#include <string>
using namespace std;

const int MAP_HEIGHT = 25;
const int MAP_WIDTH = 51;
const int MAP_OFFSET_Y = 0;
const int MAP_OFFSET_X = 5;

const int LEVEL_LENGHT = 500;

const int MAIN_MENU_OFFSET_X = 25;
const int MAIN_MENU_OFFSET_Y = 0;
const int MAIN_MENU_DISTANCE_BETWEEN_OPTION = 4;
const string MAIN_MENU_OPTION[] = { "PLAY", "INSTRUCTION", "BEST SCORE", "EXIT" };
const int MAIN_MENU_NUMBER_OF_OPTION = 4;
const char MAIN_MENU_KEY_ONE_OPTION_DOWN = 's';
const char MAIN_MENU_KEY_ONE_OPTION_UP = 'w';
const char MAIN_MENU_KEY_SELECTOR = '\n';
const int  MAIN_MENU_KEY_EXIT = 27; // il 27 � per il tasto Esc

#define WallPair 1
#define ObstaclePair 2
#define AirPair 3
#define PitPair 4
#define SelectedMenuOptionPair 99
#define StandardWriteColorPair 100
