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
#include "PrintFns.h"

using namespace std;


//int index = (b.x-1)*dimension + b.y;


int main(int argc, const char * argv[]) {
    
	int dim, comd;
	//char shipType;
    //string coord;
	cout << "Welcome to BATTLESHIP." << endl;
	cout << "Please enter the dimensions of the board: ";
	cin >> dim;
    board talus(dim); talus.printBoard();
    cout << talus.converttoindex("C2");
    //board geek; geek.printBoard();
    cout << "please enter the size of ship you would like to place on it"<< endl;
    cin >> comd;
    char k, l;
    int size = comd;
    l = ShipType(size);
    k = ShipOrientation(size, l);
    cout<< "Returned char  "<< k << endl;
    
    
	//board mainBoard(dim);
	//mainBoard.printBoard();
/*
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
    mainBoard.processcoordinates(stringin);*/
    
    
    return 0;
};
