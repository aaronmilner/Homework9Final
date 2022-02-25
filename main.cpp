//Programmer: Aaron Milner
//Programmer: Joshua Andreyev
//Assignment: hw9
//Date: 12/7/2021
//File: main.cpp
// Purpose: To encompass everything we have learned throughout the year

#include <iostream>
#include "Police.h"
#include "cstdlib"
#include "time.h"
using namespace std;

int main() {
  //srand(85);
  srand(time(NULL));

  City c1;
  c1.placeJewels();
  cout << c1;

  const int WINNING_AMOUNT = 2022; //constant to determine if robbers win the game
  int robbers_amount;
  int numTurns=0;

  Ordinary_Robber Vladimir(1);
  Ordinary_Robber Putin(2);
  Greedy_Robber Henry(3);
  Greedy_Robber Jason(4);
  Police San(1);

  Vladimir.addRobber(c1);
  Putin.addRobber(c1);
  Henry.addRobber(c1); //add police and robbers to the map
  Jason.addRobber(c1);
  San.AddPolice(c1);

  do{
    numTurns++;
    cout<<"Turn # "<<numTurns<<endl;
    Vladimir.move(c1);
    Putin.move(c1);
    Henry.move(c1);
    Jason.move(c1);
    San.Move(c1,Vladimir,Putin,Henry,Jason);
    cout<<c1;
    robbers_amount = Putin.getTotal(); //determine the robbers total jewel amount
  }while(numTurns<30 &&
  San.robbersActive(Vladimir, Putin, Henry, Jason) && robbers_amount < WINNING_AMOUNT);

  cout<<"\nSummary of the chase :"<<endl;
  if(!San.robbersActive(Vladimir, Putin, Henry, Jason))
  {
    cout<<"The police has arrested all of the robbers!"<<endl;
  }
  else if(numTurns == 30)
  {
    cout<<"The robbers run free! " << " The max number of turns (" << numTurns << ") has been reached" << endl;
  }
  else if(robbers_amount >= WINNING_AMOUNT){
    cout << "The robbers have gathered enough money to pay off the police and run away!" << endl;
  }
  San.Summary();
  Vladimir.summary();
  Putin.summary();
  Henry.summary();
  Jason.summary();

  return 0;
}
