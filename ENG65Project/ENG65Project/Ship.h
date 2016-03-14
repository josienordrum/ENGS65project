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
#include <array>
using namespace std;

class ship {
private:
    string name;                      // ships should have names
    int size;                         // how many squares does the ship take up?
    char type;                        // ship type
    char orientation;                 // ship orientation
    int engine;                       // engine block (need for moving)
    int *blockIndices;                // array of the ship's components
    
public:
    ship(int givensize, std::string nInput);        // constructor with size and name
    ship();                                         // default constructor
    ~ship();                                        // destructor

    void shipSetup(int shipSize);                   // set size, type, orientation
    int  getSize();                                 // returns size of ship
    char getType();                                 // returns type of ship
    char getOrientation();                          // returns orientation of ship
    int getEngine();                                // returns engine block index
    int* getBlocks();                               // returns block array
    void setBlock(int* inputIndex);                 // set blocks for ship
};

#endif /* Ship_h */
