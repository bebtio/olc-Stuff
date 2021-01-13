#ifndef __SPRITESHEET__HPP__
#define __SPRITESHEET__HPP__

#include "olcPixelGameEngine.h"
#include "SpriteAnimation.hpp"
#include <vector>
#include <iostream>
#include <string>
#include <map>

//****************************************************//
//
//****************************************************//
class SpriteSheet
{

public:
    SpriteSheet( std::string spriteSheetPath );
    virtual ~SpriteSheet();

    virtual void DrawAnimation    ( std::string animationKey, olc::vi2d pos, float dt );
    virtual void DrawAnimation    ( std::string animationKey, uint32_t xDrawPos, uint32_t yDrawPos, float dt );
    virtual void SetAnimationFrame( std::string animationKey, uint32_t frame );
    
private:
    virtual bool loadAnimations() = 0;

    olc::Sprite *spriteSheet;
    std::map< std::string, olc::SpriteAnimation > animations;
};


#endif // __SPRITESHEET_HPP__