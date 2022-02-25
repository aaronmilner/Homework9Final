//Programmer: Aaron Milner
//Programmer: Joshua Andreyev
//Assignment: hw9
//Date: 12/7/2021
//File: Police.cpp
// Purpose: To encompass everything we have learned throughout the year

#include "Police.h"
#include <iostream>
#include <cstdlib>
//************************************Function Definitions******************************
Police::Police(const int ID){
  policeID = ID;
  robbersDetained = 0;
  m_jewelsWorth = 0;
}

void Police::checkIndetity(Robber &ORA, Robber &ORB, Robber &GRA, Robber &GRB) {

  if ((PoliceCoor.x==ORA.robberCoord.x)&&(PoliceCoor.y==ORA.robberCoord.y))
  {
    Arrest(ORA);
  }
  if ((PoliceCoor.x==ORB.robberCoord.x)&&(PoliceCoor.y==ORB.robberCoord.y))
  {
    Arrest(ORB);
  }
  if ((PoliceCoor.x==GRA.robberCoord.x)&&(PoliceCoor.y==GRA.robberCoord.y))
  {
    Arrest(GRA);
  }
  if ((PoliceCoor.x==GRB.robberCoord.x)&&(PoliceCoor.y==GRB.robberCoord.y)) {
    Arrest(GRB);
  }
}

bool Police::checkNext(const int x, const int y) {
  bool valid = true;
  if(x<0 || x>9)
  {
    valid = false;
  }
  if(y<0||y>9)
  {
    valid = false;
  }
  return valid;
}

void Police::Arrest(Robber &robber) {
  m_jewelsWorth+=robber.robberCoord.x+robber.robberCoord.y;
  robber.m_stillActive= false;
  robbersDetained+=1;
  robber.m_jewelsPickedUp=0;
  robber.m_totalJewelWorth -= robber.m_jewelAmount;
  robber.m_jewelAmount = 0;
  cout<<"Robber ID "<<robber.robberID<<" has gotten arrested for being a bad bad boy"<<endl;
}
void Police::foundJewel(City &city){
  if(city.m_cityArray[PoliceCoor.x][PoliceCoor.y]=='J')
  {
    cout<<"The Police has encountered a Jewel"<<endl;
    city.m_cityArray[PoliceCoor.x][PoliceCoor.y]=' ';
  }
}
void Police::Move(City &city, Robber &ORA, Robber &ORB, Robber &GRA, Robber &GRB)
{
  int xold;
  int yold;
  int x;
  int y;
  bool Robber=false;
  bool finished = false;
  int randNum;
  xold=PoliceCoor.x;
  yold=PoliceCoor.y;
  if(city.m_cityArray[PoliceCoor.x][PoliceCoor.y]=='R')
  {
    checkIndetity(ORA, ORB, GRA, GRB);
  }
  do {
    randNum=rand()%8;
    //Do while loop for each random number generated
    if (randNum == 0) {
      x=PoliceCoor.x-1;
      y=PoliceCoor.y-1;
      if (checkNext(x, y)) {
        city.m_cityArray[PoliceCoor.x][PoliceCoor.y] = ' ';
        PoliceCoor.x = PoliceCoor.x - 1;
        PoliceCoor.y = PoliceCoor.y - 1;
        if(city.m_cityArray[PoliceCoor.x][PoliceCoor.y]=='R')
        {
          Robber=true;
        }
        foundJewel(city);
        city.m_cityArray[PoliceCoor.x][PoliceCoor.y] = 'P';
        finished = true;
      }
    }
    if (randNum == 1) {
      x=PoliceCoor.x-1;
      y=PoliceCoor.y;
      if (checkNext(x,y) == true)
      {
        city.m_cityArray[PoliceCoor.x][PoliceCoor.y] = ' ';
        PoliceCoor.x = PoliceCoor.x - 1;
        if(city.m_cityArray[PoliceCoor.x][PoliceCoor.y]=='R')
        {
          Robber=true;
        }
        foundJewel(city);
        city.m_cityArray[PoliceCoor.x][PoliceCoor.y] = 'P';
        finished = true;
      }
    }
    if (randNum == 2) {
      x=PoliceCoor.x-1;
      y=PoliceCoor.y+1;
      if (checkNext(x,y) == true)
      {
        city.m_cityArray[PoliceCoor.x][PoliceCoor.y] = ' ';
        PoliceCoor.x = PoliceCoor.x - 1;
        PoliceCoor.y = PoliceCoor.y + 1;
        if(city.m_cityArray[PoliceCoor.x][PoliceCoor.y]=='R')
        {
          Robber=true;
        }
        foundJewel(city);
        city.m_cityArray[PoliceCoor.x][PoliceCoor.y] = 'P';
        finished = true;
      }
    }
    if (randNum == 3) {
      x=PoliceCoor.x;
      y=PoliceCoor.y-1;
      if (checkNext(x,y) == true) {
        city.m_cityArray[PoliceCoor.x][PoliceCoor.y] = ' ';
        PoliceCoor.y = PoliceCoor.y - 1;
        if(city.m_cityArray[PoliceCoor.x][PoliceCoor.y]=='R')
        {
          Robber=true;
        }
        foundJewel(city);
        city.m_cityArray[PoliceCoor.x][PoliceCoor.y] = 'P';
        finished = true;
      }
    }
    if (randNum == 4) {
      x=PoliceCoor.x+1;
      y=PoliceCoor.y;
      if (checkNext(x,y) == true) {
        city.m_cityArray[PoliceCoor.x][PoliceCoor.y] = ' ';
        PoliceCoor.y = PoliceCoor.y + 1;
        if(city.m_cityArray[PoliceCoor.x][PoliceCoor.y]=='R')
        {
          Robber=true;
        }
        foundJewel(city);
        city.m_cityArray[PoliceCoor.x][PoliceCoor.y] = 'P';
        finished = true;
      }
    }

    if (randNum == 5) {
      x=PoliceCoor.x+1;
      y=PoliceCoor.y-1;
      if (checkNext(x,y) == true) {
        city.m_cityArray[PoliceCoor.x][PoliceCoor.y] = ' ';
        PoliceCoor.x = PoliceCoor.x + 1;
        PoliceCoor.y = PoliceCoor.y - 1;
        if(city.m_cityArray[PoliceCoor.x][PoliceCoor.y]=='R')
        {
          Robber=true;
        }
        foundJewel(city);
        city.m_cityArray[PoliceCoor.x][PoliceCoor.y] = 'P';
        finished = true;
      }
    }
    if (randNum == 6) {
      x=PoliceCoor.x+1;
      y=PoliceCoor.y;
      if (checkNext(x,y) == true) {
        city.m_cityArray[PoliceCoor.x][PoliceCoor.y] = ' ';
        PoliceCoor.x = PoliceCoor.x + 1;
        if(city.m_cityArray[PoliceCoor.x][PoliceCoor.y]=='R')
        {
          Robber=true;
        }
        foundJewel(city);
        city.m_cityArray[PoliceCoor.x][PoliceCoor.y] = 'P';
        finished = true;
      }
    }
    if (randNum == 7) {
      x=PoliceCoor.x+1;
      y=PoliceCoor.y+1;
      if (checkNext(x,y) == true) {
        city.m_cityArray[PoliceCoor.x][PoliceCoor.y] = ' ';
        PoliceCoor.x = PoliceCoor.x + 1;
        PoliceCoor.y = PoliceCoor.y + 1;
        if(city.m_cityArray[PoliceCoor.x][PoliceCoor.y]=='R')
        {
          Robber=true;
        }
        foundJewel(city);
        city.m_cityArray[PoliceCoor.x][PoliceCoor.y] = 'P';
        finished = true;
      }
    }
  }while (!finished);
  cout<<"New Police Coordinates: "<<PoliceCoor.x<<","<<PoliceCoor.y<<endl;
  if (ORA.m_stillActive)
  {
    cout<<"Ordinary Robber " << ORA.robberID << " Coordinates: "<<ORA.robberCoord.x<<","<<ORA.robberCoord.y<<endl;
  }
  if (ORB.m_stillActive)
  {
    cout<<"Ordinary Robber " << ORB.robberID << " Coordinates: "<<ORB.robberCoord.x<<","<<ORB.robberCoord.y<<endl;
  }
  if(GRA.m_stillActive)
  {
    cout<<"Greedy Robber " << GRA.robberID << " Coordinates: "<<GRA.robberCoord.x<<","<<GRA.robberCoord.y<<endl;
  }
  if(GRB.m_stillActive)
  {
    cout<<"Greedy Robber " << GRB.robberID << " Coordinates: "<<GRB.robberCoord.x<<","<<GRB.robberCoord.y<<endl;
  }


  if(Robber== true)
  {
    checkIndetity(ORA, ORB, GRA, GRB);
  }
}
void Police::AddPolice(City &city)
{
  int x=rand()%10;
  int y=rand()%10;
  city.m_cityArray[x][y]='P';
  PoliceCoor.x=x;
  PoliceCoor.y=y;
  cout<<"The Police initial position: "<<PoliceCoor.x<<","<<PoliceCoor.y<<endl;
  cout<<"\n";
}
void Police::Summary() {
  cout<<"Police id: "<<policeID<<endl;
  cout<<"\tConfiscated jewels amount: $"<<m_jewelsWorth<<endl;
  cout<<"\tFinal Number of robbers caught: "<<robbersDetained<<endl;
}
bool Police::robbersActive(const Robber &ORA, const Robber &ORB, const Robber &GRA, const Robber &GRB) {
  bool flag = false;
  if((ORA.m_stillActive==true)||(ORB.m_stillActive== true)
  ||(GRA.m_stillActive== true)||(GRB.m_stillActive==true))
  {
    flag = true;
  }
  return flag;
}

