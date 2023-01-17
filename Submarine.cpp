#include <iostream>

#include "Submarine.h"
#include "Player.h"

using namespace std;


void Submarine::action(Coordinates target)
{
	cout << "Submarine action" << endl;
	
    bool correct = false;
    while(correct!= true)
    {
        try{
            move(target);
        }
        catch(invalid_argument e){cout << "errore in move di sumbarine" <<e.what() <<endl;}
    }
    
	
	vector<Coordinates> pos = player->scan(target);
	for(int i = 0; i < pos.size(); i++)
	{
		player->getGrid().getAttack(pos[i]).setSonar();
	}
    cout << player->getGrid();
}