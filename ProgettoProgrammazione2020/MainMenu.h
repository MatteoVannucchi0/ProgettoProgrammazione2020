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
	 poi cosi che se si volesse cambiare in futuro le opzioni, e quindi le relative azioni da fare in caso vengano cliccati, si può fare in modo molto semplificato.
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