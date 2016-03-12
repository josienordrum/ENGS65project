//
//  BoardSetUp.cpp
//  ENG65Project
//
//  Created by Josephine Nordrum on 3/12/16.
//  Copyright © 2016 Josephine Nordrum. All rights reserved.
//

#include "BoardSetUp.hpp"
#include "Board.h"
#include <stdio.h>
using namespace std;

void BoardSetUp(string player1, board board1, string shipsizes){
    int gamesetup = 0;                                  //game set up is not done so gamesetup = 0
    cout << "Hello "<< player1 << "! Let's set up your board! Let's start with your ship of size " << shipsizes[0] << endl;
    board1.printBoard(gamesetup);
    int temp = shipsizes[0]-48;
    board1.PlaceShips(temp,0);
    board1.printBoard(gamesetup);
    
    for( int i = 1; i < board1.getDimension()/3; i++){
        cout << "The next ship you entered is of size " << shipsizes[i];
        temp = shipsizes[i]-48;
        board1.PlaceShips(temp, i);
        board1.printBoard(gamesetup);
    }
}