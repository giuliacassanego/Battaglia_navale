#include <stdio.h>
#include <iostream>

#include "Grid.h"
#include "Player.h"

using namespace std;

int main(void)
{
	try
	{
	Player player1("Player1");
	Player player2("Player2");
	player1.setOpponent(&player2);
	player2.setOpponent(&player1);
	
	cout << "Player created" << endl;
	NavalUnit* battleship1 = player1.addUnit(BATTLESHIP, "c1");
	NavalUnit* submarine1 = player1.addUnit(SUBMARINE, "e1");
	NavalUnit* supportvessel1 = player1.addUnit(SUPPORTVESSEL, "s1");
	cout << "units added" << endl;
	player1.setUnitPosition(battleship1, Coordinates(1,1), Coordinates(5,1));
	player1.setUnitPosition(submarine1, Coordinates(4,2), Coordinates(4,2));
	player1.setUnitPosition(supportvessel1, Coordinates(5,11), Coordinates(7,11));
	cout << "print grid1" << endl;
	cout << player1.getGrid();
	

	cout << "Player created" << endl;
	NavalUnit* battleship2 = player2.addUnit(BATTLESHIP, "c1");
	NavalUnit* submarine2 = player2.addUnit(SUBMARINE, "e1");
	NavalUnit* supportvessel2 = player2.addUnit(SUPPORTVESSEL, "s1");
	cout << "units added" << endl;
	player2.setUnitPosition(battleship2, Coordinates(1,1), Coordinates(5,1));
	player2.setUnitPosition(submarine2, Coordinates(4,2), Coordinates(4,2));
	player2.setUnitPosition(supportvessel2, Coordinates(5,11), Coordinates(7,11));
	cout << "print grid2" << endl;
	cout << player2.getGrid();
	
	cout << "Moving battleship" << endl;
	battleship1->action(Coordinates(6,11));
	battleship1->action(Coordinates(3,1));
	submarine1->action(Coordinates(0,4));
	cout << "print grid1" << endl;
	cout << player1.getGrid();
	cout << "print grid2" << endl;
	cout << player2.getGrid();
	
	
	battleship1->action(Coordinates(1,1));
	battleship1->action(Coordinates(1,2));
	cout << "print grid2" << endl;
	cout << player2.getGrid();
	
	supportvessel2->action(Coordinates(2,0));
	cout << player2.getGrid();

	
	battleship1->action(Coordinates(6,7));
	cout << "print grid1" << endl;
	cout << player1.getGrid();
	cout << "print grid2" << endl;
	cout << player2.getGrid();	
	
	submarine1->action(Coordinates(0,3));
	cout << "print grid1" << endl;
	cout << player1.getGrid();
	cout << "print grid2" << endl;
	cout << player2.getGrid();	
	
	return 0;
	}
	catch(invalid_argument e)
	{
		cout << e.what() << endl;
	}

}
