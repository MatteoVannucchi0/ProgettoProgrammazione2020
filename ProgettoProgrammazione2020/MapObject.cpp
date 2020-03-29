#include "MapObject.h"

Object::Object() {

}

Object::Object(ObjectType type) {
	this->type = type;
	this->ChangeAppearance(this->type);
}

void Object::ChangeAppearance(){
	switch (this->type)
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
	case wall:
		this->appearance = '|';
		break;
	default:
		break;
	}
}

Object Object::GetType() {
	return this->type;
}

void Object::ChangeType(Type newType) {
	this->type = newType;
	this->ChangeAppearance();
}

void Object::PrintAppearance() {
	cout << this->appearence;
}
