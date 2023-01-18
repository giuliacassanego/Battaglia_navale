/**
 * @author Angelica Zonta 2032570
 * @brief Definition of functions of GridCell.h
 */
 
#include "GridCell.h"

void GridCell::clear()
{
	isHit = false;
	isMiss = false;
	isSonar = false;
	p = nullptr;
}

char GridCell::getSymbol()
{
	if(p)
	{
		char c = p->getSymbol();
		return (isHit ? tolower(c) : c); //check of the hit status and return the relative symbol
	}
	if(isSonar)
	{
		return 'Y';
	}
	if(isHit)
	{
		return 'X';
	}
	if(isMiss)
	{
		return 'O';
	}
	return ' ';
}