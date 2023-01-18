/**
 * @author Giulia Cassanego 2032560
 * @brief Executable
 * @param argc
 * @param argv
 */

#include <stdio.h>
#include <iostream>

#include "Grid.h"
#include "Player.h"
#include "GamePlay.h"

using namespace std;

int main(int argc, char** argv)
{
	//check of the command line input
    if(argc != 2)
	{
		cout << "error: Unspecified type of players" << endl;
		return 0;
	}
	char c1 = argv[1][0];
	char c2 = argv[1][1];
	if(!(c1 == 'p' || c1 == 'c') || c2 != 'c')
	{
		cout << "error: Unspecified type" << endl;
		return 0;
	}
	PlayMode mode;
	if(c1 == 'p')
	{
		mode = PC;
	}
	else
	{
		mode = CC;
	}
    
    //start of the game
	GamePlay game(mode);
	game.playGame();
	
	return 0;
}
