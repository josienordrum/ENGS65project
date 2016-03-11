//
//  Ship.cpp
//  ENG65Project
//
//  Created by Josephine Nordrum on 3/11/16.
//  Copyright © 2016 Josephine Nordrum. All rights reserved.
//

#include <stdio.h>
#include "Block.h"
#include "Ship.h"

ship::ship(int givensize, std::string name){
    blockindicies = new int[givensize];
    for(int i = 0; i < givensize; i++){
        blockindicies[i] = 10000;
    }
    size = givensize;
    name = name;
}
ship::ship(){
    blockindicies = new int[2];
    for(int i = 0; i < 2; i++){
        blockindicies[i] = 10000;
    }
    size = 2;
    name = "Default Two";
}

ship::~ship(){
    delete[] blockindicies;
}

int* ship::getblocks(){return blockindicies; }
int ship::getsizes(){return size;}

void ship::setblock( int index){
    int i =0;
    while (blockindicies[i] != 10000){
        i++;
    }
    blockindicies[i] = index;
}
