#include <cstdlib>
#include <ctime>

#include "GamePlay.h"
#include "ComputerPlayer.h"
#include "HumanPlayer.h"

using namespace std;

void GamePlay::playGame()
{
	switch(mode)
	{
		case PC:
		{
			HumanPlayer p1("Player1");
            cout <<  p1.getName() <<"'s grid:"<< endl<< p1.getGrid(); 
			ComputerPlayer p2("Player2");
            cout <<  p2.getName() <<"'s grid:"<< endl<< p2.getGrid(); 
            p1.setOpponent(&p2);
            p2.setOpponent(&p1);
            Action a;
            
                    
            try{
                    int first = start();
                    Player* active;
                    if(first == 1)
                    {
                        active = &p1;
                    }
                    else
                    {
                        active = &p2;
                    }
                    
                    int n = 0;
                    while(n < 6)
                    {
                        a = active->nextAction();
                        
                         cout<< "stampo x source"<<a.getSource().getX() << endl;
                        cout << "stampo y source"<<a.getSource().getY() <<endl;
                        
                         cout<< "stampo x target"<<a.getTarget().getX() << endl;
                        cout << "stampo y taget"<<a.getTarget().getY() <<endl;
                        active->play(a);
                        
                        if(active->hasLost())
                        {
                            cout << active->getName() << " has lost :(";
                            break;
                        }
                        //active = (active == &p1 ? &p2 : &p1);
                        if(active == &p1)
                        {
                            active = &p2;
                        }
                        else
                        {
                            active = &p1;
                        }
                        cout<<"Griglia del giocatore umano " << p1.getGrid();
                        
                        n++;
                    }
                    cout << p1.checkWin()->getName() << " has won :)";
                            break;
            }
            catch(invalid_argument e){cout <<"chissa che finiamo!"<< e.what() <<endl;}
        }
                
		case CC:
		{
			ComputerPlayer p1("Player1");
            cout <<  p1.getName() <<"'s grid:"<< endl<< p1.getGrid(); 
			ComputerPlayer p2("Player2");
            cout <<  p2.getName() <<"'s grid:"<< endl<< p2.getGrid(); 
            p1.setOpponent(&p2);
            p2.setOpponent(&p1);
            Action a;
            
            
			
            
                try{
                        int first = start();
                    Player* active = (first == 1 ? &p1 : &p2);
                    
                    
                    
                    int n = 0;
                    while(n < 4)
                    {       
                        cout<< "Turno del " <<active->getName() <<endl;

     
                        a = active->nextAction();
                                
                                cout<< "stampo x source"<<a.getSource().getX() << endl;
                                cout << "stampo y source"<<a.getSource().getY() <<endl;
                                
                                 cout<< "stampo x target"<<a.getTarget().getX() << endl;
                                cout << "stampo y taget"<<a.getTarget().getY() <<endl;

                                active->play(a);

                            cout << active->getName() << active->getGrid()  <<endl;

                            if(active->hasLost())
                            {
                                cout << active->getName() << " has lost :(";
                                break;
                            }

                            active = (active == &p1 ? &p2 : &p1);
                            cout <<" ora e attivo: "<< active->getName() <<endl;

                            if(a.getType() != CLEAR){
                                n++;
                            }
                    }
                    cout << p1.checkWin()->getName() << " has won :)";
                    break;
                }
                catch(invalid_argument e){cout <<"che merda" << e.what();}


			
		}
		default:
			break;
	}
	
	
}

int GamePlay::start()
{
    srand(time(NULL));
    int n = rand()%2+1; //numero casuale da 1 a 2
    return n;
}
/*
void GamePlay::activePlayer(Player p1, Player p2)
{
	int first = start();
	Player* active = (first == 1 ? &p1 : &p2);
	
	int n = 0;
	while(n < 6)
	{
		Action a = active->nextAction();
		active->play(a);
		if(active->hasLost())
		{
			cout << active->getName() << " has lost :(";
			break;
		}
		active = (active == &p1 ? &p2 : &p1);
		n++;
	}
	cout << p1.checkWin()->getName() << " has won :)";
}*/

