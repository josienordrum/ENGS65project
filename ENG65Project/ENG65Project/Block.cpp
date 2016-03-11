//
//  Block.cpp
//  ENG65Project
//
//  Created by Josephine Nordrum on 3/11/16.
//  Copyright © 2016 Josephine Nordrum. All rights reserved.
//

#include <stdio.h>
#include "Block.h"


block::block(){                        //constructor for unidefned block
    type = water;
    status = notchecked;
    boardindex = 0;
    shipnumber = 0;
}

block::block(blocktype given, int index, int number){  //constructor for defined block (still initiates to unchecked)
    type = given;
    status = notchecked;
    boardindex = index;
    shipnumber = number;
}

block::~block(){
}

void block::operator = (block other){
    type = other.type;
    status = other.status;
    boardindex = other.boardindex;
    shipnumber = other.shipnumber;
}
void block::sink(void){
    status = sunkship;
}

int block::getshipnumber(void) {return shipnumber;}        //these functions return the values of private members
blockstatus block::getstatus(void){ return status; }
blocktype block::gettype(void) { return type; }
void block::setstatus( blockstatus stat){ status = stat; }
void block::settype( blocktype stat){ type = stat;}
void block::setshipno(int shipno){shipnumber = shipno;}
void block::setindex(int index) {boardindex = index;}
int block::getindex(void) {return boardindex;}

void block::printblock(void){          //POTENTIALLY override cout instead
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
