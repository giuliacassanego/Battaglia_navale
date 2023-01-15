#include <iostream>

#include "BattleShip.h"
#include "Player.h"

using namespace std;


void BattleShip::action(Coordinates target)
{
	cout << "Battleshp action" << endl;
	bool hit = player->hitOpponent(target);
	cout << "hit: " << hit << endl;
	if(hit)
	{
		player->getGrid().getAttack(target).setHit();
	}
	else
	{
		player->getGrid().getAttack(target).setMiss();	
	}
	
}