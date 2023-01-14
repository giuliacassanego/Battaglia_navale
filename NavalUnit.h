#ifndef NAVALUNIT_H
#define NAVALUNIT_H

#include <string>

#include "Coordinates.h"

using namespace std;

class NavalUnit
{
protected:
	NavalUnit(string name, int size, Player player) : name(name), size(size), player(player);

	Player player;
	Coordinates center;
	bool vertical;
	int size;
	int shield;
	string name;
	
public:
	void setPosition(Coordinates bow, Coordinates stern);	//chiamato inserimento Player
	vector<Coordinates> getGridPositions() {return getGridPositions(center);}	//vettore posizioni corrente unità
	vector<Coordinates> getGridPositions(Coordinates center);	//vettore nuova posizione per verificare se libero
	Coordinates getCenter() {return center;}
	int getSize() {return size;}
	int getShield() {return shield;}
	string getName(){return name;}
	virtual char getSymbol() = 0; 	//funzione virtuale
};


#endif