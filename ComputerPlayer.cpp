/**
 * @brief Definitions of functions of ComputerPlayer
 */

#include "ComputerPlayer.h"
#include "BattleShip.h"

#include <cstdlib>
#include <ctime>
#include <string>

Action ComputerPlayer::nextAction()
{
    Action a;
    
/*    srand(time(NULL));
    int n = rand()%2+1;

    if(n==1) //eseguo comando AA AA
    {
        cout << "command AA AA" << endl;
        a = Action(CLEAR);
    }
    else{ */
		int num = rand()%(units.size()-1);
		Coordinates source = units[num]->getCenter();
		GridCell& cell1 = getGrid().getDefense(source);
		char symbol = cell1.getSymbol();
		
		bool correct = false;
		while(correct != true)
        {
			try{ 
				Coordinates target = randomChosePos();
				GridCell& cell2 = getGrid().getDefense(target);
		
				if(symbol == 'C' || symbol == 'c')
				{
					a = Action(source, target);
					correct = true;
				}
				else if(cell2.isVoid())
				{
					a = Action(source, target);
					correct = true;
				}
			}
			catch(invalid_argument e)
			{
				cout  << e.what() << endl;
			}
        }
//   }
	actionCoords.push_back(Coordinates::createString(a.getSource(), a.getTarget()));
	cout << "size actionCoords " << actionCoords.size() << endl;
    return a;
}

Coordinates ComputerPlayer::randomChosePos() //metodo per target
{
    srand(time(NULL));
    int num = rand()%12+1; 

    bool correctLett = false; 
    char pos;
    while(correctLett != true)
    {
        pos =65+rand()%(78-64); //scelgo una lettera casulamente con codice ascii: da A a N;
        if(pos != 74 && pos != 75)//controllo che non escano le lettere K e J
        {
            correctLett=true;
        }
    } 
    string s = pos + to_string(num);
    Coordinates coor(s);
    return coor;
}


int ComputerPlayer::chooseDirection()
{
    srand(time(NULL));
    int n = rand()%2+1; 
    return n;
}

Coordinates ComputerPlayer::findStern(NavalUnit* n, Coordinates bow) //metodo per trovare la prua
{
    
    int x = bow.getX();
    int y= bow.getY();
    int dir = chooseDirection();
    int size = n->getSize();

    x = (dir==1 ? x+= (size-1) : x); 
    y= (dir==1 ? y : y+= (size-1));

    Coordinates stern(x, y);
    return stern;
}

void ComputerPlayer::prepareGrid()
{
    cout << getName() << " is setting his naval units..." <<endl;
    
	NavalUnit* battleship1 = addUnit(BATTLESHIP, "c1");
    bool correct = false;
    while(correct != true){
         try{
            Coordinates bow = randomChosePos();
            setUnitPosition(battleship1, bow, findStern(battleship1, bow));
            correct = true;
        }
        catch(invalid_argument e){}
    }
    
	NavalUnit* battleship2 = addUnit(BATTLESHIP, "c2");
    correct = false;
    while(correct != true){
         try{
            Coordinates bow = randomChosePos();
            setUnitPosition(battleship2, bow, findStern(battleship2, bow));
            correct = true;
        }
        catch(invalid_argument e){}
    }
	
	NavalUnit* battleship3 = addUnit(BATTLESHIP, "c3");
    correct = false;
    while(correct != true){
         try{
            Coordinates bow = randomChosePos();
            setUnitPosition(battleship3, bow, findStern(battleship3, bow)); 
            correct = true;
        }
        catch(invalid_argument e){}
    }
    
	NavalUnit* supportvessel1 = addUnit(SUPPORTVESSEL, "s1");
    correct = false;
    while(correct != true){
         try{
            Coordinates bow = randomChosePos();
            setUnitPosition(supportvessel1, bow, findStern(supportvessel1, bow)); 
            correct = true;
        }
        catch(invalid_argument e){}
    }
    
	NavalUnit* supportvessel2 = addUnit(SUPPORTVESSEL, "s2");
    correct = false;
    while(correct != true){
         try{
            Coordinates bow = randomChosePos();
            setUnitPosition(supportvessel2, bow, findStern(supportvessel2, bow));
            correct = true;
        }
        catch(invalid_argument e){}
    }
    
	NavalUnit* supportvessel3 = addUnit(SUPPORTVESSEL, "s3");
    correct = false;
    while(correct != true){
         try{
            Coordinates bow = randomChosePos();
            setUnitPosition(supportvessel3, bow, findStern(supportvessel3, bow));
            correct = true;
        }
        catch(invalid_argument e){}
    }
    
	NavalUnit* submarine1 = addUnit(SUBMARINE, "e1");
    correct = false;
    while(correct != true){
         try{
            Coordinates bow = randomChosePos();
            setUnitPosition(submarine1, bow, findStern(submarine1, bow));
            correct = true;
        }
        catch(invalid_argument e){}
    }
    
	NavalUnit* submarine2 = addUnit(SUBMARINE, "e2");
    correct = false;
    while(correct != true){
         try{
            Coordinates bow = randomChosePos();
            setUnitPosition(submarine2, bow, findStern(submarine2, bow));
            correct = true;
        }
        catch(invalid_argument e){}
    }
}

