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
#include <iostream>
#include <array>

using namespace std;


//int index = (b.x-1)*dimension + b.y;


int main(int argv, char* argc[]) {
    
	int dim, comd;
	char shipType;
    string coord;
	cout << "Welcome to BATTLESHIP." << endl;
	cout << "Please enter the dimensions of the board: ";
	cin >> dim;
	board mainBoard(dim);
	mainBoard.printBoard();
	cout << "Choose a ship to place (5-block): " << endl;
	cout << "(a) [O][O][O]     (b)                       (c) [O][O]" << endl;
	cout << "       [O]            [O][O][O][O][0]           [O][O]" << endl;
	cout << "       [0]                                         [0]" << endl;
	cout << "Enter a, b or c >> ";
	cin >> shipType;
	cout << "Where would you like to place the engine room ([0]) of this ship?" << endl;
	cin.ignore();
	cout << "Enter row character + column number (e.g. A5) >> ";
	getline(cin, coord);
	// find blocks and set them to ships
	mainBoard.printBoard();
	cout << "Are you happy with the placement?" << endl;
	cin.ignore();
	cout << "(1) YES!   (2)   Rotate   (3) Move >> ";
	cin >> comd;
    
    //this will be a subfunction of player
    cout<< "Enter a coordinate to test" <<endl;
    string stringin;
    cin >> stringin;
    mainBoard.processcoordinates(stringin);
    
    
    return 0;
};
