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
    int dimension;
    
public:
    board() {                     // default constructor for a 5x5 board
        blocks = new block[25];
        ships = new ship[2];
        dimension = 5;
    }
    
    board(int input) {            // constructor with the input number as the dimension
        blocks = new block[input*input];
        ships = new ship[input/3];
        dimension = input;
    }
    
    ~board() {                    // destructor
        for(int i =0 ; i < dimension*dimension; i++){                //find which block matches the input coordinates
            blocks[i].~block();
        }
    }
    
    int getdimension(void) {return dimension;}
    
    void assignShips(ship* locations) {
        //	ship = locations;
    }
    
    void processcoordinates(std::string stringin) {

        int index = converttoindex(stringin);
        
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
        for(int j=0; j < dimension; j++) {
            std::cout << " " << j+1 << " ";
        }
        
        std::cout << std::endl;
      
        for(int i=0; i < dimension; i++) {               // then, print row by row
            std::cout << " " << (char)(i+65) << " ";			// print row character
            
            for(int j=0; j < dimension; j++) {
                int index = i*dimension + j;
                blocks[index].printblock();
            }
            
            std::cout << std::endl;		// change line at the end of the row
        }
    }
    
    int converttoindex(std::string input){
        int y = input[1]-49;
        int x = input[0] - 65;
        int size = getdimension();
        int index = x*size + y;
        
        if (index >= size*size){
            std::cout << "That coordinate is not on the board!" << std::endl;
        }
        return index;
    }
    
    void PlaceShips(std::string shiptype, std::string location, int shipno);
    std::string ShipOrientation(int size, char type);
    char ShipType(int size);
};


#endif /* Board_h */
