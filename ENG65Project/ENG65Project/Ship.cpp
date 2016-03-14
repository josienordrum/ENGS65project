//
//  Ship.cpp
//  ENG65Project
//
//  Created by Josephine Nordrum on 3/11/16.
//  Edited by Jenny Seong 3/11/16.
//  Copyright © 2016 Josephine Nordrum. All rights reserved.
//

#include <stdio.h>
#include "Block.h"
#include "Ship.h"
#include "PrintFns.hpp"

// Constructor with known size and name
ship::ship(int givensize, string nInput){
	size = givensize;
	type = 'a';														// set 'a' as default
	orientation = 'a';												// set 'b' as default
	engine = 1;														// placeholder for ship engine
	blockIndices = new int[givensize];								// allocates space for the number of blocks
	for(int i = 0; i < givensize; i++){ blockIndices[i] = 10000; }	// set block index to 10000 as default--will be set later
	name = nInput;
}

// Default constructor
ship::ship(){
	size = 2;
	type = 'a';														// set 'a' as default
	orientation = 'a';												// set 'b' as default
	engine = 1;														// placeholder for ship engine
	blockIndices = new int[size];									// default size: 2
	for(int i = 0; i < 2; i++){ blockIndices[i] = 10000; }			// again, set all indices to 10000 to fill array for now
	name = "TwoDecker[default]";									// default name: "TwoDecker[default]"
}

// Destructor
ship::~ship(){
    delete[] blockIndices;
}

/**
 * Set up parameters of the ship using functions from the PrintFns file
 */
void ship::shipSetup() {
	int input;
	bool error = true;
	cout << "What size should the ship be? Enter 2, 3, 4, or 5: ";
	while (error == true) {
		cin >> input;
		cin.ignore();
		if (input >= 2 && input <= 5) { error = false; }
		else { cout << "Invalid ship size. Please enter 2, 3, 4, or 5: "; }
	}
	size = input;
	type = ShipType(size);
	orientation = ShipOrientation(size, type);
}

// Return array of block indices for the ship
int* ship::getBlocks() { return blockIndices; }

// Return size of ship
int ship::getSize() { return size; }

// Return type of ship
char ship::getType() { return type; }

// Return orientation of ship
char ship::getOrientation() { return orientation; }

/**
 * Get the engine block's index number
 * Used for referencing ships when moving
 * e.g. "Destroyer placed at A5"
 */
int ship::getEngine() { return engine; }

// Set the block indices for the ship
void ship::setBlock(int* inputIndex){
	// if index array sizes do not match, send out error message
	if (sizeof(*inputIndex) != sizeof(*blockIndices)) { cout << "The array size doesn't match!" << endl; }
	// else, set indexes as ship blocks and engine block as the ship's engine
	else {
		for(int i = 0; i < size; i++) {blockIndices[i] = inputIndex[i]; }
		engine = inputIndex[0];
	}
}
