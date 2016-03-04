//
//  main.cpp
//  ENG65Project
//
//  Created by Josephine Nordrum on 2/22/16.
//	Edited by Jenny Seong on 2/24/16.
//  Copyright © 2016 Josephine Nordrum. All rights reserved.

#include <iostream>
#include <array>
using namespace std;


enum blockstatus {notchecked, hitwater, hitship, sunkship}; //these are the block statuses
enum blocktype  {water, engine, deck, artillery};           //these are the types of blocks
enum orientation {vertical, horzontal};    //what is the ships orientation
enum inputletter {A, B, C, D, E, F, G, H, I, J, K}; //these turn the input coordinates into numbers


//int index = (b.x-1)*dimension + b.y;

class block {
private:
    blocktype type;             //enumeration of engine/deck/artillary room/ etc
    blockstatus status;
    bool stillstanding;           //enumeration of  float/sunk
    int boardindex;              //coordinates of block
    int shipnumber;             //which ship does the block belong to
public:
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

class ship {
private:
    string name;                //ships should have names
    int size;                   //how many squares does the ship take up?
    block *blocks;              //array of the ship's components
    orientation orient;         //determine if vertical or horizontal ship
    
public:
    ship(int givensize){
        blocks = new block[givensize];
    }
    
    void sinkship(){
        for(int i =0 ; i < size; i++){                //find which block matches the input coordinates
            blocks[i].status = sunkship;
        }
};
    
//functions: process coordinate (given a coordinate, find which ship block was hit and change its status… update status)

class board{
private:
    block *blocks;                //array of ships to check how many are left
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

    // function to assign ships onto board
    /** I set this as a separate function because I feel like we need to first initialize the board
     * to get the coordinates and then assign blocks according to the dimensions
     * but we'll talk about this later :)
     */
    void assignShips(ship* locations) {
    //	ship = locations;
    }

    void processcoordinates(int index) {
        if (blocks[index].status != notchecked){
            cout << "You've already checked that location! Try another spot:" << endl;
            cin >> index;
        }
        switch (blocks[index].type) {
            case engine:
                                //if its an engine,
                break;
            case deck:
                blocks[index].status = hitship;
                break;
            case artillery:
                blocks[index].status = hitship;
                //NEED CODE TO TELL THE PERSON THEY LOSE A TURN
                break;
            case water:
                blocks[index].status = hitwater;
        }
    }

    // print out the board to the screen
    void printBoard(){
    	// for the first row, print out column information
    	cout << "   ";
    	for(int j=0; j < dimension; j++) { cout << " " << j+1 << " "; }
    	cout << endl;
    	// then, print row by row
        for(int i=0; i < dimension; i++) {
    		cout << " " << (char)(i+65) << " ";			// print row character
            for(int j=0; j < dimension; j++) {
                int index = (i-1)*dimension + j;
                blocks[index].printblock();
    			    			}
    		}
    		cout << endl;		// change line at the end of the row
    	}
};




int main() {
	int dim, comd;
	char shipType;
	string coord;
	cout << "Welcome to BATTLESHIP." << endl;
	cout << "Please enter the dimensions of the board: ";
	cin >> dim;
	board mainBoard(dim);
	mainBoard.printBoard();
	cout << "Choose a ship to place (5-block): " << endl;
	cout << "(a) [O][O][O]     (b)                       (c) [O][O]" << endl;
	cout << "       [O]            [O][O][O][O][0]           [O][O]" << endl;
	cout << "       [0]                                         [0]" << endl;
	cout << "Enter a, b or c >> ";
	cin >> shipType;
	cout << "Where would you like to place the engine room ([0]) of this ship?" << endl;
	cin.ignore();
	cout << "Enter row character + column number (e.g. A5) >> ";
	getline(cin, coord);
	// find blocks and set them to ships
	mainBoard.printBoard();
	cout << "Are you happy with the placement?" << endl;
	cin.ignore();
	cout << "(1) YES!   (2)   Rotate   (3) Move >> ";
	cin >> comd;
    
    return 0;
}
