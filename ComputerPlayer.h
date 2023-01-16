#ifndef COMPUTERPLAYER_H
#define COMPUTERPLAYER_H

#include <iostream>
#include "Player.h"
#include "Action.h"

using namespace std;

class ComputerPlayer : public Player{

    
public:
    ComputerPlayer(string n) : Player(n){prepareGrid();}
    Action nextAction();
    string randomChosePos();
    
    
    int chooseDirection();
    Coordinates findStern(NavalUnit* n, Coordinates bow);
    void prepareGrid();
    
    
};


#endif
