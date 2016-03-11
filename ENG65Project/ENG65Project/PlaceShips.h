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


void board::PlaceShips(std::string shiptype, std::string location, int shipno){
    //translate desired location into indexed location on board
    int index = converttoindex(location);
    int shipsize = shiptype[0];
    char type = shiptype[1];
    char orient = shiptype[2];
    int index2;
   
    //ships[shipno] = new ship(shipsize);
    blocks[index].settype(engine);
    blocks[index].setshipno(shipno);
    ships[shipno].setblock(index);
    switch (shipsize){
    case 2:
            switch (orient){
                case 'a':
                    index2 = index-1;
                    break;
                case 'b':
                    index2 = index-1;
                    break;
                case 'c':
                    index2 = index + dimension;
                    break;
                case 'd':
                    index2 = index - dimension;
                    break;
                default:
                    std::cout << "ERROR: Reached default option 2" <<std::endl;
                    break;
            }
                blocks[index2].settype(deck);
                blocks[index2].setshipno(shipno);
                ships[shipno].setblock(index2);
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
