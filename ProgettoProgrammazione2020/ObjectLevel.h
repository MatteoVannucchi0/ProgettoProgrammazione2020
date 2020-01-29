#pragma once

class LevelGenerator {
protected:
	Object MapLevel[][3];

public:
	LevelGenerator() {
		// rand casuale da implementare
	}

	LevelGenerator(int seed) {
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