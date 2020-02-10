#include "Screen.h"
#include <iostream>
#include <string>
#include <Windows.h>

using  namespace std;

void InitScreen() {			// Funzione chiamata una singola volta all'inizio di tutto il programma che serve per inizilizzare vari valori e chiamare funzioni di inizializzazione relative alla libreria dello schermo
	initscr();
	cbreak();				// Non fa molta differenza fra nocbreak e cbreak, nella documentazione della libreria dicono che è utile averlo attivo quindi per sicurezza lo lascio.
	noecho();				//per evitare che se si prema 'w' o altri tasti vengano mostrati a schermo
	nodelay(stdscr, TRUE);	// se non ci fosse ad ogni gtech ci si bloccherebbe l'esecuzione
	start_color();			//Per far in modo che si possano usare i colori
	curs_set(0);			//Per evitare che il cursore venga mostrato (quello che lampeggia)
	

	init_pair(ObstaclePair, COLOR_RED, COLOR_BLACK);				// DEFINITI I COLORI DEGLI OGGETTI
	init_pair(WallPair, COLOR_WHITE, COLOR_BLACK);					//Con init_pair vengono inizializzati i colori che poi verranno usati per le varie scritte, oggetti e macchina
	init_pair(AirPair, COLOR_BLUE, COLOR_BLACK);					//pair perchè i colori vengono presi in coppia, il primo si riferisce al colore del testo il secondo a quello dello sfondo
	init_pair(PitPair, COLOR_YELLOW, COLOR_BLACK);
	init_pair(SelectedMenuOptionPair, COLOR_YELLOW, COLOR_WHITE);
	init_pair(StandardWriteColorPair, COLOR_WHITE, COLOR_BLACK);

																//Seguono poi comandi per settare la grandezza della schermata
	HWND console = GetConsoleWindow();						
	RECT r;
	GetWindowRect(console, &r); 

	MoveWindow(console, 0, 0, 1920, 1080, TRUE);
}

Screen::Screen() {
	this->xOffset = 0;												//In caso di inizializzazione base dello Screen viene preso come offset 0 in tutte le direzione
	this->yOffset = 0;
	this->MoveCursor(0, 0, false);									//MoveCursor(0,0,false) fa in modo di settare un cursore virtuale nella posizione 0,0 relativa all'offset
}

Screen::Screen(int xOffset, int yOffset) {
	this->xOffset = xOffset;
	this->yOffset = yOffset;		
	this->MoveCursor(0, 0, false);									//MoveCursor(0,0,false) fa in modo di settare un cursore virtuale nella posizione 0,0 relativa all'offset
}

void Screen::DrawObjectAt(Object obj, int x, int y) {				//Prende un oggetto di tipo Object e due coordinate e stampa l'oggetto in quel determinato punto
	this->MoveCursor(x, y, false);

	switch (obj.GetType())											//In base al tipo sceglie che caso fare, serve per la gestione dei colori 
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
		case pit:
			attron(COLOR_PAIR(AirPair));
			printw("%c", obj.appearence);
			attroff(COLOR_PAIR(AirPair));
			break;
		default:
			break;
	}
}

void Screen::DrawStringAt(string st, int x, int y, int colorPair) {		//data una stringa, due coordinate, e un intero che rappresenta un colorPair stampa la stringa con quel determinato colore
	this->MoveCursor(x, y, false);
	attron(COLOR_PAIR(colorPair));
	printw("%s", st.c_str());											//st.c_str() restituisce un puntatore all'array di char della stringa in modo da poterlo stampare
	attroff(COLOR_PAIR(colorPair));
	
}

void Screen::MoveCursor(int x, int y, bool relativeToCurrentPosition) {	//Funzione che muove il cursore virtuale e il "vero" cursore in un determinato punto

	if (relativeToCurrentPosition) {									//Questo sembra abbastanza inutile perchè non viene mai chiamato, però lo ho aggiunto in caso potesse servire
		this->cursorXPos = this->cursorYPos + x;						//Magari tipo voglio scrivere una stringa 3 righe più in basso a quella scritta per ultimo posso fare così 
		this->cursorYPos = this->cursorXPos + y;						//MoveCursor(0, 3, true); poi DrawStringAt(miaStringa ,GetCursorXPos(), GetCursorYPos(), colorPair)
	}																	//Facendo in modo che non devo sapere la posizione della scritta precendente
	else {
		this->cursorXPos = x;
		this->cursorYPos = y;
	}
		move(this->yOffset + this->cursorYPos, this->xOffset + this->cursorXPos);
}

void Screen::ResetCursorPosition() {									//Il nome dice tutto
	this->MoveCursor(0, 0, false);
}

int Screen::GetCursorXPos() {
	return this->cursorXPos;
}

int Screen::GetCursorYPos() {
	return this->cursorYPos;
}

void Screen::ScreenClear() {
	clear();
	system("cls");
	curs_set(0);
}