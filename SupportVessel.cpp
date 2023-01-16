#include <iostream>

#include "SupportVessel.h"
#include "Player.h"

using namespace std;


void SupportVessel::action(Coordinates target)
{
	cout << "SupportVessel action" << endl;
	move(target);
	
	for(int i = target.getX() -2; i < target.getX() +2; i++)
	{
		for(int j = target.getY()-2; j < target.getY()+2; j++)
		{
			GridCell& cell = player->getGrid().getDefense(Coordinates(i,j));
			NavalUnit *unit = cell.getUnit();
			if(!cell.isVoid() && unit!=this)
			{
				unit->repair();
		
				player->getGrid().clear(unit);	//tolgo unità con vecchi valori
				player->getGrid().insert(unit);	//la reinserisco con valori aggiornati			
			}
		}
	}
}