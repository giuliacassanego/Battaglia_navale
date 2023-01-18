/**
 * @brief Definitions of functions of SupportVessel
 * @param target
 */

#include <iostream>

#include "SupportVessel.h"
#include "Player.h"

using namespace std;


void SupportVessel::action(Coordinates target)
{
	cout << "SupportVessel action" << endl;
	
	try{
		move(target);
	}
	catch(invalid_argument e)
	{
		cout << e.what() << endl;
	}

	for(int i = target.getX() - 1; i <= target.getX() + 1; i++)	//area 3x3
	{
		for(int j = target.getY() - 1; j <= target.getY() + 1; j++)
		{
			try
			{
				if(Coordinates(i,j).isValid())
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
			catch(invalid_argument e) {}
		}
	}
}