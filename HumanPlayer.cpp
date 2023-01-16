#include "HumanPlayer.h"

Action HumanPlayer::nextAction()
{
    string comand;
    
    Coordinates source;
    Coordinates target;
    bool correct = false;
    
    while(correct)
    {
        cout<<"Inserire coordinate dell'unita da far giocare e dove attaccare";
        cin >> comand;
        if(comand.substr(2, 3) == " ")
        {
            source = Coordinates(comand.substr(0,2));
            target = Coordinates(comand.substr(3));
        }
        else{
            source = Coordinates(comand.substr(0,3));
            target = Coordinates(comand.substr(4));
        }
        
        //contorllo se è void?
        GridCell& cell = getGrid().getDefense(source);
        if(!cell.isVoid())
        {
            correct =true;
        }
    }
    
    Action a(source, target);
    return a;
 
}