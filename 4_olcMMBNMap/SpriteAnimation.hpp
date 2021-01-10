#ifndef __SPRITEANIMATION__HPP__
#define __SPRITEANIMATION__HPP__

#include "olcPixelGameEngine.h"
#include <vector>
#include <iostream>
#include <string>

class SpriteAnimation : public olc::PGEX
{

public:
    SpriteAnimation( std::string spritePath );
    ~SpriteAnimation() { delete sprite; }

    // Add a new frame to this animation.
    void addFrame( olc::vi2d framePos, olc::vi2d frameDims );
    void addFrame( uint32_t xFramePos, uint32_t yFramePos, uint32_t xFrameDim, uint32_t yFrameDim );
    void addFrameCornerCoords( olc::vi2d topLeftCorner, olc::vi2d bottomRightCorner );

    void update();
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