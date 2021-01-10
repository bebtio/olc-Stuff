
#include "SpriteAnimation.hpp"

//**************************************************************//
// SpriteAnimation constructor
// spritePath - path to the sprite sheet.
//**************************************************************//
SpriteAnimation::SpriteAnimation( std::string spritePath )
{
    this->currFrame = 0;
    this->numFrames = 0;

    sprite = new olc::Sprite(spritePath);
}

//**************************************************************//
// addFrame
//**************************************************************//
void SpriteAnimation::addFrame( olc::vi2d framePos, olc::vi2d frameDims )
{
    this->framePos.push_back( framePos );
    this->frameDims.push_back( frameDims );
    numFrames++;
}
 
//**************************************************************//
// addFrame
//**************************************************************//
void SpriteAnimation::addFrame( uint32_t xFramePos, uint32_t yFramePos, uint32_t xFrameDim, uint32_t yFrameDim )
{
    this->framePos. push_back( olc::vi2d( xFramePos, yFramePos ) );
    this->frameDims.push_back( olc::vi2d( xFrameDim, yFrameDim ) );
    numFrames++;
}

void SpriteAnimation::addFrameCornerCoords( olc::vi2d topLeftCorner, olc::vi2d bottomRightCorner )
{
    uint32_t xFrameDim( bottomRightCorner.x - topLeftCorner.x );
    uint32_t yFrameDim( bottomRightCorner.y - topLeftCorner.y );

    olc::vi2d frameDims( xFrameDim, yFrameDim );

    addFrame( topLeftCorner, frameDims );
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

    if( numFrames == 0)
    {
        std::cout << "Error in SpriteAnimation: " << std::endl;
        std::cout << "numFrames is equal to 0."   << std::endl;
        std::cout << "Add frames using the addFrame function." << std::endl;
        throw;
    }

    if( pge->GetKey( olc::N).bPressed ) 
    { update(); }

    olc::vi2d currPos ( framePos.at( currFrame ) );
    olc::vi2d currDims( frameDims.at(currFrame ) );
    olc::vi2d drawPos ( xDrawPos, yDrawPos       );

    pge->DrawPartialSprite( drawPos, sprite, currPos, currDims );

}