#include <iostream>

#include "SupportVessel.h"
#include "Player.h"

using namespace std;


void SupportVessel::action(Coordinates target)
{
	cout << "SupportVessel action" << endl;
	move(target);
	
}