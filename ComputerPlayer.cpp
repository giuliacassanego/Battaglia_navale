#include "ComputerPlayer.h"
#include "BattleShip.h"

#include <cstdlib>
#include <ctime>
#include <string>

Action ComputerPlayer::nextAction()
{
    Action a;
    
    srand(time(NULL));
    int n = rand()%2+1;

    //if(n==1) //eseguo comando AA AA
    /*{
        cout << "comando AA";
        
        a = Action(CLEAR);
    }
    else{
       // int unitMakeAction = rand()%8+1;  //uso il this?? come lo vogliamo richiamare?
        
        
        //cout << unitMakeAction<< endl;
        
        //cout <<"centers size" << centers.size() <<endl;
        //cout << centers[unitMakeAction]->getSymbol() <<endl;
        
        
        //Coordinates source(centers[unitMakeAction]->getCenter());
        */
        bool correct = false;
		while(correct != true)
        {
            try{
                int num = rand()%(centers.size()-1);
                cout << "center size " <<centers.size()<<endl;
                cout <<"cooridnata random nel vector " << num<<endl;
                Coordinates source = centers[num];
                
                
                cout << "coordinata x" << source.getX()<<endl;
                cout << "coordinata y" << source.getY()<<endl;
                
                
                a = Action(source, randomChosePos());
                
                correct = true;
            }
            catch(invalid_argument e){ cout << "do bae";}
        }
        
   // }
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
    cout << getName() << " is setting his Navalcenters" <<endl;
    
    bool correct = false;
    while(correct != true){
         try{
            NavalUnit* battleship1 = addUnit(BATTLESHIP, "c1");
            Coordinates bow = randomChosePos();
            setUnitPosition(battleship1, bow, findStern(battleship1, bow));
            centers.push_back(battleship1->getCenter()); 
            correct = true;
        }
        catch(invalid_argument e){}
    }
    
    correct = false;
    while(correct != true){
         try{
            NavalUnit* battleship2 = addUnit(BATTLESHIP, "c2");
            Coordinates bow = randomChosePos();
            setUnitPosition(battleship2, bow, findStern(battleship2, bow));
           centers.push_back(battleship2->getCenter()); 
            correct = true;
        }
        catch(invalid_argument e){}
    }
    
    correct = false;
    while(correct != true){
         try{
            NavalUnit* battleship3 = addUnit(BATTLESHIP, "c3");
            Coordinates bow = randomChosePos();
            setUnitPosition(battleship3, bow, findStern(battleship3, bow));
     centers.push_back(battleship3->getCenter()); 
            correct = true;
        }
        catch(invalid_argument e){}
    }
    
    correct = false;
    while(correct != true){
         try{
            NavalUnit* supportvessel1 = addUnit(SUPPORTVESSEL, "s1");
            Coordinates bow = randomChosePos();
            setUnitPosition(supportvessel1, bow, findStern(supportvessel1, bow));
           centers.push_back(supportvessel1->getCenter()); 
            correct = true;
        }
        catch(invalid_argument e){}
    }
    
    correct = false;
    while(correct != true){
         try{
            NavalUnit* supportvessel2 = addUnit(SUPPORTVESSEL, "s2");
            Coordinates bow = randomChosePos();
            setUnitPosition(supportvessel2, bow, findStern(supportvessel2, bow));
         centers.push_back(supportvessel2->getCenter());
            correct = true;
        }
        catch(invalid_argument e){}
    }
    
    correct = false;
    while(correct != true){
         try{
            NavalUnit* supportvessel3 = addUnit(SUPPORTVESSEL, "s3");
            Coordinates bow = randomChosePos();
            setUnitPosition(supportvessel3, bow, findStern(supportvessel3, bow));
          centers.push_back(supportvessel3->getCenter());
            correct = true;
        }
        catch(invalid_argument e){}
    }
    
    correct = false;
    while(correct != true){
         try{
            NavalUnit* submarine1 = addUnit(SUBMARINE, "e1");
            Coordinates bow = randomChosePos();
            setUnitPosition(submarine1, bow, findStern(submarine1, bow));
            centers.push_back(submarine1->getCenter());
            correct = true;
        }
        catch(invalid_argument e){}
    }
    
    correct = false;
    while(correct != true){
         try{
            NavalUnit* submarine2 = addUnit(SUBMARINE, "e2");
            Coordinates bow = randomChosePos();
            setUnitPosition(submarine2, bow, findStern(submarine2, bow));
            centers.push_back(submarine2->getCenter());
            correct = true;
        }
        catch(invalid_argument e){}
    }
}

