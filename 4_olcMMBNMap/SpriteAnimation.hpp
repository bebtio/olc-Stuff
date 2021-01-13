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
class SpriteAnimation : public olc::PGEX
{

public:
    SpriteAnimation();
    ~SpriteAnimation() {}

    // Add a new frame to this animation.
    void addFrame( olc::vi2d framePos, olc::vi2d frameDims );
    void addFrame( uint32_t xFramePos, uint32_t yFramePos, uint32_t xFrameDim, uint32_t yFrameDim );

    // Use the corner coordinates of the frame within the sprite sheet to add instead.
    void addFrameCornerCoords( olc::vi2d topLeftCorner, olc::vi2d bottomRightCorner );

    void update();
    void setFrameNum( uint32_t frameNum = 0 );
    void DrawFrame( olc::Sprite *sprite, uint32_t xDrawPos, uint32_t yDrawPos );
    void DrawFrame( olc::Sprite *sprite, olc::vi2d drawPos );
    const olc::vi2d getCurrentDims() { return( frameDims.at( currFrame ) ); }
private:

    std::vector<olc::vi2d> framePos;
    std::vector<olc::vi2d> frameDims;

    uint32_t numFrames;
    uint32_t currFrame;
};

}
#endif // __SPRITEANIMATION_HPP__