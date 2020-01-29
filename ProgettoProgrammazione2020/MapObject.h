#pragma once
enum ObjectType {
	wall,
	obstacle,
	air
};

class Object {
protected:
	char appearence;
	ObjectType type;
public:
	Object() {
		
	}

	Object(ObjectType type) {
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

	void Draw();
};

