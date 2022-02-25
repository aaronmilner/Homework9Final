//Programmer: Aaron Milner
//Programmer: Joshua Andreyev
//Assignment: hw9
//Date: 12/7/2021
//File: Robber.cpp
// Purpose: To encompass everything we have learned throughout the year

#include "Robber.h"
#include <cstdlib>
#include <iostream>

int Robber::m_totalJewelWorth = 0; //static variable initialization

int Robber::getTotal() {
  return m_totalJewelWorth;
}

void Robber::pickUpJewel(const Jewel* newJewel){
  if(slot < m_bagSize){ //makes sure the bag is big enough to hold the jewel
    Bag[slot] = *newJewel;
    slot += 1;
  }else{
    m_bagSize *= 2; //increase the bag size by double
    int newSize = m_bagSize;

    Jewel *temp = new Jewel[newSize];

    for(int i = 0; i < newSize; i++){ //creation of a temp bag and copy contents over
      temp[i] = Bag[i];
    }

    delete []Bag; //delete old bag

    Bag = temp;
    Bag[slot] = *newJewel; //add jewel to new bigger bag
    slot += 1;
  }
}
Robber::~Robber() {
  delete [] Bag;
}
void Robber::addRobber(City &city) {
  int x=rand()%10;
  int y=rand()%10;
  city.m_cityArray[x][y]='R';
  robberCoord.x=x;
  robberCoord.y=y;
  cout << "Robber " << robberID << "'s initial position: " << robberCoord.x << "," << robberCoord.y << endl;
}

void Robber::summary(){
  cout << "Robber id: " << robberID << endl;
  cout << "\t Final number of jewels picked up: " << m_jewelsPickedUp << endl;
  cout << "\t Total jewel worth: " << m_jewelAmount << endl;
}