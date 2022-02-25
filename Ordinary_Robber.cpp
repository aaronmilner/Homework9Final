//Programmer: Aaron Milner
//Programmer: Joshua Andreyev
//Assignment: hw9
//Date: 12/7/2021
//File: Ordinary_Robber.cpp
// Purpose: To encompass everything we have learned throughout the year

#include "Ordinary_Robber.h"


Ordinary_Robber::Ordinary_Robber(const int ID) {
  robberID = ID;
  Bag = new Jewel[m_bagSize];
}

Ordinary_Robber::~Ordinary_Robber() {
  delete [] Bag;
}

void Ordinary_Robber::move(City &city){
  if(m_stillActive){ //makes sure they are not already arrested and can move
    bool valid_move;
    int row;
    int col;
    do{
      valid_move = true;
      row = 0;
      col = 0;

      int random_move = rand() % 8; //picks a random direction to check

      if(random_move == 0){
        row += -1;
        col += -1;
      }else if(random_move == 1){
        row += -1;
      }else if(random_move == 2){
        row += -1;
        col += 1;
      }else if(random_move == 3){
        col += -1;
      }else if(random_move == 4){
        col += 1;
      }else if(random_move == 5){
        row += 1;
        col += -1;
      }else if(random_move == 6){
        row += 1;
      }else if(random_move == 7){
        row += 1;
        col += 1;
      }

      if(robberCoord.x + col < 0 || robberCoord.x + col > 9){
        valid_move = false;
      }
      if(robberCoord.y + row < 0 || robberCoord.y + row > 9){
        valid_move = false;
      }
    }while(!valid_move);

    city.m_cityArray[robberCoord.x][robberCoord.y] = ' ';

    robberCoord.x = robberCoord.x + col;
    robberCoord.y = robberCoord.y + row;


    if(city.m_cityArray[robberCoord.x][robberCoord.y] == 'J'){
      cout << "An ordinary robber has picked up a jewel, Robber ID: " << robberID << endl;
      m_jewelsPickedUp += 1;
      Jewel *newJewel= new Jewel(robberCoord); //when landing on a J, create the jewel and pickup/add it to the bag
      pickUpJewel(newJewel);
      m_jewelAmount+= newJewel->m_jewelValue;
      m_totalJewelWorth += newJewel->m_jewelValue;

      city.m_cityArray[robberCoord.x][robberCoord.y] = 'R';

    }else if(city.m_cityArray[robberCoord.x][robberCoord.y] == 'P'){
      cout << "A robber has ran into the police and has been arrested" << endl;

      m_jewelsPickedUp = 0;
      m_totalJewelWorth -= m_jewelAmount;
      m_jewelAmount = 0;
      m_stillActive = false;

      city.m_cityArray[robberCoord.x][robberCoord.y] = 'R';

    }else if(city.m_cityArray[robberCoord.x][robberCoord.y] == ' '){
      city.m_cityArray[robberCoord.x][robberCoord.y] = 'R';

    }else if(city.m_cityArray[robberCoord.x][robberCoord.y] == 'R'){
      cout << "Two robbers greet eachother at x: " << robberCoord.x << " y: " << robberCoord.y << endl;

      city.m_cityArray[robberCoord.x][robberCoord.y] = 'R';
    }
  }
}