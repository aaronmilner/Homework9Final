//Programmer: Aaron Milner
//Programmer: Joshua Andreyev
//Assignment: hw9
//Date: 12/7/2021
//File: Ordinary_Robber.h
// Purpose: To encompass everything we have learned throughout the year

#ifndef HOMEWORK9FINAL_ORDINARY_ROBBER_H
#define HOMEWORK9FINAL_ORDINARY_ROBBER_H
#include "Robber.h"
#include <iostream>

using namespace std;

class Ordinary_Robber: public Robber {
public:
  Ordinary_Robber() {};//Default Constructor
  Ordinary_Robber(const int ID);//Parameterized Constructor
  ~Ordinary_Robber();//Destructor

  //Description: Allows the greedy robber to move
  //Pre: The city
  //Post: Has different outcomes based on where they land on the map
  void move(City &city);

private:



};

#endif //HOMEWORK9FINAL_ORDINARY_ROBBER_H
