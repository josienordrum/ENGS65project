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
    block(){                        //constructor for unidefned block
        type = water;
        status = notchecked;
        boardindex = 0;
        shipnumber = 0;
    }
    
    block(blocktype given, int index, int number){ //constructor for defined block (still initiates to unchecked)
        type = given;
        status = notchecked;
        boardindex = index;
        shipnumber = number;
    }
    
    ~block(){}
    
    void sink(void){
        status = sunkship;
    }
    
    void printblock(void){          //POTENTIALLY override cout instead
        switch (status) {
            case notchecked: 		// not checked
                std::cout << "[ ]";
                break;
            case hitwater: 			// hit water
                std::cout << "[X]";
                break;
            case hitship: 			// hit ship
                std::cout << "[O]";
                break;
            case sunkship: 			// sunk ship
                std::cout << "[0]";
                break;
        }
    }
};



#endif /* Block_h */
