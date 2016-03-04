/*
 * printFns.cpp
 * Print functions for the Battleship game
 *  Created on: Mar 4, 2016
 *      Author: jennyseong
 */

#include <iostream>
using namespace std;

void printShipList(int size) {
	if (size == 2) {
		cout << "We will now place this ship" << endl;
		cout << "       [O][0]" << endl;
	}
	else if (size == 3) {
		cout << "Choose a ship to place (3-block): " << endl;
		cout << "(a) [O][O][0]     (b)[O][O]" << endl;
		cout << "                        [0]" << endl;
		cout << "Enter a or b >> ";
	}
	else if (size == 4) {
			cout << "Choose a ship to place (4-block): " << endl;
			cout << "(a) [O][O][O][0]     (b)[O][O]     (c) [0][O][O]" << endl;
			cout << "                        [0][O]               [O]" << endl;
			cout << "Enter a, b or c >> ";
		}
	else if (size == 5) {
		cout << "Choose a ship to place (5-block): " << endl;
		cout << "(a) [O][O][O]     (b)                       (c) [O][O]" << endl;
		cout << "       [O]            [O][O][O][O][0]           [O][O]" << endl;
		cout << "       [0]                                         [0]" << endl;
		cout << "Enter a, b or c >> ";
	}
	else { cout << "Invalid size" << endl; }
}
