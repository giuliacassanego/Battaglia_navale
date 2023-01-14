//Cassanego Giulia

#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include "Grid.h"

using namespace std;

class Player
{
private:
    int hits; //numero dei colpi andati a segno
    bool win;
	Corazzata corazzata1;
    Corazzata corazzata2;
    Corazzata corazzata3;
    
    NaveSupporto nave1;
    NaveSupporto nave2;
    NaveSupporto nave3;
    
    Sottomarino sottomarino1;
    Sottomarino sottomarino2;
	
	Player &opponent;
	Grid grid;

public:
	Player(string n);
	
	//member functions
	void init();	//piazza unità, specifico per human chiede dove
	void play();	//fa prossima mossa, chiama move,fire,ecc
	void move(NavalUnit unit, Coordinates target);	//usata in play
	
	bool checkHit(Coordinates pos);//aggiorna shield
	bool getTotalShield();//tutti shield a zero=perso
	
	
    void hasHit();
    int getHits();
    void hasWin();
	Grid getGrid();
	Corazzata getCor1();
	Corazzata getCor2();
	Corazzata getCor3();
	NaveSupporto getNave1();
	NaveSupporto getNave2();
	NaveSupporto getNave3();
	Sottomarino getSub1();
};

#endif
