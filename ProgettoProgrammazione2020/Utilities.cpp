#include "Utilities.h"
#include <iostream>
using namespace std;


int mod(int a, int b) {
	return (a % b + b) % b;
}

int RandomInt(int min, int max) {
	return rand() % (max - min + 1) + min;
}
