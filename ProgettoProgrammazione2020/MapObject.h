#pragma once
#include <iostream>
#include <cstdlib>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include "Constant.h"
using namespace std;


enum ObjectType {
	air,
	gas,
	obstacle,
	nails,
	pit,
	wall
}

class Object {
protected:
	ObjectType type;
	void ChangeAppearance();
public:
	char appearence;

	Object();
	Object(ObjectType type);

	ObjectType GetType();
	
	void ChangeType(ObjectType newType);
	void PrintAppearance();
};

