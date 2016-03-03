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


class coordinates{
private:
    int x;
    int y;
public:
    coordinates();
    bool operator!=(coordinates l){
        if (this->x == l.x && this->y == l.y){
            return false; }
        else return true;
    }
};

enum blocktype {engine, deck, artillery}; //these are the type of shipblocks
enum orientation {vertical, horzontal};    //what is the ships orientation
enum inputletter {A, B, C, D, E, F, G, H, I, J, K}; //these turn the input coordinates into numbers


struct shipblock {
    blocktype type;            //enumeration of engine/deck/artillary room/ etc
    bool stillstanding;             //enumeration of  float/sunk
    coordinates b;             //coordinates of shipblock
};

class ship {
private:
    string name;                //ships should have names
    int size;                   //how many squares does the ship take up?
    bool isafloat;              //is the boat afloat?
    shipblock *blocks;          //array of the ship's components
    orientation  orient;        //determine if vertical or horizontal ship
    
public:
    ship(){
        blocks = new shipblock[size];
        isafloat = true;
    }
    
    void processcoordinates(coordinates input){
        int i = 0;
        while(input != blocks[i].b){                //find which block matches the input coordinates
            i++;
        }
        switch (blocks[i].type) {                   //see what type of block it is
            case engine:
                this->isafloat = false;             //if its an engine,
                break;
            case deck:
                blocks[i].stillstanding = false;
                break;
            case artillery:
                blocks[i].stillstanding = false;
                //NEED CODE TO TELL THE PERSON THEY LOSE A TURN
                break;
        }
        int j = 0;
        while (blocks[j].stillstanding == false){
            j++;
        }
        if (j == size){
            isafloat = false;
        }
    }
};
    
//functions: process coordinate (given a coordinate, find which ship block was hit and change its status… update status)

class board{
private:
    ship *ships;                     //array of ships to check how many are left
    int dimension;                   //(so we can check if a point is on the board)
public:
    // default constructor for a 5x5 board
    board() {
    	ships = NULL;
    	dimension = 5;
    }
    // constructor with the input number as the dimension
    board(int input) {
    	ships = NULL;
		dimension = input;
    }
    // destructor
    ~board() {
    	delete ships;
    }

    // function to assign ships onto board
    /** I set this as a separate function because I feel like we need to first initialize the board
     * to get the coordinates and then assign blocks according to the dimensions
     * but we'll talk about this later :)
     */
    void assignShips(ship* locations) {
    	ships = locations;
    }

    // checks status of location
    int checkLocation(int row, int column) {
    	// 1 for not checked
    	// 2 for hit water
    	// 3 for hit ship
    	// 4 for sunk ship
    }

    // print out the board to the screen
    void printBoard(){
    	// for the first line, print out column information
    	cout << "   ";
    	for(int j=0; j,dimension; j++) { cout << " " << j+1 << " "; }
    	cout << endl;
    	// then, print row by row
    	for(int i=0; i<dimension, i++) {
    		cout << " " << (char)(i+65) << " ";			// print row character
    		for(int j=0; j,dimension; j++) {
    			switch (this->checkLocation(i,j)) {
    			case 1: 			// not checked
    				cout << "[ ]";
    				break;
    			case 2: 			// hit water
    				cout << "[X]";
    				break;
    			case 3: 			// hit ship
    				cout << "[O]";
    				break;
    			case 4: 			// sunk ship
    				cout << "[0]";
    				break;
    			}
    		}
    		cout << endl;		// change line at the end of the row
    	}
    }
}



int main(int argc, const char * argv[]) {

    
    
    return 0;
}

