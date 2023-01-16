#ifndef COMPUTERPLAYER_H
#define COMPUTERPLAYER_H

#include <iostream>
#include "Player.h"
#include "Action.h"

using namespace std;

class ComputerPlayer : public Player{

public:
    ComputerPlayer(string n) : Player(n){}
    Action nextAction();
    string randomChosePos();
    
};


#endif