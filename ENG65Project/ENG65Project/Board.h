//
//  Board.h
//  ENG65Project
//
//  Created by Josephine Nordrum on 3/7/16.
//  Copyright © 2016 Josephine Nordrum. All rights reserved.
//
#ifndef Board_h
#define Board_h

#include "Block.h"
#include "Ship.h"


class board{
    
private:
    block *blocks;                //array of ships to check how many are left
    ship *ships;
    int dimension;
    
public:
    board(); // default constructor for a 5x5 board
    board(int input, std::string shipsizes);
    ~board();
    int getdimension(void);
    void assignShips(ship* locations);
    void processcoordinates(std::string stringin);
    void sinkship(int number);
    void printBoard();
    int converttoindex(std::string input);
    void PlaceShips(std::string shiptype, std::string location, int shipno);
    
};
#endif /* Board_h */
