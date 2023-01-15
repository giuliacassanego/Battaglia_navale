//Cassanego Giulia 2032560

#include <ostream>
#include <stdio.h>
#include <cctype>

#include "Grid.h"
#include "Coordinates.h"
#include "NavalUnit.h"

using namespace std;

GridCell& Grid::getDefense(Coordinates pos)
{
	return defense[pos.getX()][pos.getY()];
}

GridCell& Grid::getAttack(Coordinates pos)
{
	return attack[pos.getX()][pos.getY()];
}

bool Grid::verifyIsFree(vector<Coordinates> coords)
{
	for(int i = 0; i < coords.size(); i ++)
	{
		if(!getDefense(coords[i]).isVoid())
		{
			return false;
		}
	}
	return true;
}

void Grid::insert(NavalUnit *unit)
{
	vector<Coordinates> coords = unit -> getGridPositions();
	if(!verifyIsFree(coords))
	{
		throw invalid_argument("Position already occupied");
	}
	for (int i = 0; i < coords.size(); i++)
	{
		getDefense(coords[i]).setUnit(unit, unit->isHit(i));
	}
}

void Grid::clear(NavalUnit *unit)
{
	vector<Coordinates> coords = unit -> getGridPositions();
	for (int i = 0; i < coords.size(); i++)
	{
		getDefense(coords[i]).clear();
	}
}

void Grid::deleteSonar()	//cerco Y e riporto a carattere iniziale
{
	for(int i = 0; i < 12; i++)
	{
		for(int j = 0; j < 12; j++)
		{
			getAttack(Coordinates(i, j)).resetSonar();
		}
	}
}

ostream& operator<< (ostream& os, Grid grid)
{
	os << endl << "Griglia di difesa                                         Griglia di attacco" << endl;
	//griglia difesa
	for (int j = 0; j < 12; j++)
	{
		os << Coordinates::toY(j) << " | ";
		for (int i = 0; i < 12; i++)
		{
			os << grid.getDefense(Coordinates(i, j)).getSymbol() << " | ";
		}
		
		cout << "      ";
		os << Coordinates::toY(j) << " | ";
		for (int i = 0; i < 12; i++)
		{
			os << grid.getAttack(Coordinates(i, j)).getSymbol() << " | ";
		}
		os << endl;
	}
	
	os << "  | ";
	for (int i = 0; i < 12; i++)	//stampo ultima riga, solo numeri senza |
	{
		os << Coordinates::toX(i) << " ";
	}
	cout << "      ";
	os << "  | ";
	for (int i = 0; i < 12; i++)	//stampo ultima riga, solo numeri senza |
	{
		os << Coordinates::toX(i) << " ";
	}
/*
	os << endl << endl << "Griglia di attacco" << endl;
	
	//griglia attacco
	for (int j = 0; j < 12; j++)
	{
		os << Coordinates::toY(j) << " | ";
		for (int i = 0; i < 12; i++)
		{
			os << grid.getAttack(Coordinates(i, j)).getSymbol() << " | ";
		}
		os << endl;
	}
	os << "  | ";
	for (int i = 0; i < 12; i++)	//stampo ultima riga, solo numeri senza |
	{
		os << Coordinates::toX(i) << " ";
	}
*/	
	return os << endl;
}
