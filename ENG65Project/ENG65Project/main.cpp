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
#include <iostream>
#include <array>

enum player {user, opponent};

int main(int argc, const char * argv[]) {
	int dim, comd;
	string shipsizes;
	cout << "Welcome to BATTLESHIP." << endl;
	cout << "Please enter the dimensions of the board: ";
	cin >> dim;
	cout << "OK! You will have " << dim/3 << " ships! What sizes would you like them to be?" << endl;
	cin >> shipsizes;
	board talus(dim, shipsizes);
	talus.printBoard(user);
	//board geek; geek.printBoard();
	cout << "please enter the size of ship you would like to place on it"<< endl;
	cin >> comd;
	int size = comd;
	talus.PlaceShips(size,2);
	talus.processCoordinates("C3");
	talus.printBoard(user);

    return 0;
};
