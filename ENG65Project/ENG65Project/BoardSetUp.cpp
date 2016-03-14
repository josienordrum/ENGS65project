//
//  BoardSetUp.cpp
//  ENG65Project
//
//  Created by Josephine Nordrum on 3/12/16.
//  Edited by Jenny Seong on 3/14/16.
//  Copyright © 2016 Josephine Nordrum. All rights reserved.
//

#include "BoardSetUp.hpp"
#include "Board.h"
#include <iostream>
using namespace std;

/**
 * Sets up the board with desired ships and their locations
 */
void boardSetUp(string player, Board board1, int* shipSizes){
	char happiness;
	string input;

	cout << endl << "Hello "<< player << "!" << endl;
	cout << "Let's set up your board! Here's the board: " << endl;
	board1.printBoard(0);
	// go through each ship to place on the board
	for(int i = 0; i < board1.getNumShips(); i++) {
		bool done = false;

		// first, set up the type and orientation of the ship. (Size is already set)
		board1.setupShip(i, shipSizes[i]);
		// then, place ship on the board
		board1.placeShip(i);

		// Check if the player is satisfied with the placement
		while (done == false) {
			board1.printBoard(0);
			cout << endl <<"Remember, when the engine [0] of the ship is hit, the whole ship sinks!" << endl;
			cout << "Do you like the placement of this ship? [y/n] (default = y) >> ";
			cin >> happiness;
			cin.ignore(256, '\n');
			if (happiness == 'n' || happiness == 'N') {
				cout << endl << "What's wrong with it?" << endl;
				cout << "1) I don't like the ship itself. I want to choose a different ship!" << endl;
				cout << "2) I just want to move it a little." << endl;
				cout << "Enter 1 or 2 (default = 2): ";
				cin >> happiness;
				cin.ignore();
				// if changing the ship go through setting up the ship again
				if (happiness == '1') {
					board1.clearShip(i);
					board1.setupShip(i, shipSizes[i]);
					board1.placeShip(i);
				}
				// if just moving, use the moveShip function
				else { board1.moveShip(i); }
			}
			else {
				cout << "Good! Let's move on." << endl << endl;
				done = true;
			}
		}
	}
	cout << "Now we need to place the artillery. You will be attacking from this location." << endl;
	cout << "When the artillery gets hit, you will lose a turn." << endl;
	board1.printBoard(0);
	cout << "Where would you like to place the artillery?" << endl;
	cout << "Enter coordinates (e.g. A5) >> ";
	cin >> input;
	board1.setArtillery(input);
	cout << endl << "You're done! Your board is set up like this: " << endl;
	board1.printBoard(0);
}
