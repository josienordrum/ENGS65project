//
//  TakeTurn.hpp
//  ENG65Project
//
//  Created by Josephine Nordrum on 3/12/16.
//  Edited by Jenny Soeng on 3/14/16.
//  Copyright © 2016 Josephine Nordrum. All rights reserved.
//

#ifndef TakeTurn_hpp
#define TakeTurn_hpp
#include "Board.h"
#include <string>
using namespace std;

#include <stdio.h>

int takeTurn(Board theirboard, string player);        // Function for the attack phase of the game
void waitEnter();                                     // Wait for user to hit return
void gameplay(void);                                  // Overall gameplay

#endif /* TakeTurn_hpp */
