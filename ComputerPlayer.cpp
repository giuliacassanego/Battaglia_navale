#include "ComputerPlayer.h"
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