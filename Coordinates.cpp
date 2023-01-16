//Cassanego Giulia

#include "Coordinates.h"
#include <iostream>

Coordinates::Coordinates(string s)
{
	y = toupper(s[0]) - 'A';
	if (y > 8)
	{
		y -= 2;
	}
	x = stoi(s.substr(1));
	
	//checks
	if (x < 0 || x > 11 || y < 0 || y > 11)
	{
		throw invalid_argument("error: Invalid coordinates");
	}
}

Coordinates::Coordinates(int x, int y) : x(x), y(y)
{
	//checks
	if (x < 0 || x > 11 || y < 0 || y > 11)
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
