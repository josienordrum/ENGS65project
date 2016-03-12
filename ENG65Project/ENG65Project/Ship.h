//
//  Ship.h
//  ENG65Project
//
//  Created by Josephine Nordrum on 3/7/16.
//  Edited by Jenny Seong 3/11/16.
//  Copyright © 2016 Josephine Nordrum. All rights reserved.
//

#ifndef Ship_h
#define Ship_h

#include "Block.h"
#include <string>
using namespace std;

class ship {
private:
    string name;                     //ships should have names
    int size;                        //how many squares does the ship take up?
    int *blockIndices;               //array of the ship's components
    
public:
    ship(int givensize, std::string nInput);		// constructor with size and name
    ship();											// default constructor
    ~ship();										// destructor
    int* getBlocks();								// returns block array
    int  getSize();									// returns size of ship
    void setBlock(int index[]);						// set blocks for ship
};


#endif /* Ship_h */
