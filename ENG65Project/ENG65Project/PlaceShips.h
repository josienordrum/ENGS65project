//
//  PlaceShips.h
//  ENG65Project
//
//  Created by Josephine Nordrum on 3/10/16.
//  Copyright © 2016 Josephine Nordrum. All rights reserved.
//

#ifndef PlaceShips_h
#define PlaceShips_h
#include "Block.h"
#include "Ship.h"
#include "Board.h"
#include <iostream>
#include <array>
#include "PrintFns.h"


void board::PlaceShips(std::string shiptype, std::string location){
    //translate desired location into indexed location on board
    int index = converttoindex(location);
    int shipsize = shiptype[0] - 48;
    char type = shiptype[1];
    char orient = shiptype[2];
    
    switch (shipsize){
    case 2:
            switch (orient){
                case 'a':
                    blocks[index].settype(engine);
                    blocks[index-1].settype(deck);
                    break;
                case 'b':
                    break;
                case 'c':
                    break;
                case 'd':
                    break;
                default:
                    std::cout << "Reached default option 2" <<std::endl;
                    break;
                    
            }
    break;
    case 3:
            switch (type){
                    
            }
    break;
    case 4:
    break;
    case 5:
    break;
    default:
    break;
    
    }
    
    
    
    
}






#endif /* PlaceShips_h */
