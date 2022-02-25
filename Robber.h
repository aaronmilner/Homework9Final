//Programmer: Aaron Milner
//Programmer: Joshua Andreyev
//Assignment: hw9
//Date: 12/7/2021
//File: Robber.h
// Purpose: To encompass everything we have learned throughout the year

#ifndef HOMEWORK9FINAL_ROBBER_H
#define HOMEWORK9FINAL_ROBBER_H
#include "City.h"
#include "Jewel.h"

class Robber {
public:
  Robber(){};//Default Constructor
  virtual ~Robber();

  //Description: Adds a robber to the city map
  //Pre: The city
  //Post: Returns the new city with the robber added to the map with an 'R'
  void addRobber(City &city);

  //Description: Puts the jewel in the bag
  //Pre: A jewel pointer
  //Post: Updates the bag member variable with the new jewel inside
  void pickUpJewel(const Jewel* newJewel);

  //Description: Prints out the ending info for the specfic robber
  //Pre: None
  //Post: Outputs some of the member variables to the user
  void summary();

  //Description: Gets the total amount of jewels collected by all robbers
  //Pre: None
  //Post: Returns an int
  int getTotal();

  friend class Police;

  static int m_totalJewelWorth; //jewel worth for all robbers combined
protected:
  int robberID;
  int slot = 0;
  Coordinate robberCoord;
  Jewel* Bag;
  int m_bagSize = 5;
  int m_jewelsPickedUp = 0;
  int m_jewelAmount = 0; //worth of jewels per individual
  bool m_stillActive = true;

private:

};


#endif //HOMEWORK9FINAL_ROBBER_H
