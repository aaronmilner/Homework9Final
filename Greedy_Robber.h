//Programmer: Aaron Milner
//Programmer: Joshua Andreyev
//Assignment: hw9
//Date: 12/7/2021
//File: Greedy_Robber.h
// Purpose: To encompass everything we have learned throughout the year

#ifndef HOMEWORK9FINAL_GREEDY_ROBBER_H
#define HOMEWORK9FINAL_GREEDY_ROBBER_H
#include "Robber.h"

using namespace std;

class Greedy_Robber:public Robber{
public:
  //Description: Default constructor
  //Pre: None
  //Post: Created to reduce errors
  Greedy_Robber() {};

  //Description: Parameterized constructor
  //Pre: An int
  //Post: Sets their robber ID to the int and initializes their bag
  Greedy_Robber(const int ID);

  //Description: Destructor
  //Pre: None
  //Post: Deletes their bag
  ~Greedy_Robber();

  //Description: Allows the greedy robber to move
  //Pre: The city
  //Post: Has different outcomes based on where they land on the map
  void move(City &city);

private:



};


#endif //HOMEWORK9FINAL_GREEDY_ROBBER_H
