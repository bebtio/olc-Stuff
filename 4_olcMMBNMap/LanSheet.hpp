#ifndef __LANSHEET_HPP__
#define __LANSHEET_HPP__

#include "SpriteSheet.hpp"

//****************************************************//
//
//****************************************************//
class LanSheet : public SpriteSheet
{

public:

    LanSheet();
    ~LanSheet();
 
private:
    bool loadAnimations();

};


#endif // __LANSHEET_HPP__