#ifndef __SPRITEANIMATION__HPP__
#define __SPRITEANIMATION__HPP__

#include "olcPixelGameEngine.h"
#include <vector>
#include <iostream>
#include <string>

class SpriteAnimation : public olc::PGEX
{

public:
    SpriteAnimation( uint32_t xPos, uint32_t yPos, std::string spritePath, uint32_t xDim, uint32_t yDim, uint32_t numFrames );
    SpriteAnimation( olc::vi2d pos, std::string spritePath, olc::vi2d dims, uint32_t numFrames );
    ~SpriteAnimation() { delete sprite; }

    void update();
    olc::Sprite getCurrentSprite();
    void drawSelf( olc::vi2d drawPos );
    void drawSelf( uint32_t xDrawPos, uint32_t yDrawPos );

    const olc::vi2d getCurrentDims() { return( frameDims.at( currFrame ) ); }
private:
    olc::Sprite* sprite;
    std::vector<olc::vi2d> framePos;
    std::vector<olc::vi2d> frameDims;
    uint32_t numFrames;
    uint32_t currFrame;
};
#endif // __SPRITEANIMATION_HPP__