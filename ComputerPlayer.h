/**
 * @author Angelica Zonta 2032570
 * @class ComputerPlayer
 * @file ComputerPlayer.h
 * @brief This class initialize functions to play the CC game
 */


#ifndef COMPUTERPLAYER_H
#define COMPUTERPLAYER_H

#include <iostream>
#include <vector>
#include "Player.h"
#include "Action.h"
#include "Coordinates.h"

using namespace std;

class ComputerPlayer : public Player{
    
public:
    ComputerPlayer(string n) : Player(n){prepareGrid();}
    
    //Function that randomly chooses the action to perform
    Action nextAction(); 
    Coordinates randomChosePos(); 
    int chooseDirection(); //vertical or horizontal
    
    //Return the stern of the units giving as parameter the bow
    Coordinates findStern(NavalUnit* n, Coordinates bow); 
    
    //Random creation of a grid
    void prepareGrid(); 
  
};


#endif
