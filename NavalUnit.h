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
	
	void move(Coordinates target);
	
	
public:
	void setPosition(Coordinates bow, Coordinates stern);	//chiamato inserimento Player
	vector<Coordinates> getGridPositions() {return getGridPositions(center);}	//vettore posizioni corrente unità
	vector<Coordinates> getGridPositions(Coordinates center);	//vettore nuova posizione per verificare se libero
	Coordinates getCenter() {return center;}
	void setCenter(Coordinates target); // {center = target;}
	int getSize() {return size;}
	int getShield() {return shield;}
	void hit(Coordinates target);	//in checkHit
	bool isHit(int pos) {return hitState[pos];}
	string getName(){return name;}
	bool isSunk() {return shield == 0;}
	void repair();
	
	virtual char getSymbol() = 0; 	//funzione virtuale
	
	virtual void action(Coordinates target) = 0;
};


#endif