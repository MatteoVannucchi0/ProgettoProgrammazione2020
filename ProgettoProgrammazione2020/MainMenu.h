#pragma once
#include <string>
#include "Screen.h"
#include "Constant.h"
using namespace std;

enum class MenuOption { 
	Play,
	Instruction,
	Bestscore,
	Exit
};
/*	 Perchè aggiungere un Enum quando semplicemente una variabile interna alla classe (in questo caso selectedOption) tiene già traccia della opzione su cui siamo?
	 Lo faccio per fare in modo che il codice sia più leggibile, cosi invece che avere tipo selectedOption == 1 ? abbiamo GetMenuOptionState() == MenuOption::Instruction, 
	 poi cosi che se si volesse cambiare in futuro le opzioni, e quindi le relative azioni da fare in caso vengano cliccati
	 andrebbe cambiato quattro cose: 
		 1 - la variabile (array di stringhe) (costante o no) che tiene traccia delle varie opzioni da stampare
		 2 - la dichiarazione dell' Enum (aggiungendo o togliendo delle opzioni)
		 3 - la funzione GetMenuOptionSelected che andrebbe cambiata aggiungendo o togliendo opzioni disponibili
		 4 - aggiungere le funzioni relative a quando si seleziona l'opzione (il DrawMenu e OnMenuSelected).
	 In caso utilizzazi un semplice numero (selectedOption) per tutto se volessi aggiungere qualcosa dovrei cambiare si meno cose, ma in per solo la 2 è (in caso di codice lungo) molto più lunga da fare: 
		 1 - la variabile che tiene traccia delle varie opzioni da stampare
		 2 - ogni singolo controllo per vedere in quale "stato" siamo, andando ad aggiungere quindi in mezzo al codice numeri apparentemente random 
					(Es: Poniamo che abbiamo tre opzioni iniziali Play, Bestscore e exit e vogliamo aggiungere Instruction in mezzo fra play e Bestscore. Quello che dobbiamo fare è andare a cambiare ogni singolo numero apparentemente random che andava a controllare in quale "stato" eravamo)
		 3 - aggiungere le funzioni relative a quando si seleziona l'opzione. (il DrawMenu e OnMenuSelected).

*/

class MainMenu {
protected:
	

	Screen MenuScreen;
	int selectedOption; // 0 == PLAY, 1 == Instruction, 2 == Best score, 3 == Exit

	bool isOnInternalMenu;
	bool hasClickedOnPlay;

	void Draw();

	void ManageInput();

	void OnSelection();

	void OnExitMenuSelected();
	void OnPlayMenuSelected();
	void OnInstructionMenuSelected();
	void OnBestScoreMenuSelected();

	void DrawInstructionMenu();
	void DrawBestScoreMenu();

	MenuOption GetMenuOptionSelected();
public:
	MainMenu();
	bool MenuUpdateCall();
};