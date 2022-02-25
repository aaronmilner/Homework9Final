//Programmer: Aaron Milner
//Programmer: Joshua Andreyev
//Assignment: hw9
//Date: 12/7/2021
//File: Greedy_Robber.cpp
// Purpose: To encompass everything we have learned throughout the year

#include "Greedy_Robber.h"

Greedy_Robber::Greedy_Robber(const int ID){
  robberID = ID;
  Bag = new Jewel[m_bagSize];
}

Greedy_Robber::~Greedy_Robber(){
  delete [] Bag;
}

void Greedy_Robber::move(City &city){
  bool even = false;
  int timesMoved = 0;

  do{
    if(m_stillActive){ //makes sure that they are not arrested and can move
      timesMoved +=1;
      if(timesMoved > 1)
        cout << "Greedy Robber " << robberID << " has found a jewel with an even value and gets to move again!" << endl;

      even = false;
      bool valid_move;
      int row;
      int col;

      do{
        valid_move = true;
        row = 0;
        col = 0;

        int random_move = rand() % 8; //picks a random direction to move in

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
        cout << "A greedy robber has picked up a jewel, Robber ID: " << robberID << endl;
        m_jewelsPickedUp += 1;
        Jewel *newJewel= new Jewel(robberCoord); //if they land on a jewel create a jewel and pick it up
        pickUpJewel(newJewel);

        if(newJewel->m_jewelValue % 2 == 0) //if it is an even value move again
          even = true;

        m_jewelAmount+= newJewel->m_jewelValue;
        m_totalJewelWorth += newJewel->m_jewelValue;

        city.m_cityArray[robberCoord.x][robberCoord.y] = 'R';

      }else if(city.m_cityArray[robberCoord.x][robberCoord.y] == 'P'){
        cout << "A robber has ran into the police and got arrested!" << endl;
        m_jewelsPickedUp = 0;
        m_totalJewelWorth -= m_jewelAmount;
        m_jewelAmount = 0;
        m_stillActive = false;

        city.m_cityArray[robberCoord.x][robberCoord.y] = 'R';

      }else if(city.m_cityArray[robberCoord.x][robberCoord.y] == ' '){
        city.m_cityArray[robberCoord.x][robberCoord.y] = 'R';

      }else if(city.m_cityArray[robberCoord.x][robberCoord.y] == 'R'){
        cout << "Oh no, a greedy robber has bumped into another robber and lost half his jewels!" << endl;
        cout << "Greedy robber ID: " << robberID << endl;
        int halfBag = m_bagSize / 2;
        if(slot > 0){
          for(int i = 0; i < halfBag; i++){
            m_jewelAmount -= Bag[i].m_jewelValue;
            m_totalJewelWorth -= Bag[i].m_jewelValue; //lose half their bag
            m_jewelsPickedUp -= 1;

            if(city.m_cityArray[Bag[i].m_jewelCoord.x][Bag[i].m_jewelCoord.y] == ' '){
              city.m_cityArray[Bag[i].m_jewelCoord.x][Bag[i].m_jewelCoord.y] = 'J';
            }else{
              while(city.m_cityArray[Bag[i].m_jewelCoord.x][Bag[i].m_jewelCoord.y] != ' '){ //makes sure the original jewel position is not occupied
                Bag[i].m_jewelCoord.x = rand()%10;
                Bag[i].m_jewelCoord.y = rand()%10;
              }
              city.m_cityArray[Bag[i].m_jewelCoord.x][Bag[i].m_jewelCoord.y] = 'J';
            }

          }
          if(m_jewelsPickedUp < 0)
            m_jewelsPickedUp = 0;
          if(m_jewelAmount < 0)
            m_jewelAmount = 0;
        }
        city.m_cityArray[robberCoord.x][robberCoord.y] = 'R';
      }
    }
  }while(even && timesMoved != 3);
}