/**
 * @author Angelica Zonta 2032570
 * @class Player
 * @file Player.h
 * @brief This class initializes an object player
 */
 
#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include "Grid.h"
#include "NavalUnit.h"
#include "Action.h"

using namespace std;

class Player
{
protected:
	string n;
	vector<NavalUnit*> units;
	vector<string> initPos;	//save bow and stern for the insert for the log.txt
	vector<string> actionCoords; //save source and target for the action for the log.txt
	Player *opponent;
	Grid grid;

public:
	Player(string name);
	
	string getName() {return n;}
	
    //returns the pointer to the units of the player
	NavalUnit* addUnit(NavalUnitType type, string name); 
    //inserts the units in the grid given their bow and stern
	void setUnitPosition(NavalUnit* unit, Coordinates bow, Coordinates stern);
	NavalUnit* findUnit(Coordinates center);
	
    //make the action
	void play(Action action);
	
    //virtual function
	virtual void prepareGrid() = 0;
    virtual Action nextAction() = 0;
	
   
	bool checkHit(Coordinates pos); //update shield
    int getTotalShield(); //count the number of shields, if shield=0 the player has lost
    
	Player* checkWin();
	Grid& getGrid() {return grid;}
	
	bool hitOpponent(Coordinates target);
	void setOpponent(Player *opp) {opponent = opp;}
	
	vector<Coordinates> scan(Coordinates center); //used in Submarine::action
	
	string getInitPos();
	string getActionCoords();
};

#endif
