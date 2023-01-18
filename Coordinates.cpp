/**
 * @brief 
 * @param Definitions of functions of Coordinates
 */

#include "Coordinates.h"

Coordinates::Coordinates(string s)
{
	y = toupper(s[0]) - 'A';
	if (y > 8)
	{
		y -= 2;
	}
	x = (stoi(s.substr(1))) -1;
	
	//checks
	if (!isValid())
	{
		throw invalid_argument("error: Invalid coordinates");
	}
}

Coordinates::Coordinates(int x, int y) : x(x), y(y)
{
	//checks
	if (!isValid())
	{
		throw invalid_argument("error: Invalid coordinates");
	}
}

string Coordinates::toY(int n)
{
	string s;
	if (n < 0 || n > 11)
	{
		throw invalid_argument("error: Invalid coordinates");
	}
	if(n > 8)
	{
		n += 2;
	}
	return s += 'A' + n;
}

string Coordinates::toX(int n)
{
	if (n < 0 || n > 11)
	{
		throw invalid_argument("error: Invalid coordinates");
	}
	return to_string(n + 1) + (n < 9 ? "  " : " ");
}

bool Coordinates::isValid()
{
	if (x < 0 || x > 11 || y < 0 || y > 11)
	{
		return false;
	}
	return true;
}

string Coordinates::createString(Coordinates pos1, Coordinates pos2)
{
	string s;
	return s+= toY(pos1.getY()) + toX(pos1.getX()) + " " + toY(pos2.getY()) + toX(pos2.getX());
}