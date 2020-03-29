#include <iostream>
#include "Map.h"
#include "curses.h"
#include "Constant.h"
#include "Screen.h"
#include "Utilities.h"
using namespace std;


Map::Map() {
	//INIZIALIZZA LA MAPPA 
	this->StartLine = 0;									//La mappa viene inizializzata con StartLine = 0 e Endline = altezza - 1
	this->EndLine = MAP_HEIGHT - 1;

	for (int i = 0; i < MAP_HEIGHT - 1; i++) {				//Inizializzazione della mappa iniziale (si può cambiare): è una mappa con solo muri esterni e il resto vuota.
		this->mapGrid[i][0] = this->mapGrid[i][MAP_WIDTH - 1] = Object(wall);
		for (int j = 1; j < MAP_WIDTH - 1; j++) {
			this->mapGrid[i][j] = Object(air);
		}
	}
	//Inizializza lo schermo della mappa con l'offset che deve avere la mappa rispetto al punto del terminale in alto a sx.
	this->mapScreen = Screen(MAP_OFFSET_X, MAP_OFFSET_Y);						
}

void Map::DrawLine(int y) {
	int realLineIndex = mod(this->StartLine + y, MAP_HEIGHT);			//Volendo prendere la riga y-esima e sapendo che non è in realtà la riga y-esima della matrice devo trasformare l'indice y in quello "interno" della matrice
																		//Nota uso mod() definito da me perchè si comporta come voglio io per i numeri negativi.
	for (int i = 0; i < MAP_WIDTH; i++) {					
		Object objectToDraw = this->mapGrid[realLineIndex][i];			//Prendo l'oggetto [y][i]
		this->mapScreen.DrawObjectAt(objectToDraw, i, y);				//Lo passo allo schermo per essere disegnato sul terminale
	}
}

void Map::DrawMap() {									//Semplicemente stampa ogni riga della mappa, Nota: non aggiungo un clear del terminale perchè magari altri elementi che non si vuole cancellare vengono cancellati. Va aggiunto nel file main
	for (int y = 0; y < MAP_HEIGHT - 1; y++) {
		this->DrawLine(y);
	}
}

Object* Test_TranslateToBigObject(Object line[]) {	//TEST: DA TOGLIERE SE PASOTTO NON LO VUOLE
	int sizeOfTile = 3;
	Object newLine[MAP_WIDTH];
	newLine[0] = newLine[MAP_WIDTH - 1] = Object(wall);
	for (int i = 1; i < (MAP_WIDTH / 3) - 1; i++) {
		int index = i * 3;
		newLine[index] = newLine[index + 1] = newLine[index + 2] = line[i];
	}
	return newLine;
}

void Map::PushNewRow(Object line[]) {								//Per inserire una nuova riga all'inizio (in alto) della mappa.
	Object* bigLine = Test_TranslateToBigObject(line);				//TEST: SI PUO' TOGLIERE
	for (int i = 0; i < MAP_WIDTH; i++) {
		this->mapGrid[this->EndLine][i] = bigLine[i];				//La endLine sarà la riga che viene sostituita essendo l'ultima (quella più in basso)
	}
	this->StartLine = mod(this->StartLine - 1, MAP_HEIGHT);			//decremento gli indici in modo tale da "fare andare avanti" la mappa
	this->EndLine = mod(this->EndLine - 1, MAP_HEIGHT);
}

Object Map::GetObjectAt(int x, int y){								//Funzione che serve se si vuole prendere un oggetto in una posizione specifica. Le coordinate vanno date "normalmente", l'indice viene poi trasformato
	int realLineIndex = mod(this->StartLine + y, MAP_HEIGHT);
	return this->mapGrid[x][y];
}
