/*
 * printFns.cpp
 * Print functions for the Battleship game
 *  Created on: Mar 4, 2016
 *      Author: jennyseong
 */

#include <main.cpp>

/**
 * Enter ship size, prints out the types of ships with that number of blocks
 * Returns the charater of the ship to choose orientation
 */
char ShipType(int size) {
	char input;				// variable to store input
	int error = 0;			// error variable for looping for a valid input

	// there's only 1 option for a 2-block ship
	if (size == 2) { return 'a'; }

	// choose between 2 options for a 3-block ship
	else if (size == 3) {
		cout << "Choose a ship to place (3-block): " << endl;
		cout << "(a) [O][O][0]     (b)[O][O]" << endl;
		cout << "                        [0]" << endl;
		cout << "Enter a or b >> ";
		do {
			cin >> input;
			cin.ignore();
			if (input == 'a' || input == 'A') { return 'a'; }
			else if (input == 'b' || input == 'B') { return 'b'; }
			else {
				cout << "Invalid character. Please enter a or b >>";
			}
		} while (error == 0);
	}

	// choose between 3 options for a 4-block ship
	else if (size == 4) {
		cout << "Choose a ship to place (4-block): " << endl;
		cout << "(a) [O][O][O][0]     (b)[O][O]     (c) [0][O][O]" << endl;
		cout << "                        [0][O]               [O]" << endl;
		cout << "Enter a, b or c >> ";
		do {
			cin >> input;
			cin.ignore();
			if (input == 'a' || input == 'A') { return 'a'; }
			else if (input == 'b' || input == 'B') { return 'b'; }
			else if (input == 'c' || input == 'C') { return 'c'; }
			else {
				cout << "Invalid character. Please enter a, b, or c >>";
			}
		} while (error == 0);
	}

	// choose between 3 options for a 5-block ship
	else if (size == 5) {
		cout << "Choose a ship to place (5-block): " << endl;
		cout << "(a) [O][O][O]     (b)                       (c) [O][O]" << endl;
		cout << "       [O]            [O][O][O][O][0]           [O][O]" << endl;
		cout << "       [0]                                         [0]" << endl;
		cout << "Enter a, b or c >> ";
		do {
			cin >> input;
			cin.ignore();
			if (input == 'a' || input == 'A') { return 'a'; }
			else if (input == 'b' || input == 'B') { return 'b'; }
			else if (input == 'c' || input == 'C') { return 'c'; }
			else {
				cout << "Invalid character. Please enter a, b, or c >>";
			}
		} while (error == 0);
	}

	// if size was not 2, 3, 4, or 5, it's an error!
	else {
		cout << "Invalid size" << endl;
		return 'x';
	}
}


/**
 * Enter ship size and ship type character.
 * Prints out possible orientations, asks for input
 * Returns the input as the orientation of the ship as a character
 */
char ShipOrientation(int size, char type) {
	char input;					// variable to store input
	int error = 0;				// error tracking variable

	cout << "Which orientation?" << endl;

	// print out options for the 2-block ship
	if (size == 2) {
		cout << "(a)  [O][0]     (b)  [0][O]     (c)  [0]     (d)  [O]" << endl;
		cout << "                                     [O]          [0]" << endl;
	}

	// print out options for the 2 types of 3-block ships
	else if (size == 3) {
		if (type == 'a') {
			cout << "(a)  [O][O][0]     (b)  [O]     (c)  [0][O][O]     (d)  [0]" << endl;
			cout << "                        [O]                             [O]" << endl;
			cout << "                        [0]                             [O]" << endl;
		}
		else if (type == 'b') {
			cout << "(a)  [O][O]     (b)     [O]     (c)  [0]     (d)  [O][0]" << endl;
			cout << "        [0]          [0][O]          [O][O]       [O]" << endl;
		}
		else {
			cout << "invalid ship model" << endl;
			error = 1;
		}
	}

	// print out options for the 3 types of 4-block ships
	else if (size == 4) {
		if (type == 'a') {
			cout << "(a)  [O][O][O][0]     (b)  [O]     (c)  [0][O][O][O]     (d)  [0]" << endl;
			cout << "                           [O]                                [O]" << endl;
			cout << "                           [O]                                [O]" << endl;
			cout << "                           [0]                                [O]" << endl;
		}
		else if (type == 'b') {
			cout << "(a)  [O][O]     (b)  [O][O]     (c)  [0][O]  (d)  [O][0]" << endl;
			cout << "     [O][0]          [0][O]          [O][O]       [O][O]" << endl;
		}
		else if (type == 'c') {
			cout << "(a)  [0][O][O]     (b)     [0]     (c)  [O]           (d)  [O][O]" << endl;
			cout << "           [O]             [O]          [O][O][0]          [O]" << endl;
			cout << "                        [O][O]                             [0]" << endl;
		}
		else {
			cout << "invalid ship model" << endl;
			error = 1;
		}
	}

	// print out options for the 3 types of 5-block ships
	else if (size == 5) {
		if (type == 'b') {
			cout << "(a)  [O][O][O][O][0]     (b)  [O]     (c)  [0][O][O][O][O]     (d)  [0]" << endl;
			cout << "                              [O]                                   [O]" << endl;
			cout << "                              [O]                                   [O]" << endl;
			cout << "                              [O]                                   [O]" << endl;
			cout << "                              [0]                                   [O]" << endl;
		}
		else if (type == 'a') {
			cout << "(a)  [O][O][O]     (b)        [O]     (c)     [0]       (d)  [O]" << endl;
			cout << "        [O]             [0][O][O]             [O]            [O][O][0]" << endl;
			cout << "        [0]                   [O]          [O][O][O]         [O]" << endl;
		}
		else if (type == 'c') {
			cout << "(a)  [O][O]     (b)     [O][O]     (c)  [0]        (d)  [O][O][0]" << endl;
			cout << "     [O][O]          [0][O][O]          [O][O]          [O][O]" << endl;
			cout << "        [0]                             [O][O]" << endl;
		}
		else {
			cout << "invalid ship model" << endl;
			error = 1;
		}
	}
	else {
		cout << "invalid ship size" << endl;
		error = 1;
	}

	// if there was an error in choosing the ship type, print error message for debugging
	if (error == 1) {
		cout << "There's something wrong!";
		return 'x';
	}

	// if there was no error, ask for input and return orientation as character
	cout << "Enter a, b, c or d >> ";
	do {
		cin >> input;
		cin.ignore();
		if (input == 'a' || input == 'A') { return 'a'; }
		else if (input == 'b' || input == 'B') { return 'b'; }
		else if (input == 'c' || input == 'C') { return 'c'; }
		else if (input == 'd' || input == 'D') { return 'd'; }
		else {
			cout << "Invalid character. Please enter a, b, c or d >>";
		}
	} while (error == 0);
}
