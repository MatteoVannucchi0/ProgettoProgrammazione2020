#pragma once
enum ObjectType {
	air,
	gas,
	obstacle,
	nails,
	pit,
	wall

};

class Object {
protected:
	ObjectType type;
public:
	char appearence;
	Object() {
	}

	Object(ObjectType type) {
		this->type = type;
		switch (type)
		{
		case nails:
			this->appearence = ',';
			break;
		case obstacle:
			this->appearence = 'X';
			break;
		case air:
			this->appearence = ' ';
			break;
		case gas:
			this->appearence = 'G';
			break;
		case pit:
			this->appearence = 'F';
			break;
		case wall:
			this->appearence = '|';
			break;
		default:
			break;
		}
	}

	ObjectType GetType() {
		return this->type;
	}
};

