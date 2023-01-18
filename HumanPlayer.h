/**
 * @author Angelica Zonta 2032570
 * @class HumanPlayer
 * @file HumanPlayer.h
 * @brief This class initializes functions to play the PC game
 */

#ifndef HUMANPLAYER_H
#define HUMANPLAYER_H

#include <iostream>
#include "Player.h"
#include "Action.h"

using namespace std;

class HumanPlayer : public Player{

public:
    HumanPlayer(string n) : Player(n){prepareGrid();}
    
    //Function that interacts with the user to know the next action to perform
    Action nextAction(); 
    
    //Creation of the grid with the coordinates chosen by the user
    void prepareGrid();
};

#endif