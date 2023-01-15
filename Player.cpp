//Cassanego Giulia
#include <iostream>
#include <stdexcept>

#include "Player.h"
#include "Grid.h"
#include "BattleShip.h"
#include "SupportVessel.h"
#include "Submarine.h"

using namespace std;

Player::Player(string n)
{
    hits=0; 
    win = false;
}

Grid& Player::getGrid()
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

NavalUnit* Player::addUnit(NavalUnitType type, string name)	//piazza unità, specifico per human chiede dove
{
	NavalUnit* entry;
	switch(type)
	{
		case BATTLESHIP:
			entry = new BattleShip(name, this);
			break;
		case SUPPORTVESSEL:
			entry = new SupportVessel(name, this);
			break;
		case SUBMARINE:
			entry = new Submarine(name, this);
			break;
	}
	units.push_back(entry);
	return entry;
}

void Player::setUnitPosition(NavalUnit* unit, Coordinates bow, Coordinates stern)
{
	unit->setPosition(bow, stern);
	grid.insert(unit);
}

NavalUnit* Player::findUnit(Coordinates center)
{
	for(int i = 0; i < units.size(); i++)
	{
		if(units[i]->getCenter() == center)
		{
			return units[i];
		}
	}
	return nullptr;
}

void Player::play(Action action)	//fa prossima mossa, chiama move,fire,ecc
{
	switch(action.getType())
	{
		case UNIT_ACTION:
			NavalUnit *unit = findUnit(action.getSource());
			if(unit == nullptr)
			{
				throw illegal_argument("Invalid source");
			}
			unit->action(action.getTarget());
			break;
		case CLEAR:
			getGrid().deleteSonar();
			break;
		case SHOW:
			break;
	}
}

bool Player::checkHit(Coordinates pos)
{
	GridCell& cell = getGrid().getDefense(pos);
	if(cell.isVoid())
	{
		return false;
	}
	cell.getUnit()->hit(pos);
	if(cell.getUnit()->isSunk())
	{
		getGrid().clear(cell.getUnit());
	}
	return true;
}

bool Player::hitOpponent(Coordinates target)
{
	return opponent->checkHit(target);
}

/*
	
	
	
	bool Player::checkHit(Coordinates pos);//aggiorna shield
	int Player::getTotalShield();*/