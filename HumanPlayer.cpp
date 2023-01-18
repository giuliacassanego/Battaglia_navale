/**
 * @author Angelica Zonta 2032570
 * @brief Definition of functions of HumanPlayer.h
 */
#include "HumanPlayer.h"

Action HumanPlayer::nextAction()
{
	Action a;
    string command1;
    string command2;
    Coordinates source;
    Coordinates target;
	
    bool correct = false;
    //reading and parsing the input's command
    while(correct != true)
    {
		cout << "Insert XYOrigin XYTarget" << endl;
		cin >> command1;
		cin >> command2;
		
		if (command1 == "AA" && command2 == "AA")
		{
			cout << "Command AA AA" << endl;
			a = Action(CLEAR);
			actionCoords.push_back("AA AA");
			correct = true;
		}
		else if(command1 == "XX" && command2 == "XX")
		{
			cout << "Command XX XX" << endl;
			a = Action(SHOW);
			actionCoords.push_back("XX XX");
			correct = true;
		}
		else
		{
			try {
				source = Coordinates(command1);
				target = Coordinates(command2);
                
                GridCell& cell1 = getGrid().getDefense(source);
                GridCell& cell2 = getGrid().getDefense(target);
				
                char symbol = cell1.getSymbol();

				if(!cell1.isVoid())
				{
                    if(symbol == 'C' || symbol == 'c')
                    {
                        a = Action(source, target);
                        actionCoords.push_back(Coordinates::createString(a.getSource(), a.getTarget()));
                        correct = true;
                    }
                    else if(cell2.isVoid())
                    {
                        a = Action(source, target);
                        actionCoords.push_back(Coordinates::createString(a.getSource(), a.getTarget()));
                        correct = true;
                    }
                    else{
                        cout << "XYTarget already occupied" << endl;
                    }
				}
                else{
                    cout << "XYOrigin not valid" << endl;
                }
			}
			catch(invalid_argument e){cout << e.what() << endl;}
		}
    }
    return a;
}

void HumanPlayer::prepareGrid()
{
    string command1;
    string command2;
    Coordinates bow;
    Coordinates stern;
    
    bool correct = false;
    while(correct != true)
    {
        try{
            cout<< "Insert coordinates of battleship 1" << endl;
            cin>> command1;
            cin >> command2;
            bow = Coordinates(command1);
            stern =Coordinates(command2);
            NavalUnit* battleship1 = addUnit(BATTLESHIP, "c1");
            setUnitPosition(battleship1, bow, stern);
            correct = true;
        }
        catch(invalid_argument e){cout << e.what() << endl;}
    }
    
    correct = false;
    while(correct != true)
    {
        try{
            cout<< "Insert coordinates of battleship 2" << endl;
            cin>> command1;
            cin >> command2;
            bow = Coordinates(command1);
            stern =Coordinates(command2);
            NavalUnit* battleship2 = addUnit(BATTLESHIP, "c2");
            setUnitPosition(battleship2, bow, stern);
            correct =true;
        }
        catch(invalid_argument e){cout << e.what() << endl;}
    }
    
    correct = false;
    while(correct != true)
    {
        try{
            cout<< "Insert coordinates of battleship 3" << endl;
            cin>> command1;
            cin >> command2;
            bow = Coordinates(command1);
            stern =Coordinates(command2);
            NavalUnit* battleship3 = addUnit(BATTLESHIP, "c3");
            setUnitPosition(battleship3, bow, stern);
            correct = true;
        }
        catch(invalid_argument e){cout << e.what() << endl;}
    }
    
    correct = false;
    while(correct != true)
    {
        try{
            cout<< "Insert coordinates of support vessel 1" << endl;
            cin>> command1;
            cin >> command2;
            bow = Coordinates(command1);
            stern =Coordinates(command2);
            NavalUnit* supportivevessel1 = addUnit(SUPPORTVESSEL, "s1");
            setUnitPosition(supportivevessel1, bow, stern);
            correct = true;
        }
        catch(invalid_argument e){cout << e.what() << endl;}
    }
    
    correct = false;
    while(correct != true)
    {
        try{
            cout<< "Insert coordinates of support vessel 2" << endl;
            cin>> command1;
            cin >> command2;
            bow = Coordinates(command1);
            stern =Coordinates(command2);
            NavalUnit* supportivevessel2 = addUnit(SUPPORTVESSEL, "s2");
            setUnitPosition(supportivevessel2, bow, stern);
            correct = true;
        }
        catch(invalid_argument e){cout << e.what() << endl;}
    }
    
    correct = false;
    while(correct != true)
    {
        try{
            cout<< "Insert coordinates of support vessel 3" << endl;
            cin>> command1;
            cin >> command2;
            bow = Coordinates(command1);
            stern =Coordinates(command2);
            NavalUnit* supportivevessel3 = addUnit(SUPPORTVESSEL, "s3");
            setUnitPosition(supportivevessel3, bow, stern);
            correct = true;
        }
        catch(invalid_argument e){cout << e.what() << endl;}
    }
    
    correct = false;
    while(correct != true)
    {
        try{
            cout<< "Insert coordinates of submarine 1" << endl;
            cin>> command1;
            cin >> command2;
            bow = Coordinates(command1);
            stern =Coordinates(command2);
            NavalUnit* submarine1 = addUnit(SUBMARINE, "e1");
            setUnitPosition(submarine1, bow, stern);
            correct = true;
        }
        catch(invalid_argument e){cout << e.what() << endl;}
    }
    
    correct = false;
    while(correct != true)
    {
        try{
            cout<< "Insert coordinates of submarine 2" << endl;
            cin>> command1;
            cin >> command2;
            bow = Coordinates(command1);
            stern =Coordinates(command2);
            NavalUnit* submarine2 = addUnit(SUBMARINE, "e2");
            setUnitPosition(submarine2, bow, stern);
            correct = true;
        }
        catch(invalid_argument e){cout << e.what()<< endl;}
    }
}