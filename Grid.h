//Cassanego Giulia 2032560

#ifndef GRID_H
#define GRID_H

#include <iostream>

#include "GridCell.h"

using namespace std;

class Grid
{
private:
	GridCell defense[12][12];
	GridCell attack[12][12];

public:
	Grid() {}
	GridCell& getDefense(Coordinates pos);
	GridCell& getAttack(Coordinates pos);
	
	bool isFree(Coordinates pos);	
	bool verifyIsFree(vector<Coordinates> coords);
	void insert(NavalUnit *unit);
	void clear(NavalUnit *unit);
	void deleteSonar();
};

std::ostream& operator<< (std::ostream& os, Grid grid);

#endif	//GRID_H

