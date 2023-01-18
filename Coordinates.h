/**
 * @author Angelica Zonta 2032570
 * @class Coordinates
 * @file Cooridantes.h
 * @brief This class initialize functions to save the grid's coordinates
 */

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
	
    //Creation of a string with the coordinates of each navalunits for the log file
	static string createString(Coordinates pos1, Coordinates pos2); 
	
	//Check if the coordinate is out of bound
    bool isValid(); 
	
	bool operator==(Coordinates& other) {return other.getX()==getX() && other.getY()==getY();}
};


#endif