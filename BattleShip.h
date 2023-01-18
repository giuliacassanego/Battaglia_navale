/**
 * @class BattleShip
 * @author Giulia Cassanego
 * @date 17/01/2023
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
	void action(Coordinates target);
};

#endif