#include "ComputerPlayer.h"
#include "BattleShip.h"
#include <cstdlib>
#include <ctime>
#include <string>


Action ComputerPlayer::nextAction()
{
    Action a;
    srand(time(NULL));
    int n = rand()%3+1;
    
    if(n==1) //eseguo comando XX XX
    {
        a = Action(SHOW);
    }
    else if(n==2) //eseguo comando AA AA
    {
        a = Action(CLEAR);
    }
    else{
        int unitMakeAction = rand()%(units.size()) +1;  //uso il this?? come lo vogliamo richiamare?
        Coordinates source(units[unitMakeAction]->getCenter());
        Coordinates target(randomChosePos());
        a = Action(source, target);
    }
    return a;
}

string ComputerPlayer::randomChosePos() //metodo per target
{
    srand(time(NULL));
    int n = rand()%12+1; 
    
    bool correctLett = false; 
    int pos;
    while(correctLett != true)
    {
        pos =rand()%78+65; //scelgo una lettera casulamente con codice ascii: da A a N;
        if(pos != 74 && pos != 75)//controllo che non escano le lettere K e J
        {
            correctLett=true;
        }
    }
    string s = to_string(pos)+ to_string(n);
    return s;
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

    x = (dir==1 ? x+= size : x); 
    y= (dir==1 ? y : y+=size);
    
    Coordinates stern(x, y);
    return stern;
}


void ComputerPlayer::prepareGrid()
{
    NavalUnit* battleship1 = addUnit(BATTLESHIP, "c1");
    Coordinates bow = randomChosePos();
    setUnitPosition(battleship1, bow, findStern(battleship1, bow));
    
  /*
    cout<< "Quali sono le coordiante per la corazzata 2?" << endl;
    cin>> command1;
    cin >> command2;
    source = Coordinates(command1);
    bow =Coordinates(command2);
    NavalUnit* battleship2 = addUnit(BATTLESHIP, "c2");
    setUnitPosition(battleship1, source, bow);
     * */
    
    
    
    /*
    //inserisco le corazzate
    int corazzata=1;
    while(corazzata<=3)
    {
        try{
            
            Coordinates bow(randomChosePos());
            
            NavalUnit*  n = addUnit(BATTLESHIP, "b"+to_string(corazzata)); //aggiungo al vector
            
            Coordinates stern(findStern(n, bow));
            
            setUnitPosition( n+to_string(corazzata), bow, stern); //aggiungo alla griglia
            corazzata ++;
        }
        catch(invalid_argument exception()){}
    }
    /*
    //inserisoc le navi
    int nave =1;
    while(nave<=3)
    {
        try{
            Coordinates bow(randomChoseInitial());
            Coordinates stern(findStern(SUPPORTVESSEL, bow));
            supportVessel+to_string(nave) = this.addUnit(SUPPORTVESSEL, "s"+to_string(nave); //aggiungo al vector
            this->setUnitPosition(supportVessel+to_string(i), bow, stern); //aggiungo alla griglia
            nave++;
        }
        catch(invalid_argument exception()){}
    }
    //inserisoc i sottomarini
    int sottomarino =1;
    while(sottomarino <=2)
    {
        try{
            Coordinates bow(randomChoseInitial());
            submarine+to_string(i) = this.addUnit(SUBMARINE, "e"+to_string(sottomarino); //aggiungo al vector
            this->setUnitPosition(submarine+to_string(sottomarino), bow, bow); //aggiungo alla griglia
            sottomarino++;
        }
        catch(invalid_argument exception()){}
    }
     * */
}

