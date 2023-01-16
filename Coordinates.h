//Cassanego Giulia

#ifndef COORDINATES_H
#define COORDINATES_H

#include <string>
#include <iostream>

using namespace std;

class Coordinates
{
private:
int x;
int y;
	
public:
	Coordinates() : x(-1), y(-1) {}
	Coordinates(string s);
	Coordinates(int x, int y);
	
	int getX() {return x;}
	int getY() {return y;}
	
	static string toY(int n);
	static string toX(int n);
	
	bool operator==(Coordinates& other) {return other.getX()==getX() && other.getY()==getY();}
};


#endif