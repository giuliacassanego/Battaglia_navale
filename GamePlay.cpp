#include <cstdlib>
#include <ctime>

#include "GamePlay.h"
#include "ComputerPlayer.h"
#include "HumanPlayer.h"

using namespace std;

void GamePlay::playGame()
{
	switch(mode)
	{
		case PC:
		{
			HumanPlayer p1("Player1");
			ComputerPlayer p2("Player2");
			
			int first = start();
			Player* active;
			if(first == 1)
			{
				active = &p1;
			}
			else
			{
				active = &p2;
			}
			
			int n = 0;
			while(n < 6)
			{
				Action a = active->nextAction();
				active->play(a);
				if(active->hasLost())
				{
					cout << active->getName() << " has lost :(";
					break;
				}
				//active = (active == &p1 ? &p2 : &p1);
				if(active == &p1)
				{
					active = &p2;
				}
				else
				{
					active = &p1;
				}
				n++;
			}
			cout << p1.checkWin()->getName() << " has won :)";
					break;
				}
		case CC:
		{
			ComputerPlayer p1("Player1");
			ComputerPlayer p2("Player2");
			
			int first = start();
			Player* active = (first == 1 ? &p1 : &p2);
			
			int n = 0;
			while(n < 6)
			{
				Action a = active->nextAction();
				active->play(a);
				if(active->hasLost())
				{
					cout << active->getName() << " has lost :(";
					break;
				}
				active = (active == &p1 ? &p2 : &p1);
				n++;
			}
			cout << p1.checkWin()->getName() << " has won :)";
			break;
		}
		default:
			break;
	}
	
	
}

int GamePlay::start()
{
    srand(time(NULL));
    int n = rand()%2+1; //numero casuale da 1 a 2
    return n;
}
/*
void GamePlay::activePlayer(Player p1, Player p2)
{
	int first = start();
	Player* active = (first == 1 ? &p1 : &p2);
	
	int n = 0;
	while(n < 6)
	{
		Action a = active->nextAction();
		active->play(a);
		if(active->hasLost())
		{
			cout << active->getName() << " has lost :(";
			break;
		}
		active = (active == &p1 ? &p2 : &p1);
		n++;
	}
	cout << p1.checkWin()->getName() << " has won :)";
}*/

