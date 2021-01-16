#ifndef __LANSHEET_HPP__
#define __LANSHEET_HPP__

#include "SpriteSheet.hpp"
#include "Entity2D.hpp"

//****************************************************//
//
//****************************************************//
class LanSheet : public SpriteSheet, public Entity2D<float>
{

public:

    LanSheet();
    ~LanSheet();
 
private:
    bool loadAnimations();

};


#endif // __LANSHEET_HPP__