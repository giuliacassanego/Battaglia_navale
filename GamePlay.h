#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include <fstream>

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
	ofstream logFile;
	int start();
	
public:
	GamePlay(PlayMode mode) : mode(mode) {}
	
	void playGame();
};

#endif