//
//  Ship.h
//  ENG65Project
//
//  Created by Josephine Nordrum on 3/7/16.
//  Copyright © 2016 Josephine Nordrum. All rights reserved.
//

#ifndef Ship_h
#define Ship_h
#include "Block.h"
#include <string>

class ship {
private:
    std::string name;                //ships should have names
    int size;                   //how many squares does the ship take up?
    int *blockindicies;              //array of the ship's components
    
public:
    ship(int givensize, std::string name){
        blockindicies = new int[givensize];
        for(int i = 0; i < givensize; i++){
            blockindicies[i] = 10000;
        }
        size = givensize;
        name = name;
    }
    ship(){
        blockindicies = new int[2];
        for(int i = 0; i < 2; i++){
            blockindicies[i] = 10000;
        }
        size = 2;
        name = "Default Two";
    }
    
    ~ship(){
        delete[] blockindicies;
    }
    
    int* getblocks(){return blockindicies; }
    int getsizes(){return size;}
    
    void setblock( int index){
        int i =0;
        while (blockindicies[i] != 10000){
            i++;
        }
        blockindicies[i] = index;
    }
    
};


#endif /* Ship_h */
