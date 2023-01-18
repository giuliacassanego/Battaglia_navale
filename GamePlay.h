/**
 * @author Giulia Cassanego 2032560
 * @class GamePlay
 * @file GamePlay.h
 * @brief This class plays the CC or the PC game
 */


#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include <fstream>
#include "Player.h"

//enum of the possibile game mode insertable from the command line
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
    
	//Randomly choose the beginner of the game
    int start(); 
	
public:
	GamePlay(PlayMode mode) : mode(mode) {}
    
    //Function which plays the game
	void playGame(); 
};

#endif