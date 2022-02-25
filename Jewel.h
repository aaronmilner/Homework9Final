//Programmer: Aaron Milner
//Programmer: Joshua Andreyev
//Assignment: hw9
//Date: 12/7/2021
//File: Jewel.h
// Purpose: To encompass everything we have learned throughout the year

#ifndef HOMEWORK9FINAL_JEWEL_H
#define HOMEWORK9FINAL_JEWEL_H

const static int MAXJEWELS=47;

//***************************Struct Definitions*******************************
struct Coordinate{
  int x;
  int y;
};

//****************************Class Definitions*******************************
class Jewel {
public:
  Jewel(){};//Default Constructor
  Jewel(const Coordinate &coord);//Parameterized Constructor

  //Description: Calculates the value of the Jewel
  //Pre:None
  //Post:Adds the coordinates of the Jewel and sets the Jewel value
  void calcJewel();
  friend class City;
  friend class Ordinary_Robber;
  friend class Robber;
  friend class Greedy_Robber;

private:
  int m_jewelValue;
  Coordinate m_jewelCoord;


};

#endif //HOMEWORK9FINAL_JEWEL_H
