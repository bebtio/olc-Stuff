
#include "SpriteAnimation.hpp"

//**************************************************************//
//
//**************************************************************//
SpriteAnimation::SpriteAnimation( uint32_t xPos, uint32_t yPos, std::string spritePath, uint32_t xDim, uint32_t yDim, uint32_t numFrames )
{
    this->currFrame = 0;
    this->numFrames = numFrames;
    uint32_t currXPos(xPos);
    uint32_t currYPos(yPos);

    for( uint32_t i = 0; i < numFrames; ++i )
    {
        framePos.push_back ( olc::vi2d( currXPos,currYPos ) );
        frameDims.push_back( olc::vi2d( xDim, yDim ) );

        currXPos += xDim;
        
    }

    sprite = new olc::Sprite(spritePath);
}


//**************************************************************//
// SpriteAnimation constructor
// Takes in a pos that defines the animations starting position
// on a sprite sheet. Assumes that all frames of the animation are
// the same size of size dims.
// pos - position of first frame in sprite sheet.
// spritePath - path to the sprite sheet.
// dims - the dimensions of each frame of the animation.
// numFrames - number of frames in the animation.
//**************************************************************//
SpriteAnimation::SpriteAnimation( olc::vi2d pos, std::string spritePath, olc::vi2d dims, uint32_t numFrames )
{
    SpriteAnimation( pos.x, pos.y, spritePath, dims.x, dims.y, numFrames );
}

//**************************************************************//
// Loops over frames. Resets currFrame to 0 when we exceed the 
// number of frames this animation has.
//**************************************************************//
void SpriteAnimation::update()
{
    currFrame++;
    if( currFrame >= numFrames )
    {
        currFrame = 0;
    }
}

//**************************************************************//
//
//**************************************************************//
void SpriteAnimation::drawSelf( olc::vi2d drawPos )
{
    drawSelf( drawPos.x, drawPos.y );
}

//**************************************************************//
//
//**************************************************************//
void SpriteAnimation::drawSelf( uint32_t xDrawPos, uint32_t yDrawPos )
{

    olc::vi2d currPos ( framePos.at( currFrame ) );
    olc::vi2d currDims( frameDims.at(currFrame ) );
    olc::vi2d drawPos ( xDrawPos, yDrawPos       );

    pge->DrawPartialSprite( drawPos, sprite, currPos, currDims );

}