#include <cstdlib>
#include <ctime>

#include "GamePlay.h"
#include "ComputerPlayer.h"
#include "HumanPlayer.h"

using namespace std;

Player GamePlay::playGame()
{
	switch(mode)
	{
		case PC:
		{
			HumanPlayer p1("Player1");
			ComputerPlayer p2("Player2");
			break;
		}
		case CC:
		{
			ComputerPlayer p1("Player1");
			ComputerPlayer p2("Player2");
			break;
		}
		default:
			break;
	}
	
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
}

int GamePlay::start()
{
    srand(time(NULL));
    int n = rand()%2+1; //numero casuale da 1 a 2
    return n;
}

