#pragma once
#include "Constant.h"
#include "MapObject.h"

class Map {
protected:
	Object mapGrid[MAP_HEIGHT][MAP_WIDTH];
	int StartLine;
	int EndLine;
	void DrawLine(int y);

public:
	Map();
	void DrawMap();
	void PushNewRow(Object line[]);
	Object GetObjectAt(int x, int y);
};
