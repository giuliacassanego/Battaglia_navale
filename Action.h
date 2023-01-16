#ifndef ACTION_H
#define ACTION_H

#include "Coordinates.h"

enum ActionType
{
	UNIT_ACTION,
	SHOW,	//XX XX
	CLEAR	//AA AA
};

class Action
{
private:
	ActionType type;
	Coordinates source;
	Coordinates target;
	
	
public:
	Action() {}
	Action(ActionType type) : type(type) {}
	Action(Coordinates source, Coordinates target) : type(UNIT_ACTION), source(source), target(target) {}
	
	ActionType getType() {return type;}
	Coordinates getSource() {return source;}
	Coordinates getTarget() {return target;}
};

#endif