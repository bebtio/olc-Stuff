//
// Created by bebti on 1/19/2017.
//

#ifndef BATTLESHIP_PROJ_BOXRESULT_H
#define BATTLESHIP_PROJ_BOXRESULT_H

#include <string>

struct BoxResult
{
    BoxResult(): x{0},y{0}, result{"miss"}{}
    int x;
    int y;

    std::string result;

    bool isHit()
    {
        if(result == "hit")
        {
            return(true);
        }
        return(false);
    }
};


#endif //BATTLESHIP_PROJ_BOXRESULT_H
