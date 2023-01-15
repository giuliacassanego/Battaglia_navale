#ifndef SUPPORTVESSEL_H
#define SUPPORTVESSEL_H

#include "NavalUnit.h"

class SupportVessel : public NavalUnit
{
public:
	SupportVessel(string name, Player *player) : NavalUnit(name, 3, player) {}
	char getSymbol() {return 'S';}
	void action(Coordinates target);
};

#endif