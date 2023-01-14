//Cassanego Giulia
#include <iostream>
#include <stdexcept>

#include "Player.h"
#include "Grid.h"
//#include "Corazzata.h"
//#include "NaveSupporto.h"
//#include "SottoMarino.h"

using namespace std;

Player::Player(string n):
corazzata1("corazzata1", this),
corazzata2("corazzata2", this),
corazzata3("corazzata3", this),
nave1("nave1", this),
nave2("nave2", this),
nave3("nave3", this),
sottomarino1("sottomarino1", this),
sottomarino2("sottomarino2", this),
{
    hits=0; 
    win = false;
}

Grid Player::getGrid()
{
    return grid;
}

void Player::hasHit()
{
    hits++;
}

int Player::getHits()
{
    return hits;
}

void Player::hasWin()
{
    win = true;
}

Corazzata Player::getCor1()
{
	return corazzata1;
}

Corazzata Player::getCor2()
{
	return corazzata2;
}

Corazzata Player::getCor3()
{
	return corazzata3;
}

NaveSupporto Player::getNave1()
{
	return nave1;
}

NaveSupporto Player::getNave2()
{
	return nave2;
}

NaveSupporto Player::getNave3()
{
	return nave3;
}

Sottomarino Player::getSub1()
{
	return sottomarino1;
}

Sottomarino Player::getSub2()
{
	return sottomarino2;
}