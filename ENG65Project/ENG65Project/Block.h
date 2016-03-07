//
//  Block.h
//  ENG65Project
//
//  Created by Josephine Nordrum on 3/7/16.
//  Copyright © 2016 Josephine Nordrum. All rights reserved.
//

#ifndef Block_h
#define Block_h

enum blockstatus {notchecked, hitwater, hitship, sunkship}; //these are the block statuses
enum blocktype  {water, engine, deck, artillery};           //these are the types of blocks
enum inputletter {A, B, C, D, E, F, G, H, I, J, K}; //these turn the input coordinates into numbers


class block {
private:
    blocktype type;             //enumeration of engine/deck/artillary room/ etc
    blockstatus status;
    bool stillstanding;           //enumeration of  float/sunk
    int boardindex;              //coordinates of block
    int shipnumber;             //which ship does the block belong to
public:
    block(){
        type = water;
        status = notchecked;
    };
    ~block(){
        delete this;
    };
    
    void sink(void){
        status = sunkship;
    }
    
    void printblock(void){          //POTENTIALLY override cout instead
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
    };


#endif /* Block_h */
