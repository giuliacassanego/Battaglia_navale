/**
 * @brief Definitions of functions of GridCell
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
		return (isHit ? tolower(c) : c);
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