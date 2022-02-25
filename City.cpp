//Programmer: Aaron Milner
//Programmer: Joshua Andreyev
//Assignment: hw9
//Date: 12/7/2021
//File: City.cpp
//Purpose: To encompass everything we have learned throughout the year

#include "City.h"
#include "Jewel.h"
const static int MAXCITYSIZE=10; //constant used for the city of the size

//***********************************Function Definitions************************************
City::City() {
  m_cityArray=new char*[MAXCITYSIZE];
  for (int i=0; i<MAXCITYSIZE; i++)
  {
    m_cityArray[i]=new char[MAXCITYSIZE];
  }
  for (int i=0; i<MAXCITYSIZE; i++)
  {
    for(int j=0; j<MAXCITYSIZE; j++)
    {
      m_cityArray[i][j]=' ';
    }
  }
}

City::~City() {

  for (int i = 0; i<MAXCITYSIZE; i++) {
    delete[] m_cityArray[MAXCITYSIZE]; //delete what is inside the city
  }
  delete[] m_cityArray; //delete the city
}

ostream & operator <<(ostream & os, const City &city){
  for(int i=0; i<MAXCITYSIZE; i++) {

    cout<<i<<" | "; //print the side of the board

    for (int j=0; j<MAXCITYSIZE; j++) {

      cout<<"  "<<city.m_cityArray[i][j]<<"    "; //print the spaces

    }
    cout<<"|";
    cout<<"\n";
  }
  cout << " ";
  for (int i=0; i<MAXCITYSIZE; i++)
  {
    cout<<"     "<<i<<" ";
  }
  cout<<"\n" << "\n" << "\n" << "\n"; //space in between each board
  return os;
}

void City::placeJewels() {
  int row;
  int col;
  row = rand()%10;
  col = rand()%10;
  for (int i=0; i<MAXJEWELS; i++)
  {
    do{
      m_cityArray[col][row]='J'; //set the random board space to a J representing a jewel
      row = rand()%10;
      col = rand()%10;
    }while(m_cityArray[col][row]== 'J' && m_cityArray[col][row] == 'R');

  }
}
