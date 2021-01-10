
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
// addFrame - Adds a frame of animation to this Animation.
// pulls pixels from framePos.x to framDims.x and
// framePos.y to frameDims.y.
//
// framePos - the position in the sprite sheet this frame starts at.
// frameDims - the size, height and width, of the frame.
//**************************************************************//
void SpriteAnimation::addFrame( olc::vi2d framePos, olc::vi2d frameDims )
{
    this->framePos.push_back( framePos );
    this->frameDims.push_back( frameDims );
    numFrames++;
}
 
//**************************************************************//
// addFrame
// Same as above but used the uses each x and y as an input instead
// of as a pair of olc::vi2d's. Ends up calling the addFrame function
// above.
//**************************************************************//
void SpriteAnimation::addFrame( uint32_t xFramePos, uint32_t yFramePos, uint32_t xFrameDim, uint32_t yFrameDim )
{
    addFrame( olc::vi2d( xFramePos, yFramePos ), olc::vi2d( xFrameDim, yFrameDim ) );
}

//**************************************************************//
// addFrameCornerCoords
// Same as above but used uses the upper left and lower right
// corner coordinates of the desired frame to load the sprite.
// This is sometimes easier than calculating the height and width
// of the frame yourself.
//**************************************************************//
void SpriteAnimation::addFrameCornerCoords( olc::vi2d topLeftCorner, olc::vi2d bottomRightCorner )
{
    // Compute the width and height of the frame.
    uint32_t xFrameDim( bottomRightCorner.x - topLeftCorner.x );
    uint32_t yFrameDim( bottomRightCorner.y - topLeftCorner.y );

    // Create a vi2d object.
    olc::vi2d frameDims( xFrameDim, yFrameDim );

    // Call the other addFrame function.
    addFrame( topLeftCorner, frameDims );
}

//**************************************************************//
// Loops over frames. Resets currFrame to 0 when we exceed the 
// number of frames this animation has.
//**************************************************************//
void SpriteAnimation::update()
{
    currFrame++;
    // Minus 1 for zero indexing.
    if( currFrame > numFrames - 1 ) 
    {
        currFrame = 0;
    }
}

void SpriteAnimation::setFrameNum( uint32_t frameNum )
{
    // Minus 1 for zero indexing. Clamp to realistic ranges.
    if( frameNum > numFrames - 1 ) { frameNum = numFrames; }
    if( frameNum < 0 )             { frameNum = 0;         }
}

//**************************************************************//
// Draws the sprite at the to screen at position drawPos.
//**************************************************************//
void SpriteAnimation::drawSelf( olc::vi2d drawPos )
{
    drawSelf( drawPos.x, drawPos.y );
}

//**************************************************************//
// Draws the sprite to the screen at the position (xDrawPos,yDrawPos).
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

    if( pge->GetKey( olc::N).bPressed ) { update(); }

    olc::vi2d currPos ( framePos.at ( currFrame ) );
    olc::vi2d currDims( frameDims.at( currFrame ) );
    olc::vi2d drawPos ( xDrawPos, yDrawPos        );

    pge->DrawPartialSprite( drawPos, sprite, currPos, currDims );

}