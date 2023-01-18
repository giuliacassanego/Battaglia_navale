/**
 * @author Angelica Zonta 2032570
 * @class GridCell
 * @file GridCell.h
 * @brief This class stores and updates the status of the grid cells.
 */
#ifndef GRIDCELL_H
#define GRIDCELL_H

#include "NavalUnit.h"

class GridCell
{
private:
	bool isHit;
	bool isMiss;
	bool isSonar;
	NavalUnit *p;
	
public:
	GridCell() {clear();}
    
	void setHit() {isHit = true; isMiss = false; isSonar = false;}
	void setMiss() {isMiss = true; isHit = false;}
	void setSonar() {isSonar = true;}
	void resetSonar() {isSonar = false;}
	void setUnit(NavalUnit *p, bool hit) {this->p = p; isHit = hit;}
	
	void clear();	//reset all the values
	char getSymbol();
	bool isVoid() {return p == nullptr;}
	
	NavalUnit* getUnit() {return p;}
};

#endif
