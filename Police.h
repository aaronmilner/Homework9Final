//Programmer: Aaron Milner
//Programmer: Joshua Andreyev
//Assignment: hw9
//Date: 12/7/2021
//File: Police.h
// Purpose: To encompass everything we have learned throughout the year

#ifndef HOMEWORK9FINAL_POLICE_H
#define HOMEWORK9FINAL_POLICE_H

#include "Ordinary_Robber.h"
#include "Greedy_Robber.h"
#include "Robber.h"
//*************************************Class Definitions*****************************
class Police {
public:
  Police(){};
  Police(const int ID);
  //Description: Adds the police to the city map
  //Pre: Requires a valid City Class object to be passed in
  //Post:Adds the Police randomly on map
  void AddPolice(City &city);

  //Description:Checks what Robber the police has encountered
  // and then arrests that corresponding robber
  //Pre: Requires a valid City object and 4 Valid Robber Class objects to be passed in
  //Post: Arrests the Robber
  void checkIndetity(Robber &ORA, Robber &ORB, Robber &GRA, Robber &GRB);

  //Description: Function to arrest the Robber
  //Pre: Requires a valid Robber Class object to be passed in
  //Post:Arrests the robber
  void Arrest(Robber &robber);

  //Description: Allows the Police to randomly move around the city
  //Pre: Requires a valid City and 4 Robber Class Objects to be passed in
  //Post: Moves the Police around the city and arrests any robbers
  //      that he encounters
  void Move(City &city, Robber &ORA, Robber &ORB, Robber &GRA, Robber &GRB);

  //Description: Function to check if the Police has come across a Jewel
  //Pre:Requires a valid City class object to be passed in
  //Post: Removes the jewel off the map of the city
  void foundJewel(City &city);

  //Description:Function that checks if the next move is valid
  //Pre: Requires the Police's x and y coordinates
  //Post: Returns true or false
  bool checkNext(const int x, const int y);

  //Description: Outputs a summary for the Police
  //Pre:None
  //Post:Outputs the police ID,how many robbers the police has arrested,
  //     and the amount of confiscated jewels
  void Summary();

  //Description: Function to check if any of the robbers are still active
  //Pre: Requires 4 valid Robber Class objects to be passed in
  //Post: Returns true is any of the robbers are still active, else false
  bool robbersActive(const Robber &ORA, const Robber &ORB, const Robber &GRA, const Robber &GRB);

  friend class Robber;

private:
  int m_jewelsWorth;//Amount of Jewels Confiscated
  int policeID;
  int robbersDetained; //Number of Robbers Arrested
  Coordinate PoliceCoor;
};

#endif //HOMEWORK9FINAL_POLICE_H
