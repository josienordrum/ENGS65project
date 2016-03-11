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
#include "PrintFns.h"
#include <iostream>
#include <array>


using namespace std;


//int index = (b.x-1)*dimension + b.y;


int main(int argc, const char * argv[]) {
    
    int dim, comd;
    string shipsizes;
	//char shipType;
    //string coord;
	cout << "Welcome to BATTLESHIP." << endl;
	cout << "Please enter the dimensions of the board: ";
	cin >> dim;
    cout << "OK! You will have " << dim/3 << " ships! What sizes would you like them to be?" << endl;
    cin >> shipsizes;
    board talus(dim, shipsizes); talus.printBoard();
    //board geek; geek.printBoard();
    cout << "please enter the size of ship you would like to place on it"<< endl;
    cin >> comd;
    int size = comd;
    talus.PlaceShips(ShipOrientation(size, ShipType(size)), "C3", 0);
    talus.processcoordinates("C3");
    talus.printBoard();

    return 0;
};
