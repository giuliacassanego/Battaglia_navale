/**
 * @author Giulia Cassanego 2032560
 * @class SupportVessel
 * @file SupportVessel.h
 * @brief This class is a subclass of NavalUnit
 */


#ifndef SUPPORTVESSEL_H
#define SUPPORTVESSEL_H

#include "NavalUnit.h"

class SupportVessel : public NavalUnit
{
public:
	SupportVessel(string name, Player *player) : NavalUnit(name, 3, player) {}
	char getSymbol() {return 'S';}
    
    //Implementation of the virtual function of the class player: Action move and repair
	void action(Coordinates target);
};

#endif