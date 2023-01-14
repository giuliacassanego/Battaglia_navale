#include "NavalUnit.h"

void NavalUnit::setPosition(Coordinates bow, Coordinates stern)
{
	if (bow.getX() == stern.getX())
	{
		if(abs(stern.getY() - bow.getY()) != size)
		{
			throw invalid_argument("error: Invalid size");
		}
		vertical = true;
		center = Coordinates(bow.getX(), (bow.getY() + stern.getY())/2);
	}
	else if (bow.getY() == stern.getY())
	{
		if(abs(stern.getX() - bow.getX()) != size)
		{
			throw invalid_argument("error: Invalid size");
		}
		vertical = false;
		center = Coordinates((bow.getX() + stern.getX())/2, bow.getY());
	}
	else
	{
		throw invalid_argument("error: Invalid position");
	}
}

vector<Coordinates> NavalUnit::getGridPositions(Coordinates centerPos)
{
	vector<Coordinate> coords;
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