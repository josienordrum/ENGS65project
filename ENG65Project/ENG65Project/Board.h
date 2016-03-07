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
    
    void processcoordinates(string stringin) {
        char x = stringin[0];
        int y = stringin[1];
        int index = (x-1)*dimension + y;
        
        if (blocks[index].status != notchecked){
            cout << "You've already checked that location! Try another spot:" << endl;
            string input;
            cin >> input;
            processcoordinates(string input);
        }
        switch (blocks[index].type) {
            case engine:
                ships[blocks[index].shipnumber].sinkship();                //if its an engine, sink the whole ship
                break;
            case deck:
                blocks[index].status = hitship;
                break;
            case artillery:
                blocks[index].status = hitship;
                //lose turn code here
                break;
            case water:
                blocks[index].status = hitwater;
        }
    }
    
    
    void printBoard(){
        // for the first row, print out column information
        cout << "   ";                      //// print out the board to the screen
        for(int j=0; j < dimension; j++) { cout << " " << j+1 << " "; }
        cout << endl;
      
        for(int i=0; i < dimension; i++) {               // then, print row by row
            cout << " " << (char)(i+65) << " ";			// print row character
            for(int j=0; j < dimension; j++) {
                int index = (i-1)*dimension + j;
                blocks[index].printblock();
            }
        }
        cout << endl;		// change line at the end of the row
    }
};


#endif /* Board_h */
