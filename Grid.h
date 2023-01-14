//Cassanego Giulia 2032560

#ifndef GRID_H
#define GRID_H

#include <iostream>
using namespace std;

class Grid
{
private:
	string defense[12][12];
	string attack[12][12];

public:
	Grid();
	string getDefense(Coordinates pos);
	string getAttack(Coordinates pos);
	void setDefense(Coordinates pos, char c);
	void setAttack(Coordinates, char c);
	
	bool isFree(Coordinates pos);	
	bool verifyIsFree(vector<Coordinates> coords);
	void insert(NavalUnit unit);
	void clear();
	void deleteSonar();
};

std::ostream& operator<< (std::ostream& os, Grid grid);

#endif	//GRID_H

