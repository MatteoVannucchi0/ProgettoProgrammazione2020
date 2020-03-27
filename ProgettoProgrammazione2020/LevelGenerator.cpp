#include "LevelGenerator.h"


class LevelGenerator {
protected:
	Object Row[MAP_WIDTH];
	int Seed; 
	Object* RowHeap = new Object[MAP_WIDTH];
	std::mt19937 generatore = std::mt19937(); // seed che genera il livello
	int Level;  // variabile che mi indica il livello di difficoltà dell'oggetto
	int difficulty = 20;

	void row_generator() {    // funzione che genera una riga

		int N_obstacles = N_obstacles_generator();  // ritorna il numero di ostacoli generati
		
			insert_obstacles(N_obstacles);
			// specifica il tipo di degli ostacoli e li inserisce nella riga 
		
	}
	
	int N_obstacles_generator() {     // funzione che ritorna il numero di ostacoli generati
		int Probability = 0;
		int N_obstacles = 0;
		
		Probability = generatore() % 100 + 1; // il primo rand serve per avere un la probabilità che esca un'ostacolo 
		while (difficulty >= 100) {  // se la difficoltà supera il cento verrà generato almeno un'ostacolo a riga  
			N_obstacles++;
			difficulty -= 100;
		}
		if (Probability < difficulty) { // il ragionamento usato è: se il numero generato tra 0 e 100 è < della difficoltà allora si genera un ostacolo
									// il parametro difficoltà non è altro che la probalità di generazione del ostacolo  
			N_obstacles++;
		}
		
		return  N_obstacles;
	}	

	void insert_obstacles(int N_obstacles) {
		
		while (N_obstacles > 0) // cicla finchè ci sono ostacoli da generare
		{
			int n = generatore() % 2 + 3; // genera un numero compreso tra 2 e 4 indica quale ostacolo malus verrà generato
			ObjectType val = static_cast<ObjectType>(n);
			bool flag = true;
			do {		// questo ciclo serve per verificare che non vengano sovrapposti due oggetti ( diversi da air )
				n = generatore() % MAP_WIDTH;
				
				ObjectType maptype = Row[n].GetType();
			
				if (maptype >= 1 && maptype <= 4)
					flag = false;
				else
					flag = true;
				
			} while (flag == false);

			 Row[n].ChangeType(val);
			 ObjectType maptype = Row[n].GetType();
			N_obstacles--;
		}
		
			
	}

	void refresh() { // reimposta la riga in object air, è necessario per l'inserimento degli ostacoli 
		ObjectType air = static_cast<ObjectType>(0);
		for (int i = 0; i < MAP_WIDTH; i++) {
			Row[i].ChangeType(air);
		}
	}


public:

	LevelGenerator() {          // Costruttore senza parametri  livello impostato ad 1 e seed 0
		Level = 1;
		Seed = 0;
		generatore.seed(Seed);
		difficulty = Level * difficulty; // la difficoltà serve come parametro per la generazione degli ostacoli,
						   //15 corrisponde al 15% che venga generato un ostacolo sulla riga, man mano che si sale di livello sale anche la probabilità
		int i = 0;
		
	} 

	LevelGenerator(int seed) {
		Seed = seed;
		generatore.seed(Seed);
		difficulty = 1 * difficulty;
		int i = 0;
		
	}   // Costruttore con parametro seed , livello impostato di default 0

	LevelGenerator(int seed, int Level) {
		Seed = seed;
		generatore.seed(Seed);
		difficulty = Level * difficulty;
		int i = 0;
	} // Costruttore con parametri  livello e seed




	 Object* GetRow() {     // ritorna la riga informato oggetto  
		refresh();
		row_generator();
		
		delete RowHeap;
		RowHeap = new Object[MAP_WIDTH];
		for (int i = 0; i < MAP_WIDTH; i++) {
			RowHeap[i] = Row[i];
		}

		return RowHeap;
	} 


	void PrintRow() {   // ritorna la riga in formato testuale 
		refresh();
		row_generator();

		for (int i = 0; i < MAP_WIDTH; i++)
		{
			Row[i].PrintAppearance();
		}
	}

	void Restart() { // riporta il generatore allo stato iniziale ( permette di ricominciare il  livello )
		generatore = std::mt19937(Seed);
	}
};

