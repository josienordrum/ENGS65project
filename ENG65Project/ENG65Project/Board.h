//
//  Board.h
//  ENG65Project
//
//  Created by Josephine Nordrum on 3/7/16.
//  Edited by Jenny Seong on 3/12/16.
//  Copyright © 2016 Josephine Nordrum. All rights reserved.
//
#ifndef Board_h
#define Board_h

#include "Block.h"
#include "Ship.h"

class board{
private:
	block *blocks;				// array of blocks included in board
	ship *ships;				// array of ships in game
	int dimension;				// dimensions of the board (dimension*dimension)
public:
	board(); 											// default constructor for a 5x5 board
	board(int size, string shipSizes);					// constructor with input dimensions
	~board();											// destructor

	int getDimension();									// returns the dimensions of the board
	int processCoordinates(string stringin);			// analyze input location
	void printBoard(int gamesetup);						// print out the whole board to system
	int convertIndex(string input);						// convert input coordinate to block index number
	string convertCoord(int index);						// convert index into coordinate string
	bool fitBoard(int index);							// check if coordinates fit on the board

	void placeShip(int shipNo);							// place ship on board
	void clearShip(int shipNo);							// clear board related to ships
	void moveShip(int shipNo);							// move ship
	void sinkShip(int shipNo);							// sink entire ship with input ship reference number
};

#endif /* Board_h */
