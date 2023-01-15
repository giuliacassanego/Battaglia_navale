#ifndef SUBMARINE_H
#define SUBMARINE_H

#include "NavalUnit.h"

class Submarine : public NavalUnit
{
public:
	Submarine(string name, Player *player) : NavalUnit(name, 1, player) {}
	char getSymbol() {return 'E';}
	
	void action(Coordinates target);
};

#endif