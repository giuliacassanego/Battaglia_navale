#ifndef GRIDCELL_H
#define GRIDCELL_H

#include "NavalUnit.h"

//classe memorizza e aggiorna stato delle celle della griglia
class GridCell
{
private:
	bool isHit;
	bool isMiss;
	bool isSonar;
	NavalUnit *p;
	
public:
	GridCell() {clear();}
	void setHit() {isHit = true; isMiss = false;}
	void setMiss() {isMiss = true; isHit = false;}
	void setSonar() {isSonar = true;}
	void resetSonar() {isSonar = false;}
	void setUnit(NavalUnit *p, bool hit) {this->p = p; isHit = hit;}
	
	void clear();	//reset tutti valori
	char getSymbol();
	bool isVoid() {return p == nullptr;}
	
	NavalUnit* getUnit() {return p;}
};

#endif