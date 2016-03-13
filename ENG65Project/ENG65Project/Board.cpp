//
//  Board.cpp
//  ENG65Project
//
//  Created by Josephine Nordrum on 3/11/16.
//  Edited by Jenny Seong on 3/11/16.
//  Copyright © 2016 Josephine Nordrum. All rights reserved.
//

#include <stdio.h>
#include "Block.h"
#include "Ship.h"
#include "Board.h"
#include "PrintFns.hpp"

// default constructor for a 5x5 board
board::board() {
	blocks = new block[25];
	ships = new ship[2];
	dimension = 5;
}

// constructor with the input number as the dimension
board::board(int input, string shipsizes) {
	blocks = new block[input*input];
    
	for(int j =0; j < input*input; j++){
		blocks[j].setIndex(j);
	}
    
    ships = new ship[input/3];
    int size = input/3;
    
	for (int i =0; i < size; i++){
		int k = shipsizes[i]-48;
		ships[i] = ship(k, "The Destroyer");
	}
    
	dimension = input;
}

// Destructor
board::~board() {
	//find which block matches the input coordinates
	for(int i =0 ; i < dimension*dimension; i++){
		blocks[i].~block();
	}
}

// returns the dimension data of the board
int board::getDimension(void) { return dimension; }

//??
void board::assignShips(ship* locations) {
	//	ship = locations;
}

/**
 * Analyze the input coordinate and change status
 * (The attack aspect of the game)
 */
int board::processCoordinates(string stringin) {
	int index = convertIndex(stringin);
	int temp;
    int iwin = 0;
    int k = 0;
    int l =0;
    
	if (blocks[index].getStatus() != notchecked){
		cout << "You've already checked that location! Try another spot" << endl;
		string input;
		cin >> input;
		processCoordinates(input);
	}

	switch (blocks[index].getType()) {
		case engine:
			temp = blocks[index].getShipNum();
            cout << "You sunk their ship!" << endl;
			sinkShip(temp);
            iwin =0;
			break;
		case deck:
			blocks[index].setStatus(hitship);
            cout << "You've got a hit!"<< endl;
            iwin = 0;
			break;
		case artillery:
			blocks[index].setStatus(hitship);
            cout<< "You've hit the artillery! They have no weapons to fire back with.. take another turn!" << endl;
            iwin = 1;
			break;
		case water:
			blocks[index].setStatus(hitwater);
            cout << "Only water there..." << endl;
            iwin = 0;
			break;
        default:
            cout << "We could not process those coordinates, sorry!" << endl;
            iwin = 0;
            break;
	}
    
    for (int i = 0; i < dimension/3; i++){
        int size = ships[i].getSize();
        int *temp = ships[i].getBlocks();
        for (int j = 0; j < size; j ++){
            if (blocks[temp[j]].getStatus() == notchecked){
                k++;
            }
            l++;
        }
    }
    if (k != l) { iwin = 2; cout << "CONGRATULATIONS!!!" << endl;}
    return iwin;
}

/**
 * When the attack hits an engine room of the ship, the whole ship sinks.
 * Thus, we need to go into the blocks included in the ship and change the status of all blocks.
 */
void board::sinkShip(int number){
	int * tosink;
	tosink = ships[number].getBlocks();
	int size = ships[number].getSize();
	for (int i = 0; i<size; i++){
		blocks[tosink[i]].sink();
	}
}

// Print out entire board to the system display
void board::printBoard(int gamesetup){
	// for the first row, print out column information
	cout << "   ";
	for(int j=0; j < dimension; j++) { cout << " " << j+1 << " "; }
	cout << endl;
	// then, print row by row
	for(int i=0; i < dimension; i++) {
		cout << " " << (char)(i+65) << " ";		// print row character
		for(int j=0; j < dimension; j++) {
			int index = i*dimension + j;
			blocks[index].printBlock(gamesetup);
		}
		cout << endl;							// change line at the end of the row
	}
}

// Convert input string into index
int board::convertIndex(string input) {
	int x = input[0] - 65;				// convert row character into int
	int y = input[1] - 49;				// column
	int index = x*dimension + y;
	// if input coordinates are not included in board, send error message
	if (index >= dimension*dimension){
		cout << "That coordinate is not on the board! Please try again:" << endl;
        cin >> input;
        convertIndex(input);
	}
	return index;
}

/**
 * Place desired ships onto board
 * Need to input which ship and size of ship being placed
 */
void board::PlaceShips(int size, int shipno) {
	int index[size];			// array of integers for block indexes
	string input;				// variable to store user input

	// ask user for ship type and orientation
	char type = ShipType(size);
	char orient = ShipOrientation(size, type);

	// ask user for desired location and translate into indexed location on board
	cout << "Where would you like to place the engine [0] of this ship?: ";
	cin >> input;
	cin.ignore();
	index[0] = convertIndex(input);

	// if input coordinate is not valid, print error message
	if (index[0] == 10000) {
		cout << "We cannot place the ship in that location." << endl;
		return;
	}
    
	//ships[shipno] = new ship(shipsize);

	// enter engine information on block with entered coordinate
	blocks[index[0]].setType(engine);
	blocks[index[0]].setShipNum(shipno);

	// figure out block index numbers for the rest of the ship
	switch (size){
		case 2:
			if (orient ==  'a') { index[1] = index[0] - 1; }
			else if (orient ==  'b') { index[1] = index[0] + 1; }
			else if (orient ==  'c') { index[1] = index[0] + dimension; }
			else if (orient ==  'd') { index[1] = index[0] - dimension; }
			else { cout << "Something's wrong..." << endl; }
			break;
		case 3:
			switch (type){
			case 'a':
				if (orient == 'a') {
					index[1] = index[0] - 1;
					index[2] = index[0] - 2;
				}
				else if (orient == 'b') {
					index[1] = index[0] - dimension;
					index[2] = index[0] - 2*dimension;
				}
				else if (orient == 'c') {
					index[1] = index[0] + 1;
					index[2] = index[0] + 2;
				}
				else if (orient == 'd') {
					index[1] = index[0] + dimension;
					index[2] = index[0] + 2*dimension;
				}
				else { cout << "Something's wrong..." << endl; }
				break;
			case 'b':
				if (orient == 'a') {
					index[1] = index[0] - dimension;
					index[2] = index[1] - 1;
				}
				else if (orient == 'b') {
					index[1] = index[0] + 1;
					index[2] = index[1] - dimension;
				}
				else if (orient == 'c') {
					index[1] = index[0] + dimension;
					index[2] = index[1] + 1;
				}
				else if (orient == 'd') {
					index[1] = index[0] - 1;
					index[2] = index[2] + dimension;
				}
				else { cout << "Something's wrong..." << endl; }
				break;
			}
			break;
		case 4:
			switch (type) {
			case 'a':
				if (orient == 'a') {
					for (int i = 0; i < 2; i++) { index[i+1] = index[i] - 1; }
				}
				else if (orient == 'b') {
					for (int i = 1; i < 3; i++) { index[i] = index[i-1] - dimension; }
				}
				else if (orient == 'c') {
					for (int i = 0; i < 2; i++) { index[i+1] = index[i] + 1; }
				}
				else if (orient == 'd') {
					for (int i = 1; i < 3; i++) { index[i] = index[i-1] + dimension; }
				}
				else { cout << "Something's wrong..." << endl; }
				break;
			case 'b':
				if (orient == 'a') {
					index[1] = index[0] - dimension;
					index[2] = index[1] - 1;
					index[3] = index[0] - 1;
				}
				else if (orient == 'b') {
					index[1] = index[0] + 1;
					index[2] = index[0] - dimension;
					index[3] = index[2] + 1;
				}
				else if (orient == 'c') {
					index[1] = index[0] + dimension;
					index[2] = index[0] + 1;
					index[3] = index[1] + 1;
				}
				else if (orient == 'd') {
					index[1] = index[0] - 1;
					index[2] = index[0] + dimension;
					index[3] = index[2] -1;
				}
				else { cout << "Something's wrong..." << endl; }
				break;
			case 'c':
				if (orient == 'a') {
					index[1] = index[0] + 1;
					index[2] = index[1] + 1;
					index[3] = index[2] + dimension;
				}
				else if (orient == 'b') {
					index[1] = index[0] + dimension;
					index[2] = index[1] - dimension;
					index[3] = index[2] - 1;
				}
				else if (orient == 'c') {
					index[1] = index[0] - 1;
					index[2] = index[1] - 1;
					index[3] = index[2] - dimension;
				}
				else if (orient == 'd') {
					index[1] = index[0] - dimension;
					index[2] = index[1] - dimension;
					index[3] = index[2] + 1;
				}
				else { cout << "Something's wrong..." << endl; }
				break;
			}
			break;
		case 5:
			switch (type) {
			case 'b':
				if (orient == 'a') {
					for (int i = 0; i < 3; i++) { index[i+1] = index[i] - 1; }
				}
				else if (orient == 'b') {
					for (int i = 1; i < 4; i++) { index[i] = index[i-1] - dimension; }
				}
				else if (orient == 'c') {
					for (int i = 0; i < 3; i++) { index[i+1] = index[i] + 1; }
				}
				else if (orient == 'd') {
					for (int i = 1; i < 4; i++) { index[i] = index[i-1] + dimension; }
				}
				else { cout << "Something's wrong..." << endl; }
				break;
			case 'a':
				if (orient == 'a') {
					index[1] = index[0] - dimension;
					index[2] = index[1] - dimension;
					index[3] = index[2] - 1;
					index[4] = index[2] + 1;
				}
				else if (orient == 'b') {
					index[1] = index[0] + 1;
					index[2] = index[1] + 1;
					index[3] = index[2] + dimension;
					index[4] = index[2] - dimension;
				}
				else if (orient == 'c') {
					index[1] = index[0] + dimension;
					index[2] = index[1] + dimension;
					index[3] = index[2] - 1;
					index[4] = index[2] + 1;
				}
				else if (orient == 'd') {
					index[1] = index[0] - 1;
					index[2] = index[1] - 1;
					index[3] = index[2] + dimension;
					index[4] = index[2] - dimension;
				}
				else { cout << "Something's wrong..." << endl; }
				break;
			case 'c':
				if (orient == 'a') {
					index[1] = index[0] - dimension;
					index[2] = index[1] - dimension;
					index[3] = index[1] - 1;
					index[4] = index[2] - 1;
				}
				else if (orient == 'b') {
					index[1] = index[0] + 1;
					index[2] = index[1] + 1;
					index[3] = index[1] - dimension;
					index[4] = index[2] - dimension;
				}
				else if (orient == 'c') {
					index[1] = index[0] + dimension;
					index[2] = index[1] + dimension;
					index[3] = index[1] + 1;
					index[4] = index[2] + 1;
				}
				else if (orient == 'd') {
					index[1] = index[0] - 1;
					index[2] = index[1] - 1;
					index[3] = index[1] + dimension;
					index[4] = index[2] + dimension;
				}
				else { cout << "Something's wrong..." << endl; }
				break;
			}
			break;
		default:
			cout << "Invalid ship size!" << endl;
	}

	// enter information on deck blocks for the rest of the ship
	for (int i = 1; i<size; i++) {
		blocks[index[i]].setType(deck);
		blocks[index[i]].setShipNum(shipno);
	}

	// assign array of blocks to ship object
	ships[shipno].setBlock(index);
}
