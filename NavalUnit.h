/**
 * @author Giulia Cassanego 2032560
 * @class NavalUnit
 * @file NavalUnit.h
 * @brief This class contains the characteristics of each single unit and defines their common functions (superclass)
 */

#ifndef NAVALUNIT_H
#define NAVALUNIT_H

#include <string>
#include <vector>

#include "Coordinates.h"
class Player;	//forward reference to avoid recursive inclusion

using namespace std;

enum NavalUnitType 
{
	BATTLESHIP, 
	SUPPORTVESSEL,
	SUBMARINE
};
	

class NavalUnit
{
protected:
	NavalUnit(string name, int size, Player *player);

	Coordinates center;
	bool vertical;
	string name;
	int size;
	int shield;
	Player *player;
	vector<bool> hitState;
	
	void move(Coordinates target); //used in Submarine::action and Supportvessel::action

public:
    
	void setPosition(Coordinates bow, Coordinates stern); //used in Player::setUnitPosition
    
    //Vector containing the positions of the current unit
	vector<Coordinates> getGridPositions() {return getGridPositions(center);}
    
    //vector used to verify if the coordinates centers is free to set the unit 
	vector<Coordinates> getGridPositions(Coordinates center);
	Coordinates getCenter() {return center;}
	void setCenter(Coordinates target); 
	int getSize() {return size;}
	int getShield() {return shield;}
	void hit(Coordinates target);	//used in Player::checkHit
	bool isHit(int pos) {return hitState[pos];}
	string getName(){return name;}
	bool isSunk() {return shield == 0;}
	
    //Function which repair the naval unit in case of supportvessel's move
    void repair();
	
    //Virtual functions
	virtual char getSymbol() = 0;
	virtual void action(Coordinates target) = 0;
};


#endif