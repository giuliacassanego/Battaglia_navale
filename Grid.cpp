//Cassanego Giulia 2032560

#include <ostream>
#include <stdio.h>
#include <cctype>

#include "Grid.h"
#include "Coordinates.h"
#include "NavalUnit.h"

using namespace std;

Grid::Grid()
{
	//all'inizio tutti spazi
	for(int i = 0; i < 12; i++)
	{
		for(int j = 0; j < 12; j++)
		{
			defense[i][j] = ' ';
			attack[i][j] = ' ';
		}
	}
}

string Grid::getDefense(Coordinates pos)
{
	return defense[pos.getX()][pos.getY()];
}

string Grid::getAttack(Coordinates pos)
{
	return attack[pos.getX()][pos.getY()];
}

void Grid::setDefense(Coordinates pos, char c)
{
	if (c != 'C' && c != 'E' && c != 'S')	
	{
		throw invalid_argument("error: Invalid letter entered"); 
	}
	defense[pos.getX()][pos.getY()] = c;
}

void Grid::setAttack(Coordinates pos, char c)
{
	if (c != 'O' && c != 'X' && c != 'Y')	
	{
		throw invalid_argument("error: Invalid letter entered"); 
	}
	attack[pos.getX()][pos.getY()] = c;
}

bool Grid::isFree(Coordinates pos)
{
	if(getDefense(pos) == " ")
		return true;
	return false;
}

bool Grid::verifyIsFree(vector<Coordinates> coords)
{
	for(int i = 0; i < coords.size(); i ++)
	{
		if(!isFree(coords[i]))
		{
			return false;
		}
	}
	return true;
}

void Grid::insert(NavalUnit unit)	//bow=prua, stern=poppa
{
	vector<Coordinates> coords = unit.getGridPosition();
	for (int i = 0; i < coords.size(); i++)
	{
		if(!isFree(coords[i]))
		{
			throw invalid_argument("Position already occupied");
		}
	}
	for (int i = 0; i < coords.size(); i++)
	{
		setDefense(coords[i], unit.getSymbol());
	}
}

void Grid::clear(NavalUnit unit)
{
	vector<Coordinates> coords = unit.getGridPosition();
	for (int i = 0; i < coords.size(); i++)
	{
		setDefense(coords[i], ' ');
	}
}

void Grid::deleteSonar()	//cerco Y e riporto a carattere iniziale
{
	for(int i = 1; i < 13; i++)
	{
		for(int j = 0; j < 12; j++)
		{
			if(attack[i][j] == "Y")
			{
				attack[i][j] = "Y";
			}
		}
	}
}

ostream& operator<< (ostream& os, Grid grid)
{
	os << endl << "Griglia di difesa" << endl;
	//griglia difesa
	for (int j = 0; j < 12; j++)
	{
		os << Coordinates::to_y(j) << " | ";
		for (int i = 0; i < 12; i++)
		{
			os << grid.getDefense(i, j) << " | ";
		}
		os << endl;	// << "-------------";
	}
	os << "  | ";
	for (int i = 0; i < 12; i++)	//stampo ultima riga, solo numeri senza |
	{
		os << Coordinates::to_x(i) << " ";
	}
	os << endl << endl << "Griglia di attacco" << endl;
	
	//griglia attacco
	for (int j = 0; j < 12; j++)
	{
		os << Coordinates::to_y(j) << " | ";
		for (int i = 0; i < 12; i++)
		{
			os << grid.getAttack(i, j) << " | ";
		}
		os << endl;	// << "-------------";
	}
	os << "  | ";
	for (int i = 0; i < 12; i++)	//stampo ultima riga, solo numeri senza |
	{
		os << Coordinates::to_x(i) << " ";
	}
	
	return os << endl;
}
