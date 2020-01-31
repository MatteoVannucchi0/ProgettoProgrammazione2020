#pragma once

class LevelGenerator {
protected:
	Object MapLevel[LEVEL_LENGHT][MAP_WIDTH];
	int seed;  // seed che genera il livello
	int Level;  // variabile che mi indica il livello di difficolt� dell'oggetto
	int difficulty = 15;
	
	int raw_generator() {
		
		int N_obstacles = N_obstacles_generator();  // ritorna il numero di ostacoli generati
		while (N_obstacles > 0) {
			insert_obstacles();  // specifica il tipo di ostacolo e lo inserisce nella riga 
			N_obstacles--;
		}
	}

	
	
	int N_obstacles_generator() {     // funzione che ritorna il numero di ostacoli generati
		int Probability;
		int N_obstacles;
		srand(seed);
		Probability = rand() % 100 + 1 ; // il primo rand serve per avere un la probabilit� che esca un'ostacolo se quest  
		while(difficulty >= 100) {  // se la difficolt� supera il cento verr� generato almeno un'ostacolo a riga  
			N_obstacles++;
			difficulty -= 100;
		}
		if (Probability < difficulty) { // il ragionamento usato �: se il numero generato tra 0 e 100 � < della difficolt� allora si genera un ostacolo
									// il parametro difficolt� non � altro che la probalit� di generazione del ostacolo  
			N_obstacles++;
		}
	}

	void insert_obstacles() {
		int n = rand() % 2 + 2; // genera un numero compreso tra 2 e 4 indica quale ostacolo verr� generato
		ObjectType val = static_cast<ObjectType>(n);
		Object x(ObjectType val);
	}


public:
	LevelGenerator() {
		Level = 1;
		difficulty = Level * difficulty; // la difficolt� serve come parametro per la generazione degli ostacoli,
		                   //15 corrisponde al 15% che venga generato un ostacolo sulla riga, man mano che si sale di livello sale anche la probabilit�
		
	}

	LevelGenerator(int seed) {
		this->seed = seed;
		// seed livello 1
	}

	LevelGenerator(int seed, int Level) {
		// seed e livello
	}

	int GetRow(int positionRow){   // cambiare il tipo di ritorno in seguito
		// invia la riga richiesta
		return 0;
	}

};