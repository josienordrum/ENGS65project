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

// Constructor with known size and name
ship::ship(int givensize, string nInput){
    blockIndices = new int[givensize];			// allocates space for the number of blocks
    for(int i = 0; i < givensize; i++){
        blockIndices[i] = 10000;				// set block index to 10000 as default--will be set later when player puts ship on board
    }
    size = givensize;
    name = nInput;
}

// Default constructor
ship::ship(){
    blockIndices = new int[2];					// default size: 2
    for(int i = 0; i < 2; i++){
        blockIndices[i] = 10000;				// again, set all indices to 10000 to fill array for now
    }
    size = 2;
    name = "TwoDecker[default]";				// default name: "TwoDecker[default]"
}

// Destructor
ship::~ship(){
    delete[] blockIndices;
}

// Return array of block indices for the ship
int* ship::getBlocks() { return blockIndices; }


// Return size of ship
int ship::getSize() { return size; }

// Set the block indices for the ship
void ship::setBlock(int index[]){
	if (sizeof(index) == sizeof(blockIndices)) {			// check if the input indices are the same size
		for(int i = 0; i < size; i++) { blockIndices[i] = index[i]; }
	}
	else { cout << "The array size doesn't match!" << endl; }
}
