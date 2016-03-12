//
//  main.cpp
//  ENG65Project
//
//  Created by Josephine Nordrum on 2/22/16.
//	Edited by Jenny Seong on 2/24/16.
//  Copyright © 2016 Josephine Nordrum. All rights reserved.

#include "Block.h"
#include "Ship.h"
#include "Board.h"
#include "PrintFns.hpp"
#include "BoardSetUp.hpp"
#include <iostream>
#include <array>

enum player {user, opponent};

int main(int argc, const char * argv[]) {
	int dim;
    string shipsizes, player1, player2;
	cout << "Welcome to BATTLESHIP." << endl;
	cout << "Please enter the dimensions of the board: ";
	cin >> dim;
	cout << "OK! You will have " << dim/3 << " ships! What sizes would you like them to be?" << endl;
	cin >> shipsizes;
    cout << "Player 1, What would you like to be called?" << endl;
    cin >> player1;
    cout << "Player 2, what would you like to be called?" << endl;
    cin >> player2;
    
    board board1(dim, shipsizes);
    board board2(dim, shipsizes);
    
    BoardSetUp(player1, board1, shipsizes);
    BoardSetUp(player2, board2, shipsizes);
    
    return 0;
};
