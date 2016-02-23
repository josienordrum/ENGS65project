//
//  main.cpp
//  ENG65Project
//
//  Created by Josephine Nordrum on 2/22/16.
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
    ship *ships;                //array of ships to check how many are left
    int dimension;                   //(so we can check if a point is on the board)
public:
//functions: initialize, print, destroy?
};



int main(int argc, const char * argv[]) {

    
    
    return 0;
}

