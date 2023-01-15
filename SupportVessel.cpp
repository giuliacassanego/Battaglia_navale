#include <iostream>

#include "SupportVessel.h"

using namespace std;


void SupportVessel::action(Coordinates target)
{
	cout << "SupportVessel action" << endl;
	move(target);
	
}