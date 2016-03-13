//
//  TakeTurn.cpp
//  ENG65Project
//
//  Created by Josephine Nordrum on 3/12/16.
//  Copyright © 2016 Josephine Nordrum. All rights reserved.
//

#include "TakeTurn.hpp"
#include "Board.h"
#include "BoardSetUp.hpp"
#include <stdio.h>
#include <array>
#include <string>

using namespace std;

int TakeTurn(board theirboard, string player){
    
    cout << player << ", it's your turn! Here is your opponnents' board: " << endl;
    theirboard.printBoard(1);
    cout << "Enter the coordinates you would like to check:" << endl;
    string check;
    cin >> check;
    int turn = theirboard.processCoordinates(check);
    return turn;
}

void gameplay(void){
    int dim;
    string shipsizes, player1, player2;
    
    //intro
    cout << "Welcome to BATTLESHIP." << endl;
    cout << "Please enter the dimensions of the board: ";
    cin >> dim;
    while (dim < 4 || dim > 16){
        if (dim < 4) {
            cout << "A board with sides of " << dim << " will be too small; try a size between 4 and 16" << endl;
            cin >> dim;
        }
        if (dim > 16){
            cout << "A board with sides of " << dim << " will be too large; try a size between 4 and 16" << endl;
            cin >> dim;
        }
    }
    cout << "OK! You will have " << dim/3 << " ships! What sizes would you like them to be? Enter them as a continuous string. IE: '345'" << endl;
    cin >> shipsizes;
    cout << "Player 1, What would you like to be called?" << endl;
    cin >> player1;
    cout << "Player 2, what would you like to be called?" << endl;
    cin >> player2;
    //construct boards for the players
    board board1(dim, shipsizes);
    board board2(dim, shipsizes);
    //set up each player's board
    BoardSetUp(player1, board1, shipsizes);
    BoardSetUp(player2, board2, shipsizes);
    
    //run through the game
    int gamep = 0;
    int result1, result2;
    
    
    do {
        result1 = TakeTurn(board2, player1);
   
        if (result1 != 0){
            if (result1 == 2) {
                cout << "YOU WIN " << player1 << "!!!!!"<< endl;
                gamep = 1;}
        }else{
            result2 = TakeTurn(board1, player2);
            if (result2 != 0){
                while (result2 == 1){
                 TakeTurn(board1, player2);
                }
            }
            if (result1 == 2) { gamep = 1; cout << "YOU WIN " << player2 << "!!!!" << endl;}
        }
        
    } while (gamep == 0);
    
    cout << "Thanks for playing!!" << endl;
    
}