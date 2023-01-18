//Cassanego Giulia

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
    int hits; //numero dei colpi andati a segno
    bool win;
	vector<NavalUnit*> units;
	vector<string> initPos;	//poppa e prua nell'insert
	vector<string> actionCoords;	//source e target per azioni
	Player *opponent;
	Grid grid;

public:
	Player(string name);
	
	string getName() {return n;}
	
	NavalUnit* addUnit(NavalUnitType type, string name); //piazza unità, specifico per human chiede dove
	void setUnitPosition(NavalUnit* unit, Coordinates bow, Coordinates stern);
	NavalUnit* findUnit(Coordinates center);
	virtual Action nextAction() = 0;	//human chiede, computer random
	void play(Action action);	//fa prossima mossa, chiama move,fire,ecc
	void move(NavalUnit* unit, Coordinates target);	//usata in play
	
	virtual void prepareGrid() = 0;
	
	bool checkHit(Coordinates pos);//aggiorna shield
	int getTotalShield();//tutti shield a zero=perso
	
    void hasHit() {hits++;}
    int getHits() {return hits;}
	Player* checkWin();
	Grid& getGrid() {return grid;}
	
	bool hitOpponent(Coordinates target);
	void setOpponent(Player *opp) {opponent = opp;}
	
	vector<Coordinates> scan(Coordinates center);
	
	string getInitPos();
	string getActionCoords();
};

#endif
