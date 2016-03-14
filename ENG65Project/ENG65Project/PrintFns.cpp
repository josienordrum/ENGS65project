//
//  PrintFns.cpp
//  ENG65Project
//
//  Created by Josephine Nordrum on 3/11/16.
//  Edited by Jenny Seong on 3/12/16.
//  Copyright © 2016 Josephine Nordrum. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include "PrintFns.hpp"
using namespace std;

/**
 * Enter ship size, prints out the types of ships with that number of blocks
 * Returns the character of the ship to choose orientation
 */
char shipType(int size) {
	char input;				// variable to store input
	int error = 0;			// error variable for looping for a valid input

	switch(size){
		case 2:
			// there's only 1 option for a 2-block ship
			cout << "We will be placing the Miniboat: " << endl;
			cout << "    [O][0]" << endl;
			return 'a';
			break;

		case 3:
			// 2 options for a 3-block ship
			cout << "Choose a ship to place (3-block): " << endl;
            cout << "(a) Scout:       (b) Submarine: " << endl;
			cout << "    [O][O][0]        [O][O]" << endl;
            cout << "                        [0]" << endl;
			cout << "Enter a or b >> ";
			do {
				cin >> input;
				cin.ignore(256, '\n');
				if (input == 'a' || input == 'A') { return 'a'; }
				else if (input == 'b' || input == 'B') { return 'b'; }
				else {
					cout << "Invalid character. Please enter a or b >> ";
					cin.clear();
				}
			} while (error == 0);
			break;

		case 4:
			// 3 options for a 4-block ship
			cout << "Choose a ship to place (4-block): " << endl;
            cout << "(a) Enterprise       (b) Voyager   (c) Defiant: " << endl;
			cout << "    [O][O][O][0]         [O][O]        [0][O][O]" << endl;
			cout << "                         [0][O]              [O]" << endl;
			cout << "Enter a, b or c >> ";
			do {
				cin >> input;
				cin.ignore(256, '\n');
				if (input == 'a' || input == 'A') { return 'a'; }
				else if (input == 'b' || input == 'B') { return 'b'; }
				else if (input == 'c' || input == 'C') { return 'c'; }
				else {
					cout << "Invalid character. Please enter a, b, or c >> ";
					cin.clear();
				}
			} while (error == 0);
			break;

		case 5:
			// 3 options for a 5-block ship
			cout << "Choose a ship to place (5-block): " << endl;
            cout << "(a) Destroyer:    (b) Carrier:              (c) Fortress: " << endl;
			cout << "    [O][O][O]                                   [O][O]" << endl;
			cout << "       [O]            [O][O][O][O][0]           [O][O]" << endl;
			cout << "       [0]                                         [0]" << endl;
			cout << "Enter a, b or c >> ";
			do {
				cin >> input;
				cin.ignore(256, '\n');
				if (input == 'a' || input == 'A') { return 'a'; }
				else if (input == 'b' || input == 'B') { return 'b'; }
				else if (input == 'c' || input == 'C') { return 'c'; }
				else {
					cout << "Invalid character. Please enter a, b, or c >> ";
					cin.clear();
				}
			} while (error == 0);
			break;

		default:
			cout << "invalid ship size" << endl;
			return 'a';
			break;
	}
	return 'o';
}

/**
 * Enter ship size and ship type character.
 * Prints out possible orientations, asks for input
 * Returns the input as the orientation of the ship as a character
 */
char shipOrientation(int size, char type) {
	char input;					// variable to store input
	int error = 0;				// error tracking variable

	cout << "Which orientation?" << endl;

	// print out options for the 2-block ship
	switch (size){
		case 2:
			cout << "(a)  [O][0]     (b)  [0][O]     (c)  [0]     (d)  [O]" << endl;
			cout << "                                     [O]          [0]" << endl;
			break;

		case 3:
			switch (type){
				case 'a': {
					cout << "(a)  [O][O][0]     (b)  [O]     (c)  [0][O][O]     (d)  [0]" << endl;
					cout << "                        [O]                             [O]" << endl;
					cout << "                        [0]                             [O]" << endl;
				} break;
				case 'b': {
					cout << "(a)  [O][O]     (b)     [O]     (c)  [0]     (d)  [O][0]" << endl;
					cout << "        [0]          [0][O]          [O][O]       [O]" << endl;
				} break;
				default:
					cout << "invalid ship model" << endl;
					error = 1;
					break;
			}
			break;

		case 4:
			switch (type){
				case'a':
					cout << "(a)  [O][O][O][0]     (b)  [O]     (c)  [0][O][O][O]     (d)  [0]" << endl;
					cout << "                           [O]                                [O]" << endl;
					cout << "                           [O]                                [O]" << endl;
					cout << "                           [0]                                [O]" << endl;
					break;
				case'b':
					cout << "(a)  [O][O]     (b)  [O][O]     (c)  [0][O]  (d)  [O][0]" << endl;
					cout << "     [O][0]          [0][O]          [O][O]       [O][O]" << endl;
					break;
				case'c':
					cout << "(a)  [0][O][O]     (b)     [0]     (c)  [O]           (d)  [O][O]" << endl;
					cout << "           [O]             [O]          [O][O][0]          [O]" << endl;
					cout << "                        [O][O]                             [0]" << endl;
					break;
				default:
					cout << "invalid ship model" << endl;
					error = 1;
					break;
			} break;

		case 5:
			switch (type){
				case 'b':
					cout << "(a)  [O][O][O][O][0]     (b)  [O]     (c)  [0][O][O][O][O]     (d)  [0]" << endl;
					cout << "                              [O]                                   [O]" << endl;
					cout << "                              [O]                                   [O]" << endl;
					cout << "                              [O]                                   [O]" << endl;
					cout << "                              [0]                                   [O]" << endl;
					break;
				case'a':
					cout << "(a)  [O][O][O]     (b)        [O]     (c)     [0]       (d)  [O]" << endl;
					cout << "        [O]             [0][O][O]             [O]            [O][O][0]" << endl;
					cout << "        [0]                   [O]          [O][O][O]         [O]" << endl;
					break;
				case'c':
					cout << "(a)  [O][O]     (b)     [O][O]     (c)  [0]        (d)  [O][O][0]" << endl;
					cout << "     [O][O]          [0][O][O]          [O][O]          [O][O]" << endl;
					cout << "        [0]                             [O][O]" << endl;
					break;
				default:
					cout << "invalid ship model" << endl;
					error = 1;
					break;
			}break;

		default:
			cout << "invalid ship size" << endl;
			error = 1;
			break;
	}

	// if there was an error in printing the ship type options, print error message for debugging
	if (error == 1) {
		cout << "There's something wrong!";
		return '0';
	}
	// if there was no error, ask for input and return orientation as character
	cout << "Enter a, b, c or d >> ";
	do {
		cin >> input;
		cin.ignore(256, '\n');
		if      (input == 'a' || input == 'A') { return 'a'; }
		else if (input == 'b' || input == 'B') { return 'b'; }
		else if (input == 'c' || input == 'C') { return 'c'; }
		else if (input == 'd' || input == 'D') { return 'd'; }
		else {
			cout << "Invalid character. Please enter a, b, c or d >> ";
			cin.clear();
		}
	} while (error == 0);

	// if do-while loop is skipped, return dummy char '0' & alert of error
    cout << "ERROR: invalid ship" << endl;
	return '0';
}
