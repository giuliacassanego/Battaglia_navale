#include <iostream>
using namespace std;

#include "NavalUnit.h"
#include "Player.h"

NavalUnit::NavalUnit(string name, int size, Player *player) : name(name), size(size), shield(size), player(player) 
{
	for(int i = 0; i < size; i++)
	{
		hitState.push_back(false);
	}
}


void NavalUnit::setPosition(Coordinates bow, Coordinates stern)
{
	if (bow.getX() == stern.getX())
	{
		if(abs(stern.getY() - bow.getY()) != (size - 1))
		{
			cout << "Invalid size Y" << endl;
			throw invalid_argument("error: Invalid size");
		}
		vertical = true;
		center = Coordinates(bow.getX(), (bow.getY() + stern.getY())/2);
	}
	else if (bow.getY() == stern.getY())
	{
		if(abs(stern.getX() - bow.getX()) != (size - 1))
		{
			cout << "Invalid size X" << endl;
			throw invalid_argument("error: Invalid size");
		}
		vertical = false;
		center = Coordinates((bow.getX() + stern.getX())/2, bow.getY());
	}
	else
	{
		cout << "Invalid position" << endl;
		throw invalid_argument("error: Invalid position");
	}
}

vector<Coordinates> NavalUnit::getGridPositions(Coordinates centerPos)
{
	vector<Coordinates> coords;
	if (vertical)
	{
		for(int i = 0; i < size; i++)
		{
			coords.push_back(Coordinates(centerPos.getX(), centerPos.getY() - size/2 + i));
		}
	}
	else
	{
		for(int i = 0; i < size; i++)
		{
			coords.push_back(Coordinates(centerPos.getX() - size/2 + i, centerPos.getY()));
		}
	}
	return coords;
}

void NavalUnit::move(Coordinates target)
{
	Coordinates oldCenter = getCenter();
	try
	{
		player->getGrid().clear(this);
		setCenter(target);
		player->getGrid().insert(this);
	}
	catch(exception e)
	{
		cout << "Insert failed" << endl;
		setCenter(oldCenter);
		player->getGrid().insert(this);
		throw invalid_argument("Invalid position");
	}
}

void NavalUnit::hit(Coordinates target)
{
	vector<Coordinates> positions = getGridPositions();
	for(int i = 0; i < positions.size();i++)
	{
		if(positions[i] == target)
		{
			if(!hitState[i])	//non era già stato colpito
			{
				shield--;
			}
			hitState[i] = true;
			player->getGrid().getDefense(target).setHit();
		}
	}
}

void NavalUnit::repair()
{
	shield = size;
	for(int i = 0; i < size; i++)
	{
		hitState[i] = false;
	}
}