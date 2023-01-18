/**
 * @brief Definitions of functions of Submarine
 * @param target
 */

#include <iostream>

#include "Submarine.h"
#include "Player.h"

using namespace std;


void Submarine::action(Coordinates target)
{
	cout << "Submarine action" << endl;

	try{
		move(target);
	}
	catch(invalid_argument e)
	{
		cout << e.what() << endl;
	}

	vector<Coordinates> pos = player->scan(target);
	for(int i = 0; i < pos.size(); i++)
	{
		player->getGrid().getAttack(pos[i]).setSonar();
	}
}