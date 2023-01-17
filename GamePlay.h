#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include "Player.h"

enum PlayMode 
{
	PC,
	CC
};

class GamePlay
{
private:
	PlayMode mode;
	
	int start();
	
public:
	GamePlay(PlayMode mode) : mode(mode) {}
	
	void playGame();
	//void activePlayer(Player p1, Player p2);
};

#endif