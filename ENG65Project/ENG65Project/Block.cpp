//
//  Block.cpp
//  ENG65Project
//
//  Created by Josephine Nordrum on 3/11/16.
//  Edited by Jenny Seong on 3/12/16.
//  Copyright © 2016 Josephine Nordrum. All rights reserved.
//

#include <stdio.h>
#include "Block.h"

// Default constructor for unidentified block
block::block(){
    type = water;
    status = notchecked;
    boardIndex = 0;
    shipNum = 0;
}

/**
 * Constructor for a block with known information
 * Will be initiallized as "notchecked" since when a block is first made, it cannot have been checked)
 */
block::block(blockType given, int index, int number){
    type = given;
    status = notchecked;
    boardIndex = index;
    shipNum = number;
}

// Destructor
block::~block(){}

// Copy data to current block from "other" block
void block::operator = (block other){
    type = other.type;
    status = other.status;
    boardIndex = other.boardIndex;
    shipNum = other.shipNum;
}

/**
 * Set the status of the block to "sunkship"
 * (Using class function "setStatus")
 */
void block::sink(void){
    setStatus(sunkship);
}

// Get the type of the block
blockType block::getType(void) { return type; }

// Get the status of the block
blockStatus block::getStatus(void){ return status; }

// Get the board index of the block
int block::getIndex(void) { return boardIndex; }

// Get the ship number assigned to the block
int block::getShipNum(void) { return shipNum; }

// Set the block's type
void block::setType(blockType tp){ type = tp;}

// Set the ship number assigned to the block
void block::setStatus(blockStatus stat){ status = stat; }

// Set the index on the board assigned to the block
void block::setIndex(int index) { boardIndex = index; }

// Set the ship number assigned to the block
void block::setShipNum(int shipNo){ shipNum = shipNo; }

/**
 * Print out block to system according to the status of the block
 * player: 0 for user, 1 for opponent
 * (POSSIBLY OVERRIDE COUT)
 */
void block::printBlock(int gamesetup){
	// for the opponent's board (Check status of attacks)
	if (gamesetup == 1) {
		switch (status) {
			case notchecked: 		// not checked
				cout << "[ ]";
				break;
			case hitwater: 			// hit water
				cout << "[X]";
				break;
			case hitship: 			// hit ship
				cout << "[O]";
				break;
			case sunkship: 			// sunk ship
				cout << "[0]";
				break;
		}
	}

	// for the player's board (Check ship placement)
	else {
			switch (type) {
				case water: 		// no ship placed
					cout << "[ ]";
					break;
				case artillery: 	// attack rooms
					cout << "[X]";
					break;
				case deck: 			// decks
					cout << "[O]";
					break;
				case engine: 		// engine rooms
					cout << "[0]";
					break;
			}
		}
}
