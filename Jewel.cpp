//Programmer: Aaron Milner
//Programmer: Joshua Andreyev
//Assignment: hw9
//Date: 12/7/2021
//File: Jewel.cpp
// Purpose: To encompass everything we have learned throughout the year

#include "Jewel.h"
#include <cstdlib>
#include <iostream>
using namespace std;
//*********************************Function Definitions**********************************
Jewel::Jewel(const Coordinate &coord){
  m_jewelCoord.x = coord.x;
  m_jewelCoord.y = coord.y;
  calcJewel();
}

void Jewel::calcJewel(){
  m_jewelValue = m_jewelCoord.x + m_jewelCoord.y;
}
