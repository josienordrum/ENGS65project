//
//  Block.h
//  ENG65Project
//
//  Created by Josephine Nordrum on 3/7/16.
//  Copyright © 2016 Josephine Nordrum. All rights reserved.
//

#ifndef Block_h
#define Block_h
#include <iostream>
#include <functional>

enum blockstatus {notchecked, hitwater, hitship, sunkship}; //these are the block statuses
enum blocktype  {water, engine, deck, artillery};           //these are the types of blocks
enum inputletter {A, B, C, D, E, F, G, H, I, J, K}; //these turn the input coordinates into numbers


class block {
private:
    blocktype type;             //enumeration of engine/deck/artillary room/ etc
    blockstatus status;           //enumeration of  float/sunk
    int boardindex;              //coordinates of block
    int shipnumber;             //which ship does the block belong to

public:
    block();
    block(blocktype given, int index, int number);
    ~block();
    
    void operator = (block other);
    void sink(void);
    
    int getshipnumber(void);     //these functions return the values of private members
    blockstatus getstatus(void);
    blocktype gettype(void);
    void setstatus( blockstatus stat);
    void settype( blocktype stat);
    void setshipno(int shipno);
    void setindex(int index);
    int getindex(void);
    
    void printblock(void);
};



#endif /* Block_h */
