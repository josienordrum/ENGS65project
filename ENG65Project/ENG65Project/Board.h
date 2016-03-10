//
//  Board.h
//  ENG65Project
//
//  Created by Josephine Nordrum on 3/7/16.
//  Copyright © 2016 Josephine Nordrum. All rights reserved.
//

#include "Block.h"
#include "Ship.h"
#ifndef Board_h
#define Board_h

class board{
    
private:
    block *blocks;                //array of ships to check how many are left
    ship *ships;
    static int dimension;         //(so we can check if a point is on the board)
    
public:
    board() {                     // default constructor for a 5x5 board
        blocks = NULL;
        dimension = 5;
    }
    
    board(int input) {            // constructor with the input number as the dimension
        blocks = NULL;
        dimension = input;
    }
    
    ~board() {                    // destructor
        delete blocks;
    }
    
    void assignShips(ship* locations) {
        //	ship = locations;
    }
    
    void processcoordinates(std::string stringin) {
        char x = stringin[0];
        int y = stringin[1];
        int index = (x-1)*dimension + y;
        
        if (blocks[index].getstatus() != notchecked){
            std::cout << "You've already checked that location! Try another spot" << std::endl;
            std::string input;
            std::cin >> input;
            processcoordinates(input);
        }
        switch (blocks[index].gettype()) {
            case engine:
                ships[blocks[index].getshipnumber()].sinkship();                //if its an engine, sink the whole ship
                
                break;
            case deck:
                blocks[index].setstatus(hitship);
                break;
            case artillery:
                blocks[index].setstatus(hitship);
                //lose turn code here
                break;
            case water:
                blocks[index].setstatus(hitwater);
        }
    }
    
    
    void printBoard(){
        // for the first row, print out column information
        std::cout << "   ";                      //// print out the board to the screen
        for(int j=0; j < dimension; j++) { std::cout << " " << j+1 << " "; }
        std::cout << std::endl;
      
        for(int i=0; i < dimension; i++) {               // then, print row by row
            std::cout << " " << (char)(i+65) << " ";			// print row character
            for(int j=0; j < dimension; j++) {
                int index = (i-1)*dimension + j;
                blocks[index].printblock();
            }
        }
        std::cout << std::endl;		// change line at the end of the row
    }
};


#endif /* Board_h */
