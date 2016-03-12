//
//  Board.cpp
//  ENG65Project
//
//  Created by Josephine Nordrum on 3/11/16.
//  Copyright © 2016 Josephine Nordrum. All rights reserved.
//

#include <stdio.h>
#include "Block.h"
#include "Ship.h"
#include "Board.h"


board::board() {                     // default constructor for a 5x5 board
        blocks = new block[25];
        ships = new ship[2];
        dimension = 5;
    }
    
    board::board(int input, std::string shipsizes) {            // constructor with the input number as the dimension
        blocks = new block[input*input];
        for(int j =0; j < input*input; j++){
            blocks[j].setindex(j);
        }
        ships = new ship[input/3];
        for (int i =0; i < input/3; i++){
            int k = shipsizes[i]-48;
            ships[i] = ship(k, "The Destroyer");
            i++;
        }
        dimension = input;
    }
    
    board::~board() {                    // destructor
        for(int i =0 ; i < dimension*dimension; i++){                //find which block matches the input coordinates
            blocks[i].~block();
        }
    }
    
    int board::getdimension(void) {return dimension;}
    
    void board::assignShips(ship* locations) {
        //	ship = locations;
    }
    
    void board::processcoordinates(std::string stringin) {
        
        int index = converttoindex(stringin);
        int temp;
        
        if (blocks[index].getstatus() != notchecked){
            std::cout << "You've already checked that location! Try another spot" << std::endl;
            std::string input;
            std::cin >> input;
            processcoordinates(input);
        }
        
        switch (blocks[index].gettype()) {
                
            case engine:
                temp = blocks[index].getshipnumber();                //if its an engine, sink the whole ship
                sinkship(temp);
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
    
    void board::sinkship(int number){
        int *tosink;
        tosink = ships[number].getblocks();
        int size = ships[number].getsizes();
        for (int i = 0; i<size; i++){
            blocks[tosink[i]].sink();
        }
    }
    
    void board::printBoard(){
        
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
    
    int board::converttoindex(std::string input){
        int y = input[1]-49;
        int x = input[0] - 65;
        int size = getdimension();
        int index = x*size + y;
        
        if (index >= size*size){
            std::cout << "That coordinate is not on the board!" << std::endl;
        }
        return index;
    }
    
    void board::PlaceShips(std::string shiptype, std::string location, int shipno){
        //translate desired location into indexed location on board
        int index = converttoindex(location);
        int shipsize = shiptype[0];
        char type = shiptype[1];
        char orient = shiptype[2];
        int index2, index3, index4;
        
        //ships[shipno] = new ship(shipsize);
        blocks[index].settype(engine);
        blocks[index].setshipno(shipno);
        ships[shipno].setblock(index);
        switch (shipsize){
            case 2:
                switch (orient){
                    case 'a':
                        index2 = index-1;
                        break;
                    case 'b':
                        index2 = index-1;
                        break;
                    case 'c':
                        index2 = index + dimension;
                        break;
                    case 'd':
                        index2 = index - dimension;
                        break;
                    default:
                        std::cout << "ERROR: Reached default option 2" <<std::endl;
                        break;
                }
                blocks[index2].settype(deck);
                blocks[index2].setshipno(shipno);
                ships[shipno].setblock(index2);
                break;
            case 3:
                switch (type){
                    case 'a':
                        switch(orient){
                            case 'a':
                                index2 = index -1;
                                index3 = index -2;
                                break;
                            case 'b':
                                index2 = index - dimension;
                                index3 = index - 2*dimension;
                                break;
                            case 'c':
                                index2 = index +1;
                                index3 = index +2;
                                break;
                            case 'd':
                                index2 = index + dimension;
                                index3 = index + 2*dimension;
                                break;
                            default:
                                std::cout << "ERROR: Reached default option 3a" <<std::endl;
                                break;
                        }
                        break;
                    case 'b':
                        switch(orient){
                            case 'a':
                                index2 = index -dimension;
                                index3 = index2 -1;
                                break;
                            case 'b':
                                index2 = index +1;
                                index3 = index2 -dimension;
                                break;
                            case 'c':
                                index2 = index + dimension;
                                index3 = index2 + 1;
                                break;
                            case 'd':
                                index2 = index -1;
                                index3 = index2 + dimension;
                                break;
                            default:
                                std::cout << "ERROR: Reached default option 3b" <<std::endl;
                                break;
                        }
                        break;
                    default:
                        std::cout << "ERROR: Reached default option 3" <<std::endl;
                        break;
                }
                blocks[index2].settype(deck);
                blocks[index2].setshipno(shipno);
                ships[shipno].setblock(index2);
                
                blocks[index3].settype(deck);
                blocks[index3].setshipno(shipno);
                ships[shipno].setblock(index3);
                break;
            case 4:
                switch (type) {
                    case 'a':
                        switch (orient) {
                            case 'a':
                                index2 = index  - dimension;
                                index3 = index2 - dimension;
                                index4 = index3 - dimension;
                                break;
                            case 'b':
                                index2 = index - 1;
                                index3 = index2 -1;
                                index4 = index3 -1;
                                break;
                            case 'c':
                                index2 = index  + dimension;
                                index3 = index2 + dimension;
                                index4 = index3 + dimension;
                                break;
                            case 'd':
                                index2 = index + 1;
                                index3 = index2 +1;
                                index4 = index3 +1;
                                break;
                        }
                        break;

                    case 'b':
                        switch (orient) {
                            case 'a':
                                index2 = index - dimension;
                                index3 = index2 -1;
                                index4 = index -1;
                                break;
                            case 'b':
                                index2 = index - dimension;
                                index3 = index2 +1;
                                index4 = index +1;
                                break;
                            case 'c':
                                index2 = index + dimension;
                                index3 = index2 + 1;
                                index4 = index +1;
                                break;
                            case 'd':
                                index2 = index + dimension;
                                index3 = index2 -1;
                                index4 = index -1;
                                break;
                        }
                        break;

                    case 'c':
                        switch (orient) {
                            case 'a':
                                index2 = index +1;
                                index3 = index2 +1;
                                index4 = index3 + dimension;
                                break;
                            case 'b':
                                index2 = index + dimension;
                                index3 = index2 + dimension;
                                index4 = index3 -1;
                                break;
                            case 'c':
                                index2 = index -1;
                                index3 = index2 -1;
                                index4 = index3 - dimension;
                                break;
                            case 'd':
                                index2 = index - dimension;
                                index3 = index2 - dimension;
                                index4 = index3 +1;
                                break;
                        }
                        break;
                    default:
                        std::cout << "ERROR: Reached default option 4" <<std::endl;
                        break;
                }
                blocks[index2].settype(deck);
                blocks[index2].setshipno(shipno);
                ships[shipno].setblock(index2);
                
                blocks[index3].settype(deck);
                blocks[index3].setshipno(shipno);
                ships[shipno].setblock(index3);
                
                blocks[index4].settype(deck);
                blocks[index4].setshipno(shipno);
                ships[shipno].setblock(index4);
                break;
            case 5:
                break;
            default:
                
                break;
                
        }
    }
