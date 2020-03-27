#include "MapObject.h"

enum ObjectType {
	air,
	gas,
	obstacle,
	nails,
	pit

};

class Object {
protected:
	ObjectType type;
	char appearance;

	void ChangeAppearance() {
		switch (type)
		{
		case nails:
			this->appearance = '!';
			break;
		case obstacle:
			this->appearance = 'X';
			break;
		case air:
			this->appearance = ' ';
			break;
		case gas:
			this->appearance = 'G';
			break;
		case pit:
			this->appearance = 'U';
			break;
		default:
			break;
		}
	}


public:

	Object() {

		type = air;
		appearance = ' ';
	}

	Object(ObjectType x) {
		type = x;
		switch (type)
		{
		case nails:
			this->appearance = ',';
			break;
		case obstacle:
			this->appearance = 'X';
			break;
		case air:
			this->appearance = ' ';
			break;
		case gas:
			this->appearance = 'G';
			break;
		case pit:
			this->appearance = 'U';
			break;
		default:
			break;
		}
	}

	ObjectType GetType() {
		return this->type;
	}
	
	void PrintAppearance() {
		cout << appearance;
	}

	void ChangeType(ObjectType new_ob) {
		type = new_ob;
		ChangeAppearance();
	}
	
};
