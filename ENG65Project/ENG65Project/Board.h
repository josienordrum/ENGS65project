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
	void assignShips(ship* locations);					// assign ships to its locations
	int processCoordinates(string stringin);			// analyze input location
	void sinkShip(int number);							// sink entire ship with input ship reference number
	void printBoard(int gamesetup);						// print out the whole board to system
	int convertIndex(string input);						// convert input coordinate to block index number
	void PlaceShips(int size, int shipno);				// place ships on board
};

#endif /* Board_h */
