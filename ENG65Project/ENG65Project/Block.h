//
//  Block.h
//  ENG65Project
//
//  Created by Josephine Nordrum on 3/7/16.
//  Edited by Jenny Seong on 3/11/16.
//  Copyright © 2016 Josephine Nordrum. All rights reserved.
//

#ifndef Block_h
#define Block_h

#include <iostream>
#include <functional>
using namespace std;

enum blockStatus {notchecked, hitwater, hitship, sunkship};		// possible status of blocks
enum blockType  {water, engine, deck, artillery};				// types of blocks
enum inputletter {A, B, C, D, E, F, G, H, I, J, K};				// coordinate translator

class block {
private:
    blockType type;               // block type: water/engine/deck/artillery
    blockStatus status;           // block status: notchecked/hitwater/hitship/sunlship
    int boardIndex;               // index of block on board
    int shipNum;                  // ship reference of block

public:
    block();											// default constructor
    block(blockType given, int index, int number);		// constructor with given situations
    ~block();											// destructor
    
    void operator = (block other);						// copy information from other block to current block
    void sink(void);									// sink the block if the ship it belongs to is sunk
    
    blockType getType(void);							// return type
    blockStatus getStatus(void);						// return status
    int getIndex(void);									// return boardIndex number
    int getShipNum(void);								// return shipNum

    void setType(blockType tp);							// set the type of the block
    void setStatus(blockStatus stat);					// set the status of the block
    void setIndex(int index);							// set the boardIndex
    void setShipNum(int shipNum);						// set the ship number
    
    void printBlock(int player);						// prints block to system according to its status
};

#endif /* Block_h */
