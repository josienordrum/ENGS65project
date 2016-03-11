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
    
    ship(int givensize, std::string name);
    ship();
    ~ship();
    int* getblocks();               //getters and setters for private members of block
    int  getsizes();
    void setblock( int index);
    
};


#endif /* Ship_h */
