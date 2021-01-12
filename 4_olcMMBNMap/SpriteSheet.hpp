#ifndef __SPRITEANIMATION__HPP__
#define __SPRITEANIMATION__HPP__

#include "olcPixelGameEngine.h"
#include <vector>
#include <iostream>
#include <string>

namespace olc
{
//****************************************************//
//
//****************************************************//
class SpriteSheet
{

public:
    SpriteSheet( std::string spriteSheetPath );
    ~SpriteSheet();

    virtual void DrawAnimation    ( std::string animationKey, olc::vi2d pos, float dt );
    virtual void DrawAnimation    ( std::string animationKey, uint32_t xDrawPos, uint32_t yDrawPos, float dt );
    virtual void SetAnimationFrame( std::string animationKey, uint32_t frame );
    
private:
    virtual bool loadAnimations() = 0;
    olc::Sprite *spriteSheet;

    std::map< std::string, olc::SpriteAnimation > animations;
};

}
#endif // __SPRITEANIMATION_HPP__