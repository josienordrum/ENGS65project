//
//  Board.cpp
//  ENG65Project
//
//  Created by Josephine Nordrum on 3/11/16.
//  Edited by Jenny Seong on 3/14/16.
//  Copyright © 2016 Josephine Nordrum. All rights reserved.
//

#include <stdio.h>
#include "Block.h"
#include "Ship.h"
#include "Board.h"

// default constructor for a 5x5 board
Board::Board() {
	blocks = new block[25];
	for(int j =0; j < 25; j++){ blocks[j].setIndex(j); }
	numShips = 2;
	ships = new ship[numShips];
	dimension = 5;
}

// constructor with the input number as the dimension
Board::Board(int input) {
	dimension = input;
	blocks = new block[dimension*dimension];
	for(int j =0; j < dimension*dimension; j++){ blocks[j].setIndex(j); }
    numShips = input/3;
    ships = new ship[numShips];
}

// Destructor
Board::~Board() {
	//find which block matches the input coordinates
	for(int i =0 ; i < dimension*dimension; i++){
		blocks[i].~block();
	}
}

// returns the dimension data of the board
int Board::getDimension(void) { return dimension; }

// returns number of ships that can fit on baord
int Board::getNumShips() { return numShips; }

/**
 * Analyze the input coordinate and change status
 * (The attack aspect of the game)
 * Returns 0 for a normal turn
 * 1 for a hit in the artillery (gets another turn)
 * 2 for a game won (sunk all ships)
 */
int Board::processCoordinates(string stringin) {
	int iwin = 0;                                // return value
	int standing = 0;                            // number of ship blocks still standing
	int shipNum;                                 // number of ship being affected

	// Change the coordinates into an index number
	int index = convertIndex(stringin);
	// Check if the coordinate has been processed already
	if (blocks[index].getStatus() != notchecked){
		cout << "You've already checked that location! Try another spot" << endl;
		string input;
		cin >> input;
		processCoordinates(input);
	}

	switch (blocks[index].getType()) {
		case engine:          // if engine, sink the entire ship
			shipNum = blocks[index].getShipNum();
			cout << "You sunk their ship!" << endl;
			sinkShip(shipNum);
			iwin = 0;                    // still a normal hit for now
			break;
		case deck:            // if deck, mark the deck as hit
			blocks[index].setStatus(hitship);
			cout << "You've got a hit!"<< endl;
			iwin = 0;                    // normal hit
			break;
		case artillery:       // if artillery, get another turn
			blocks[index].setStatus(hitship);
			cout << "You've hit the artillery!" << endl;
			cout << "They have no weapons to fire back with.. take another turn!" << endl;
			iwin = 1;                    // artillery hit -- gets another turn immediately
			break;
		case water:           // if water, mark water as hit
			blocks[index].setStatus(hitwater);
			cout << "Only water there..." << endl;
			iwin = 0;                    // normal hit
			break;
		default:
			cout << "We could not process those coordinates, sorry!" << endl;
			iwin = 0;
			break;
	}
	printBoard(1);
    
	// after processing coordinates, check all the ships for their status
	for (int i = 0; i < numShips; i++){
		int size = ships[i].getSize();
		int *temp = ships[i].getBlocks();
		for (int j = 0; j < size; j ++){
			// get number of blocks not checked
			if (blocks[temp[j]].getStatus() == notchecked){ standing++; }
		}
	}
	// if the number of not checked ship blocks are zero, everything is sunk
    if (standing == 0) { iwin = 2; }

    return iwin;
}

/**
 * Print out entire board to the system display
 * Use 0 for user (when placing), 1 for opponent (when attacking)
 */
void Board::printBoard(int gamesetup){
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

/**
 * Convert input string into index
 */
int Board::convertIndex(string input) {
	string temp;
	if (input.size() > 3){
		cout << "I'm sorry, those coordinates are invalid. Please re-enter in type 'A1'" << endl;
		cin >> temp;
		cin.ignore();
		convertIndex(temp);
		return -1;							// error = -1
	}
	else {
		int x, y;
		if (input.size() == 3) {
		temp[0] = input[1]; temp[1] = input[2];
		x = atoi( temp.c_str() ) - 1;
		y = input[0] - 65;
		}
		else {
			y = input[0] - 65;				// convert row character into int
			x = input[1] - 49;              // column
		}
		int index = y*dimension + x;
		// if input coordinates are not included in board, send error message
		if (index >= dimension*dimension){
			cout << "That coordinate is not on the board! Please try again:" << endl;
			cin >> input;
			convertIndex(input);
		}
		return index;
	}
}

/**
 * Convert board's block index into coordinates for user interface
 */
string Board::convertCoord(int index) {
	int row, column;
	string coordinates = "";
	column = (index+1) % dimension;
	row = (index+1-column) / dimension + 1;
	coordinates += row + 64;
	coordinates += column + 48;
	return coordinates;
}

// Check if input index fits on the board
bool Board::fitBoard(int index) {
	if ((index < 0) || (index >= dimension*dimension)) {
		cout << "The index " << index << " is out of bounds." << endl;
		return true;
	}
	else { return false; }
}

/**
 * Place desired ships onto board
 * Need to input which ship and size of ship being placed
 */
void Board::setupShip(int shipNo, int shipSize) {
	// set up ship by letting user decide what kind of ship they want
	ships[shipNo].shipSetup(shipSize);
}

/**
 * Place desired ships onto board
 * Need to input which ship is being placed
 */
void Board::placeShip(int shipNo) {
	// get ship size, type, and orientation from desired ship
	int size = ships[shipNo].getSize();
	char type = ships[shipNo].getType();
	char orient = ships[shipNo].getOrientation();

	int index[size];			// array of integers for block indexes
	bool error;					// error tracker
	string input;				// variable to store user input

	// ask user for desired location and translate into indexed location on board
	printBoard(0);
	cout << "Where would you like to place the engine [0] of this ship?" << endl;
	cout << "Please enter the coordinates using row and column number. (e.g. A5) >> ";
	cin >> input;
	index[0] = convertIndex(input);

	// if input coordinate is not valid, print error message
	if (index[0] == 10000) {
		cout << "We cannot place the ship in that location." << endl;
		placeShip(shipNo);
	}

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
					index[2] = index[1] - 1;
				}
				else if (orient == 'b') {
					index[1] = index[0] - dimension;
					index[2] = index[1] - dimension;
				}
				else if (orient == 'c') {
					index[1] = index[0] + 1;
					index[2] = index[1] + 1;
				}
				else if (orient == 'd') {
					index[1] = index[0] + dimension;
					index[2] = index[1] + dimension;
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
					index[2] = index[1] + dimension;
				}
				else { cout << "Something's wrong..." << endl; }
				break;
			}
			break;
		case 4:
			switch (type) {
			case 'a':
				if (orient == 'a') {
					for (int i = 0; i < 3; i++) { index[i+1] = index[i] - 1; }
				}
				else if (orient == 'b') {
					for (int i = 0; i < 3; i++) { index[i+1] = index[i] - dimension; }
				}
				else if (orient == 'c') {
					for (int i = 0; i < 3; i++) { index[i+1] = index[i] + 1; }
				}
				else if (orient == 'd') {
					for (int i = 0; i < 3; i++) { index[i+1] = index[i] + dimension; }
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
					index[1] = index[0] - dimension;
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
					for (int i = 0; i < 4; i++) { index[i+1] = index[i] - 1; }
				}
				else if (orient == 'b') {
					for (int i = 0; i < 4; i++) { index[i+1] = index[i] - dimension; }
				}
				else if (orient == 'c') {
					for (int i = 0; i < 4; i++) { index[i+1] = index[i] + 1; }
				}
				else if (orient == 'd') {
					for (int i = 0; i < 4; i++) { index[i+1] = index[i] + dimension; }
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

	// if all index numbers fit on the board, enter coordinates
	for (int i = 0; i<size; i++) { if (fitBoard(index[i])==true) { error = true; } }
	if (error == false) {
		// enter engine information on block with entered coordinate
		blocks[index[0]].setType(engine);
		blocks[index[0]].setShipNum(shipNo);
		// enter information on deck blocks for the rest of the ship
		for (int i = 1; i<size; i++) {
			blocks[index[i]].setType(deck);
			blocks[index[i]].setShipNum(shipNo);
		}
		// assign array of blocks to ship object
		ships[shipNo].setBlock(index);
	}
	else {
		cout << "The ship cannot be placed at that location!" << endl;
		placeShip(shipNo);
	}
}

// clear blocks related to given ship
void Board::clearShip(int shipNo) {
	int size = ships[shipNo].getSize();
	int *temp;
	temp = ships[shipNo].getBlocks();
	for (int i = 0; i<size; i++) {
		blocks[temp[i]].setType(water);
		blocks[temp[i]].setShipNum(0);
	}
}

/**
 * Move selected ship
 * prints out board and points out the engine to make sure desired ship is being moved
 */
void Board::moveShip(int shipNo) {
	int index = ships[shipNo].getEngine();
	printBoard(0);
	cout << "Moving ship located at " << convertCoord(index) << endl << endl;
	clearShip(shipNo);
	placeShip(shipNo);
}

/**
 * When the attack hits an engine room of the ship, the whole ship sinks.
 * Thus, we need to go into the blocks included in the ship and change the status of all blocks.
 */
void Board::sinkShip(int shipNo){
	int * tosink;
	tosink = ships[shipNo].getBlocks();
	int size = ships[shipNo].getSize();
	for (int i = 0; i<size; i++){
		blocks[tosink[i]].sink();
	}
}
