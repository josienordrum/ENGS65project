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
#include "PrintFns.cpp"

// default constructor for a 5x5 board
board::board() {
	blocks = new block[25];
	ships = new ship[2];
	dimension = 5;
}

<<<<<<< HEAD
// constructor with the input number as the dimension
board::board(int input, string shipsizes) {
	blocks = new block[input*input];
	for(int j =0; j < input*input; j++){
		blocks[j].setIndex(j);
	}
	ships = new ship[input/3];
	for (int i =0; i < input/3; i++){
		int k = shipsizes[i]-48;
		ships[i] = ship(k, "The Destroyer");
		i++;
	}
	dimension = input;
}
=======
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
        int index2, index3, index4, index5;
        
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
>>>>>>> origin/master

// Destructor
board::~board() {
	//find which block matches the input coordinates
	for(int i =0 ; i < dimension*dimension; i++){
		blocks[i].~block();
	}
}

<<<<<<< HEAD
// returns the dimension data of the board
int board::getDimension(void) { return dimension; }

//??
void board::assignShips(ship* locations) {
	//	ship = locations;
}

/**
 * Analyze the input coordinate and change status
 * (The attack aspect of the game)
 */
void board::processCoordinates(string stringin) {
	int index = convertIndex(stringin);
	int temp;

	if (blocks[index].getStatus() != notchecked){
		cout << "You've already checked that location! Try another spot" << endl;
		string input;
		cin >> input;
		processCoordinates(input);
	}

	switch (blocks[index].getType()) {
		case engine:
			temp = blocks[index].getShipNum();
			sinkShip(temp);
			break;
		case deck:
			blocks[index].setStatus(hitship);
			break;
		case artillery:
			blocks[index].setStatus(hitship);
			// ********** lose turn code here *************
			break;
		case water:
			blocks[index].setStatus(hitwater);
			break;
	}
}

/**
 * When the attack hits an engine room of the ship, the whole ship sinks.
 * Thus, we need to go into the blocks included in the ship and change the status of all blocks.
 */
void board::sinkShip(int number){
	int *tosink;
	tosink = ships[number-1].getBlocks();
	int size = ships[number-1].getSize();
	for (int i = 0; i<size; i++){
		blocks[tosink[i]].sink();
	}
}

// Print out entire board to the system display
void board::printBoard(int player){
	// for the first row, print out column information
	cout << "   ";
	for(int j=0; j < dimension; j++) { cout << " " << j+1 << " "; }
	cout << endl;
	// then, print row by row
	for(int i=0; i < dimension; i++) {
		cout << " " << (char)(i+65) << " ";		// print row character
		for(int j=0; j < dimension; j++) {
			int index = i*dimension + j;
			blocks[index].printBlock(player);
		}
		cout << endl;							// change line at the end of the row
	}
}

// Convert input string into index
int board::convertIndex(string input) {
	int x = input[0] - 65;				// convert row character into int
	int y = input[1] - 49;				// column
	int index = x*dimension + y;
	// if input coordinates are not included in board, send error message
	if (index >= dimension*dimension){
		cout << "That coordinate is not on the board!" << endl;
		return NULL;
	}
	return index;
}

/**
 * Place desired ships onto board
 * Need to input which ship and size of ship being placed
 */
void board::PlaceShips(int size, int shipno) {
	int index[size];			// array of integers for block indexes
	string input;				// variable to store user input

	// ask user for ship type and orientation
	char type = ShipType(size);
	char orient = ShipOrientation(size, type);

	// ask user for desired location and translate into indexed location on board
	cout << "Where would you like to place this ship?: ";
	cin >> input;
	cin.ignore();
	index[0] = convertIndex(input);

	// if input coordinate is not valid, print error message
	if (index[0] == NULL) {
		cout << "We cannot place the ship in that location." << endl;
		return;
	}

	//ships[shipno] = new ship(shipsize);

	// enter engine information on block with entered coordinate
	blocks[index[0]].setType(engine);
	blocks[index[0]].setShipNum(shipno);

	// figure out block index numbers for the rest of the ship
	switch (size){
		case 2:
			if (orient ==  'a') { index[1] = index[0] - 1; }
			else if (orient ==  'b') { index[1] = index[0] + 1; }
			else if (orient ==  'c') { index[1] = index[0] + dimension; }
			else if (orient ==  'd') { index[1] = index[0] - dimension; }
			else { cout << "Something's wrong..." << endl; }
			break;
		case 3:
			switch (type){
			case 'a':
				if (orient == 'a') {
					index[1] = index[0] - 1;
					index[2] = index[0] - 2;
				}
				else if (orient == 'b') {
					index[1] = index[0] - dimension;
					index[2] = index[0] - 2*dimension;
				}
				else if (orient == 'c') {
					index[1] = index[0] + 1;
					index[2] = index[0] + 2;
				}
				else if (orient == 'd') {
					index[1] = index[0] + dimension;
					index[2] = index[0] + 2*dimension;
				}
				break;
			case 'b':
				if (orient == 'a') {
					index[1] = index[0] - dimension;
					index[2] = index[1] - 1;
				}
				else if (orient == 'b') {
					index[1] = index[0] + 1;
					index[2] = index[1] - dimension;
				}
				else if (orient == 'c') {
					index[1] = index[0] + dimension;
					index[2] = index[1] + 1;
				}
				else if (orient == 'd') {
					index[1] = index[0] - 1;
					index[2] = index[2] + dimension;
				}
				break;
			}
			break;
		case 4:
			switch (type) {
			case 'a':
				if (orient == 'a') {
					for (int i = 0; i < 2; i++) { index[i+1] = index[i] - 1; }
				}
				else if (orient == 'b') {
					for (int i = 1; i < 3; i++) { index[i] = index[i-1] - dimension; }
				}
				else if (orient == 'c') {
					for (int i = 0; i < 2; i++) { index[i+1] = index[i] + 1; }
				}
				else if (orient == 'd') {
					for (int i = 1; i < 3; i++) { index[i] = index[i-1] + dimension; }
				}
				break;
			case 'b':
				if (orient == 'a') {
					index[1] = index[0] - dimension;
					index[2] = index[1] - 1;
					index[3] = index[0] - 1;
				}
				else if (orient == 'b') {
					index[1] = index[0] + 1;
					index[2] = index[0] - dimension;
					index[3] = index[2] + 1;
				}
				else if (orient == 'c') {
					index[1] = index[0] + dimension;
					index[2] = index[0] + 1;
					index[3] = index[1] + 1;
				}
				else if (orient == 'd') {
					index[1] = index[0] - 1;
					index[2] = index[0] + dimension;
					index[3] = index[2] -1;
				}
				break;
			case 'c':
				if (orient == 'a') {
					index[1] = index[0] + 1;
					index[2] = index[1] + 1;
					index[3] = index[2] + dimension;
				}
				else if (orient == 'b') {
					index[1] = index[0] + dimension;
					index[2] = index[1] - dimension;
					index[3] = index[2] - 1;
				}
				else if (orient == 'c') {
					index[1] = index[0] - 1;
					index[2] = index[1] - 1;
					index[3] = index[2] - dimension;
				}
				else if (orient == 'd') {
					index[1] = index[0] - dimension;
					index[2] = index[1] - dimension;
					index[3] = index[2] + 1;
				}
				break;
			}
			break;
		case 5:
			switch (type) {
			case 'b':
				if (orient == 'a') {
					for (int i = 0; i < 3; i++) { index[i+1] = index[i] - 1; }
				}
				else if (orient == 'b') {
					for (int i = 1; i < 4; i++) { index[i] = index[i-1] - dimension; }
				}
				else if (orient == 'c') {
					for (int i = 0; i < 3; i++) { index[i+1] = index[i] + 1; }
				}
				else if (orient == 'd') {
					for (int i = 1; i < 4; i++) { index[i] = index[i-1] + dimension; }
				}
				break;
			case 'a':
				if (orient == 'a') {
					index[1] = index[0] - dimension;
					index[2] = index[1] - dimension;
					index[3] = index[2] - 1;
					index[4] = index[2] + 1;
				}
				else if (orient == 'b') {
					index[1] = index[0] + 1;
					index[2] = index[1] + 1;
					index[3] = index[2] + dimension;
					index[4] = index[2] - dimension;
				}
				else if (orient == 'c') {
					index[1] = index[0] + dimension;
					index[2] = index[1] + dimension;
					index[3] = index[2] - 1;
					index[4] = index[2] + 1;
				}
				else if (orient == 'd') {
					index[1] = index[0] - 1;
					index[2] = index[1] - 1;
					index[3] = index[2] + dimension;
					index[4] = index[2] - dimension;
				}
				break;
			case 'c':
				if (orient == 'a') {
					index[1] = index[0] - dimension;
					index[2] = index[1] - dimension;
					index[3] = index[1] - 1;
					index[4] = index[2] - 1;
				}
				else if (orient == 'b') {
					index[1] = index[0] + 1;
					index[2] = index[1] + 1;
					index[3] = index[1] - dimension;
					index[4] = index[2] - dimension;
				}
				else if (orient == 'c') {
					index[1] = index[0] + dimension;
					index[2] = index[1] + dimension;
					index[3] = index[1] + 1;
					index[4] = index[2] + 1;
				}
				else if (orient == 'd') {
					index[1] = index[0] - 1;
					index[2] = index[1] - 1;
					index[3] = index[1] + dimension;
					index[4] = index[2] + dimension;
				}
				break;
			}
			break;
		default:
			cout << "Invalid ship size!" << endl;
	}

	// enter information on deck blocks for the rest of the ship
	for (int i = 1; i<size; i++) {
		blocks[index[i]].setType(deck);
		blocks[index[i]].setShipNum(shipno);
	}

	// assign block to ship object
	ships[shipno].setBlock(index);
}
=======
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
                switch (type){
                        case 'a':
                            switch (orient){
                                case 'a':
                                    index2 = index - dimension;
                                    index3 = index2 - dimension;
                                    index4 = index3 + 1;
                                    index5 = index3 -1;
                                    break;
                                case 'b':
                                    index2 = index + 1;
                                    index3 = index2 + 1;
                                    index4 = index3 - dimension;
                                    index5 = index3 + dimension;
                                    break;
                                case 'c':
                                    index2 = index + dimension;
                                    index3 = index2 + dimension;
                                    index4 = index3 + 1;
                                    index5 = index3 -1;
                                    break;
                                case 'd':
                                    index2 = index - 1;
                                    index3 = index2 - 1;
                                    index4 = index3 - dimension;
                                    index5 = index3 + dimension;
                                    break;
                            }
                        break;
                        case 'b':
                                switch (orient){
                                    case 'a':
                                        break;
                                    case 'b':
                                        break;
                                    case 'c':
                                        break;
                                    case 'd':
                                        break;
                                }
                        break;
                        case 'c':
                                switch (orient){
                                    case 'a':
                                        break;
                                    case 'b':
                                        break;
                                    case 'c':
                                        break;
                                    case 'd':
                                        break;
                                }
                        break;
                        case 'd':
                                switch (orient){
                                    case 'a':
                                        break;
                                    case 'b':
                                        break;
                                    case 'c':
                                        break;
                                    case 'd':
                                        break;
                                }
                        break;
                        default:
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
                
                blocks[index5].settype(deck);
                blocks[index5].setshipno(shipno);
                ships[shipno].setblock(index5);
                
                break;
            default:
                
                break;
                
        }
    }
>>>>>>> origin/master
