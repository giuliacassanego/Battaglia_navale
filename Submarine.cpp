#include <iostream>

#include "Submarine.h"
#include "Player.h"

using namespace std;


void Submarine::action(Coordinates target)
{
	cout << "Submarine action" << endl;
	move(target);
	
	vector<Coordinates> pos = player->scan(target);
	for(int i = 0; i < pos.size(); i++)
	{
		player->getGrid().getAttack(pos[i]).setSonar();
	}
}