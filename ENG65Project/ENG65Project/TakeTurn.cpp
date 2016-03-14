//
//  TakeTurn.cpp
//  ENG65Project
//
//  Created by Josephine Nordrum on 3/12/16.
//  Edited by Jenny Seong on 3/14/16.
//  Copyright © 2016 Josephine Nordrum. All rights reserved.
//

#include "TakeTurn.hpp"
#include "Board.h"
#include "BoardSetUp.hpp"
#include <string>
#include <curses.h>

using namespace std;

/**
 * The attack phase of the game.
 * Returns 0 for a normal turn
 * 1 for a hit in the artillery (gets another turn)
 * 2 for a game won (sunk all ships)
 */
int takeTurn(Board theirboard, string player){
	string check;			// coordinate input for attacking

	cout << endl << endl << player << ", it's your turn! Here is your opponnent's board: " << endl;
	theirboard.printBoard(1);
	cout << "Enter the coordinates you would like to check: " << endl;
	cin >> check;
	cin.ignore(256,'\n');
	int turn = theirboard.processCoordinates(check);
	return turn;
}

/**
 * Overall gameplay of the game
 */
void gameplay(void){
	int dim, input;						// variable to store input dimensions and ship sizes
	string player1, player2;			// 2 players for a game

	cout << "Welcome to BATTLESHIP." << endl;
	cout << "Please enter the dimensions of the board (4~16): ";
	cin >> dim;
	while (cin.fail()) {
		cout << "That's not an integer! Please enter an integer between 4 and 16: ";
		cin.clear();
		cin.ignore(256,'\n');
		cin >> dim;
	}
	while (dim < 4 || dim > 16){
		if (dim < 4) {
			cout << "A board with sides of " << dim << " will be too small." << endl;
			cout << "try a size between 4 and 16: " << endl;
		}
		if (dim > 16) {
			cout << "A board with sides of " << dim << " will be too large." << endl;
			cout << "try a size between 4 and 16: " << endl;
		}
		cin >> dim;
	}
	cout << "Player 1, What would you like to be called?" << endl << ">> ";
	cin >> player1;
	cout << "Player 2, what would you like to be called?" << endl << ">> ";
	cin >> player2;

	// construct boards for the players
	Board board1(dim);
	Board board2(dim);

	// ask for sizes of ships they will be using
	int numShips = dim/3;
	int shipSizes[numShips];
	cout << "You will have " << numShips << " ships each." << endl;
	for (int i = 0; i < numShips; i++) {
		cout << "What size should ship #" << i+1 << " be? Enter 2, 3, 4, or 5: ";
		cin >> input;
		while (cin.fail() || input < 2 || input > 5) {
			cout << "Invalid ship size! Please enter 2, 3, 4, or 5: ";
			cin.clear();
			cin.ignore(256,'\n');
			cin >> input;
			}
		shipSizes[i] = input;
	}
	cout << "The input ship sizes are ";
	for (int i = 0; i < numShips; i++) { cout << shipSizes[i] << ". "; }
	cout << endl;

	//set up each player's board
	boardSetUp(player1, board1, shipSizes);
	boardSetUp(player2, board2, shipSizes);

	//run through the game
	int gamep = 0;                        // variable to check if the game is done or not
	int result1, result2;
	do {
		result1 = takeTurn(board2, player1);
   
		if (result1 != 0){
			if (result1 == 2) {
				cout << "CONGRATULATIONS!!!" << endl;
				cout << "YOU WIN " << player1 << "!!!!!"<< endl;
				gamep = 1;}
		}
		else{
			result2 = takeTurn(board1, player2);
			if (result2 != 0){
				while (result2 == 1){
				 takeTurn(board1, player2);
				}
			}
			if (result2 == 2) {
				gamep = 1;
				cout << "CONGRATULATIONS!!!" << endl;
				cout << "YOU WIN " << player2 << "!!!!!" << endl;}
		}

	} while (gamep == 0);

	cout << "Thanks for playing!!" << endl;

}
