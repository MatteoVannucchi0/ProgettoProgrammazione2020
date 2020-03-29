#pragma once
#include "Constant.h"
#include "MapObject.h"
#include "Screen.h"


//Classe che gestisce la mappa, mantenendo in memoria tutti vari oggetti contenuti nella mappa.
/*in modo da impedire che ad ogni frames debba riaggiornare tutta la matrice degli oggetti, tengo in memoria due indici
  l'indice di inizio (startLine) e l'indice di fine (endLine) che mi rappresentano come devono essere considerate le posizioni degli oggetti nella matrice.
  Ad esempio se StartLine = 5 la quinta riga della matrice sarà in realtà la prima riga (dall'alto) che viene stampata, quindi l'ultima aggiunta.
*/
class Map {
protected:
	Object mapGrid[MAP_HEIGHT][MAP_WIDTH];
	int StartLine;								
	int EndLine;
	Screen mapScreen;
	void DrawLine(int y);

public:
	Map();
	void DrawMap();
	void PushNewRow(Object line[]);
	Object GetObjectAt(int x, int y);
};