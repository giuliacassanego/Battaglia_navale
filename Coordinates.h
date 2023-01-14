//Cassanego Giulia

#ifndef COORDINATES_H
#define COORDINATES_H

#include <string>

using namespace std;

class Coordinates
{
private:
int x;
int y;
	
public:
	Coordinates(string s);
	Coordinates(int x, int y);
	
	int getX() {return x;}
	int getY() {return y;}
	
	static string toY(int n);
	static string toX(int n);
};


#endif