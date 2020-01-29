#pragma once
enum ObjectType {
	wall,
	obstacle,
	air
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
		case wall:
			this->appearence = '|';
			break;
		case obstacle:
			this->appearence = 'X';
			break;
		case air:
			this->appearence = ' ';
			break;
		default:
			break;
		}
	}

	ObjectType GetType() {
		return this->type;
	}
};

