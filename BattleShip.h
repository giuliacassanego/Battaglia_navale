/**
 * @author Giulia Cassanego 2032560
 * @class BattleShip
 * @file BattleShip.h
 * @brief This class is a subclass of NavalUnit
 */

#ifndef BATTLESHIP_H
#define BATTLESHIP_H

#include "NavalUnit.h"

class BattleShip : public NavalUnit
{
public:
    BattleShip(string name, Player *player) : NavalUnit(name, 5, player) {}
	char getSymbol() {return 'C';}
    
    //Implementation of the virtual function of the class player: Action fire
	void action(Coordinates target);
};

#endif