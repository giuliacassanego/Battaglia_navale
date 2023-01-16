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
            source = Coordinates(getSource(comand));
            target = Coordinates(getBow(comand));
        }
        else{
            source = Coordinates(getSource(comand));
            target = Coordinates(getBow(comand));
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

string HumanPlayer::getSource(string s)
{
    string source;
    if(s.substr(2, 3) == " ")
    {
        source = s.substr(0,2);
    }
    else{
        source = s.substr(0,3);
    }
    return source;
}

string HumanPlayer::getBow(string s)
{
    string bow;
    if(s.substr(2, 3) == " ")
    {
        bow = s.substr(3);
    }
    else{
        bow = s.substr(4);
    }
    return bow;
}

void HumanPlayer::prepareGrid()
{
    
    try{
        string command1;
        string command2;
        Coordinates source;
        Coordinates bow;
        
        cout<< "Quali sono le coordinate per la corazzata 1?" << endl;
        cin>> command1;
        cin >> command2;
        source = Coordinates(command1);
        bow =Coordinates(command2);
        NavalUnit* battleship1 = addUnit(BATTLESHIP, "c1");
        setUnitPosition(battleship1, source, bow);
      
        cout<< "Quali sono le coordinate per la corazzata 2?" << endl;
        cin>> command1;
        cin >> command2;
        source = Coordinates(command1);
        bow =Coordinates(command2);
        NavalUnit* battleship2 = addUnit(BATTLESHIP, "c2");
        setUnitPosition(battleship1, source, bow);
        
        cout<< "Quali sono le coordinate per la corazzata 3?" << endl;
        cin>> command1;
        cin >> command2;
        source = Coordinates(command1);
        bow =Coordinates(command2);
        NavalUnit* battleship3 = addUnit(BATTLESHIP, "c3");
        setUnitPosition(battleship3, source, bow);
        
        cout<< "Quali sono le coordinate per la nave di supporto 1?" << endl;
        cin>> command1;
        cin >> command2;
        source = Coordinates(command1);
        bow =Coordinates(command2);
        NavalUnit* supportivevessel1 = addUnit(BATTLESHIP, "s1");
        setUnitPosition(supportivevessel1, source, bow);
        
        cout<< "Quali sono le coordinate per la nave di supporto 2?" << endl;
        cin>> command1;
        cin >> command2;
        source = Coordinates(command1);
        bow =Coordinates(command2);
        NavalUnit* supportivevessel2 = addUnit(BATTLESHIP, "s2");
        setUnitPosition(supportivevessel2, source, bow);
        
        cout<< "Quali sono le coordinate per la nave di supporto 3?" << endl;
        cin>> command1;
        cin >> command2;
        source = Coordinates(command1);
        bow =Coordinates(command2);
        NavalUnit* supportivevessel3 = addUnit(BATTLESHIP, "s3");
        setUnitPosition(supportivevessel3, source, bow);
        
        cout<< "Quali sono le coordinate per il sottomarino 1?" << endl;
        cin>> command1;
        cin >> command2;
        source = Coordinates(command1);
        bow =Coordinates(command2);
        NavalUnit* submarine1 = addUnit(BATTLESHIP, "e1");
        setUnitPosition(submarine1, source, bow);
     
        cout<< "Quali sono le coordinate per il sottomarino 2?" << endl;
        cin>> command1;
        cin >> command2;
        source = Coordinates(command1);
        bow =Coordinates(command2);
        NavalUnit* submarine2 = addUnit(BATTLESHIP, "e2");
        setUnitPosition(submarine2, source, bow);
 
    }
    catch(invalid_argument e){
        cout << e.what();
    }
    

    
}
