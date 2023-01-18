/**
 * @author Giulia Cassanego 2032560
 * @class Action
 * @file Action.h
 * @brief This class constructs an Action object used by players in GamePlay
 */

#ifndef ACTION_H
#define ACTION_H

#include "Coordinates.h"

/**
 * @enum that represents the three possible types of actions
 */
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