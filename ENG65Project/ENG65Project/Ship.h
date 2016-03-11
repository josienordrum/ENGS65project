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
    block *blocks;              //array of the ship's components
    
public:
    ship(int givensize, std::string name){
        blocks = new block[givensize];
        size = givensize;
        name = name;
    }
    ship(){
        blocks = new block[2];
        size = 2;
        name = "Ship 007";
    }
    
    ~ship(){
        for( int i =0; i < size; i++){
            blocks[i].~block();
        }
    }
    void sinkship(){
        for(int i =0 ; i < size; i++){                //find which block matches the input coordinates
            blocks[i].sink();
        }
    }
    
    void setblocks(block addme) {
        int i = 0;
        while (blocks[i].gettype() != water){
            i++;
            std::cout << "I have a block of type " << blocks[i].gettype() << "its boardindex is" << blocks[i].getindex();
        }
        blocks[i] = addme;
    }
    
    void debug(void){
        std::cout << "hello! my name is " << name << ", and my size is"<< size <<"!  My blocks are as follow:" << std::endl;
        for(int i =0; i< size; i++){
          std::cout << "I have a block of type " << blocks[i].gettype() << "its boardindex is" << blocks[i].getindex();
        }
    }
    
    
};


#endif /* Ship_h */
