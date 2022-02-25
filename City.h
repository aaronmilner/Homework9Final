//Programmer: Aaron Milner
//Programmer: Joshua Andreyev
//Assignment: hw9
//Date: 12/7/2021
//File: City.h
// Purpose: To encompass everything we have learned throughout the year
#include <iostream>
using namespace std;
#ifndef HOMEWORK9FINAL_CITY_H
#define HOMEWORK9FINAL_CITY_H

//***************************************Class Definitions/Function Prototypes******************************
class City {
public:
  City();//Default Constructor
  ~City();//Destructor

  //Description: Randomly places Jewels on the city map
  //Pre:None
  //Post:City has Jewels scattered throughout map
  void placeJewels();

  friend class Robber;
  friend class Police;
  friend class Ordinary_Robber;
  friend class Greedy_Robber;
  //Description: Overloading the << operator to output the city map
  //             with the robbers, police and jewels
  //Pre: Requires a valid City class to be passed in
  //Post: Outputs a map of the city
  friend ostream & operator <<(ostream & os, const City &city);

private:
  char **m_cityArray;
};


#endif //HOMEWORK9FINAL_CITY_H
