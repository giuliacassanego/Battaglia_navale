#ifndef HUMANPLAYER_H
#define HUMANPLAYER_H

#include <iostream>
#include "Player.h"
#include "Action.h"

using namespace std;

class HumanPlayer : public Player{

public:
    HumanPlayer(string n) : Player(n){}
    Action nextAction();

    
};






#endif
