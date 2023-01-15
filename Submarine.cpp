#include <iostream>

#include "Submarine.h"

using namespace std;


void Submarine::action(Coordinates target)
{
	cout << "Submarine action" << endl;
	move(target);
	
}