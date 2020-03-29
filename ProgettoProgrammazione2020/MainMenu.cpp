#include "Screen.h"
#include "Constant.h"
#include "MainMenu.h"
#include "Utilities.h"
#include <assert.h>
using namespace std;

MainMenu::MainMenu() {
	this->MenuScreen = Screen(MAIN_MENU_OFFSET_X, MAIN_MENU_OFFSET_Y);			//inizializza lo 'schermo' su cui il menu andrà a scrivere, prendi i valori MAIN_MENU_OFFSET_X e MAIN_MENU_OFFSET_Y come offset dall'angolo in alto a SX
	this->selectedOption = 0;													//inizializza come scelta di base il Play
	this->isOnInternalMenu = false;												//non siamo su un menù interno
	this->hasClickedOnPlay = false;												//non è ancora stato cliccato il bottone play
}

void MainMenu::Draw() {
	//MAGARI SI PUO' AGGIUNGERE UNA SCRITTA STATICA COL NOME DEL GIOCO
	if (!this->isOnInternalMenu) {				// Se non è in un menù interno deve stampare il menu principale
		for (int i = 0; i < MAIN_MENU_NUMBER_OF_OPTION; i++) {			// Per ogni opzione 
			int colorPair = StandardWriteColorPair;		//Di base il colore con cui scrivere scritta e sfondo è StandardWriteColorPair
			if (i == this->selectedOption)		// Se siamo nella opzione su cui siamo sopra allora il colore non deve essere più quello standard ma SelectedMenuOptionPair
				colorPair = SelectedMenuOptionPair;
			this->MenuScreen.DrawStringAt(MAIN_MENU_OPTION[i], 0, i * MAIN_MENU_DISTANCE_BETWEEN_OPTION, colorPair); //Relega allo schermo la stampa della singola opzione, con distanza i * MAIN_MENU_DISTANCE_OPTION 
		}																											 // (distanza in termini di altezza fra le varie opzioni del menù) e con colore il colorPair selezionato
	}
	else {													// se invece siamo in un menù interno (che può essere di vari tipi) 
		switch (this->GetMenuOptionSelected()){				// Prendiamo lo stato del Menu, cioé l'opzione che abbiamo selezionato
		case MenuOption::Exit:								//i casi Exit e Play li lascio per completezza, ma queste due porzioni di codice non verrano mai eseguite e in ogni caso non devono fare niente
			break;
		case MenuOption::Play:
			break;
		case MenuOption::Instruction:			
			this->DrawInstructionMenu();					// Se l'opzione selezionata è istruzione stampa il relativo menù
			break;
		case MenuOption::Bestscore:
			this->DrawBestScoreMenu();						// Se l'opzione è BestScore stampa il relativo menù
			break;
		default:
			break;
		}
	}
}

bool MainMenu::MenuUpdateCall() {		//Funzione generale che gestisce il ciclo di Update del menu, diviso in tre parti: Input, Draw, Check se si ha cliccato su play
										//Il valore di ritorno è vero se l'utente ha cliccato su play, falso altrimenti
	this->ManageInput();
	this->Draw();
	return this->hasClickedOnPlay; 
}

void MainMenu::ManageInput() {		// Funzione che gestisce gli input e i relativi cambiamenti di stato interni al menù
	int ch = getch();	

	if (!this->isOnInternalMenu) {									 // Se siamo in un menù interno non ci importa di gestire su e giù con la freccia
		switch (ch)
		{
		case MAIN_MENU_KEY_ONE_OPTION_DOWN:													 // per mandare in giù di un opzione
			this->selectedOption = mod(this->selectedOption + 1, MAIN_MENU_NUMBER_OF_OPTION); // il modulo serve per fare in modo quando si arrivi all'ultima opzione ricicla alla prima o viceversa
			break;
		case MAIN_MENU_KEY_ONE_OPTION_UP:													 // per mandare in su di un opzione
			this->selectedOption = mod(this->selectedOption - 1, MAIN_MENU_NUMBER_OF_OPTION);
			break;
		case MAIN_MENU_KEY_SELECTOR:
			this->OnSelection();									//Se l'Enter viene premuto vuol dire che abbiamo selezionato un'opzione, quindi chiama la funzione apposita
			break;
		default:
			break;
		}
	}
	else {								
		if (ch == MAIN_MENU_KEY_EXIT) {		//In caso che venga premuto L'ESC mentre siamo dentro un menù
			this->MenuScreen.ScreenClear();							//Si pulisce lo schermo
			this->isOnInternalMenu = false;							//Non siamo più in un menù interno
		}															//Ha come effetto quello di uscire dal menu secondario e ritornare al menu principale
	}
}

void MainMenu::OnSelection() {					//Funzione chiamata ogni qualvolta che mentre si è nel menu principale (quindi isOnInternalMenu = false) viene premuto il tasto Enter (cioè 'seleziona') (il tasto per cui viene chiamata la funzione può essere cambiato)
	switch (this->GetMenuOptionSelected())		// in base a che opzione abbiamo selezionato una funzione relativa al menu interno verrà chiamata
	{
	case MenuOption::Exit:
		this->OnExitMenuSelected();
		break;
	case MenuOption::Play:
		this->OnPlayMenuSelected();
		break;
	case MenuOption::Instruction:
		this->OnInstructionMenuSelected();
		break;
	case MenuOption::Bestscore:
		this->OnBestScoreMenuSelected();
		break;
	default:
		break;
	}
}

void MainMenu::OnExitMenuSelected() {
	this->MenuScreen.ScreenClear(); // la finestra viene pulita
	exit(0);						// viene terminata l'esecuzione del programma
}

void MainMenu::OnPlayMenuSelected() {
	this->MenuScreen.ScreenClear();		// la finestra viene pulita
	this->hasClickedOnPlay = true;		// Viene messo vero in modo tale che al prossimo ciclo del main, quando si verifica che con il return di MenuUpdateCall() viene ritornato True, in modo tale da poter uscire dal ciclo del menu e andare al ciclo del gioco
}

void MainMenu::OnInstructionMenuSelected() {
	this->MenuScreen.ScreenClear();
	this->isOnInternalMenu = true;
}

void MainMenu::OnBestScoreMenuSelected() {
	this->MenuScreen.ScreenClear();
	this->isOnInternalMenu = true;
}

void MainMenu::DrawInstructionMenu() {		//Chiamata quando isOnInternalMenu è true e quanto GetMenuOptionSelected() = Instruction (o equivalentemente quando selectedOption = 1)
	this->MenuScreen.DrawStringAt("PROVA MENU INSTRUCTION", 0, 0, StandardWriteColorPair);
}

void MainMenu::DrawBestScoreMenu() {		//Chiamata quando isOnInternalMenu è true e quanto GetMenuOptionSelected() = Bestscore (o equivalentemente quando selectedOption = 2)
	this->MenuScreen.DrawStringAt("PROVA MENU BestScore", 0, 0, StandardWriteColorPair);
}

MenuOption MainMenu::GetMenuOptionSelected() {		// Questa funzione viene chiamata ogni qualvolta si vuole (per convenzienza o altre ragione) avere l'opzione selezionata (di solito tenuta in selectedOption cioè INT) trasformata in tipo MenuOption
	MenuOption ris;
	switch (this->selectedOption)
	{
	case 0:											//Forse vanno cambiati con dei valori 'Costanti' con significato.
		ris = MenuOption::Play;
		break;
	case 1:
		ris = MenuOption::Instruction;
		break;
	case 2:
		ris = MenuOption::Bestscore;
		break;
	case 3:
		ris = MenuOption::Exit;
		break;
	default: // questo caso non dovrebbe mai verificarsi, per sicurezza ci si lascia un Assert cosi che si può verificare in fase di Debug
		assert(false && "Errore in GetMenuOptionSelected, this->selectedOption non è fra i casi dello switch");
		exit(0);
		break;
	}
	return ris;
}