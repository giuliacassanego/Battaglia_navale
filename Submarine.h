/**
 * @author Giulia Cassanego 2032560
 * @class Submarine
 * @file Submarine.h
 * @brief This class is a subclass of NavalUnit
 */


#ifndef SUBMARINE_H
#define SUBMARINE_H

#include "NavalUnit.h"

class Submarine : public NavalUnit
{
public:
	Submarine(string name, Player *player) : NavalUnit(name, 1, player) {}
	char getSymbol() {return 'E';}
	
    //Implementation of the virtual function of the class player: Action move and scan
	void action(Coordinates target);
};

#endif