#pragma once
enum class ObjectType {
	air = 0,
	gas = 1,
	obstacle = 2,
	nails = 3,
	pit = 4

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
		case nails = 3:
			this->appearence = ',';
			break;
		case obstacle = 2:
			this->appearence = 'X';
			break;
		case air = 0:
			this->appearence = ' ';
			break;
		case gas = 1:
			this->appearence = 'G';
			break;
		case pit = 4:
			this->appearence = 'U';
			break;
		default:
			break;
		}
	}

	void Draw();
};

