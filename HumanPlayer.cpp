#include "HumanPlayer.h"

Action HumanPlayer::nextAction()
{
    string command1;
    string command2;
    
    Coordinates source;
    Coordinates target;
    bool correct = false;
    
    while(correct != true)
    {
        cout<<"Inserire coordinate dell'unita da far giocare e dove attaccare";
        cin >> command1;
        cin >> command2;

        source = Coordinates(command1);
        target = Coordinates(command2);
        
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
            cout<< "Quali sono le coordinate per la corazzata 1?" << endl;
            cin>> command1;
            cin >> command2;
            bow = Coordinates(command1);
            stern =Coordinates(command2);
            NavalUnit* battleship1 = addUnit(BATTLESHIP, "c1");
            setUnitPosition(battleship1, bow, stern);
            correct = true;
        }
        catch(invalid_argument e){cout<< e.what()<<endl;}
    }
    
    correct = false;
    while(correct != true)
    {
        try{
            cout<< "Quali sono le coordinate per la corazzata 2?" << endl;
            cin>> command1;
            cin >> command2;
            bow = Coordinates(command1);
            stern =Coordinates(command2);
            NavalUnit* battleship2 = addUnit(BATTLESHIP, "c2");
            setUnitPosition(battleship2, bow, stern);
            correct =true;
        }
        catch(invalid_argument e){cout<< e.what()<<endl;}
    }
    
    correct = false;
    while(correct != true)
    {
        try{
            cout<< "Quali sono le coordinate per la corazzata 3?" << endl;
            cin>> command1;
            cin >> command2;
            bow = Coordinates(command1);
            stern =Coordinates(command2);
            NavalUnit* battleship3 = addUnit(BATTLESHIP, "c3");
            setUnitPosition(battleship3, bow, stern);
            correct = true;
        }
        catch(invalid_argument e){cout<< e.what()<<endl;}
    }
    
    correct = false;
    while(correct != true)
    {
        try{
            cout<< "Quali sono le coordinate per la nave di supporto 1?" << endl;
            cin>> command1;
            cin >> command2;
            bow = Coordinates(command1);
            stern =Coordinates(command2);
            NavalUnit* supportivevessel1 = addUnit(SUPPORTVESSEL, "s1");
            setUnitPosition(supportivevessel1, bow, stern);
            correct = true;
        }
        catch(invalid_argument e){cout<< e.what()<<endl;}
    }
    
    correct = false;
    while(correct != true)
    {
        try{
            cout<< "Quali sono le coordinate per la nave di supporto 2?" << endl;
            cin>> command1;
            cin >> command2;
            bow = Coordinates(command1);
            stern =Coordinates(command2);
            NavalUnit* supportivevessel2 = addUnit(SUPPORTVESSEL, "s2");
            setUnitPosition(supportivevessel2, bow, stern);
            correct = true;
        }
        catch(invalid_argument e){cout<< e.what()<<endl;}
    }
    
    correct = false;
    while(correct != true)
    {
        try{
            cout<< "Quali sono le coordinate per la nave di supporto 3?" << endl;
            cin>> command1;
            cin >> command2;
            bow = Coordinates(command1);
            stern =Coordinates(command2);
            NavalUnit* supportivevessel3 = addUnit(SUPPORTVESSEL, "s3");
            setUnitPosition(supportivevessel3, bow, stern);
            correct = true;
        }
        catch(invalid_argument e){cout<< e.what()<<endl;}
    }
    
    correct = false;
    while(correct != true)
    {
        try{
            cout<< "Quali sono le coordinate per il sottomarino 1?" << endl;
            cin>> command1;
            cin >> command2;
            bow = Coordinates(command1);
            stern =Coordinates(command2);
            NavalUnit* submarine1 = addUnit(SUBMARINE, "e1");
            setUnitPosition(submarine1, bow, stern);
            correct = true;
        }
        catch(invalid_argument e){cout<< e.what()<<endl;}
    }
    
    correct = false;
    while(correct != true)
    {
        try{
            cout<< "Quali sono le coordinate per il sottomarino 2?" << endl;
            cin>> command1;
            cin >> command2;
            bow = Coordinates(command1);
            stern =Coordinates(command2);
            NavalUnit* submarine2 = addUnit(SUBMARINE, "e2");
            setUnitPosition(submarine2, bow, stern);
            correct = true;
        }
        catch(invalid_argument e){cout<< e.what()<<endl;}
    }

}
