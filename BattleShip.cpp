/**
 * @author Giulia Cassanego 2032560
 * @brief Definition of the functions of BattleShip.h
 */

#include <iostream>

#include "BattleShip.h"
#include "Player.h"

using namespace std;


void BattleShip::action(Coordinates target)
{
	cout << "Battleship action" << endl;
	bool hit = player->hitOpponent(target);
    
	cout << "hit: " << hit << endl; //0=not hit, 1 = hit 
	if(hit)
	{
		player->getGrid().getAttack(target).setHit();
	}
	else
	{
		player->getGrid().getAttack(target).setMiss();	
	}
}