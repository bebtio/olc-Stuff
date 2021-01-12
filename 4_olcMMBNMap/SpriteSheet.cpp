#include "SpriteSheet.hpp"


//****************************************************************//
//
//
//
//****************************************************************//
SpriteSheet::SpriteSheet( std::string spriteSheetPath )
{
    spriteSheet = new olc::Sprite( spriteSheetPath );
}

//****************************************************************//
//
//
//
//****************************************************************//
SpriteSheet::~SpriteSheet()
{
    delete( spriteSheet );
}

//****************************************************************//
//
//
//
//****************************************************************//
void DrawAnimation( std::string animationKey, olc::vi2d pos, float dt )
{
    DrawAnimation( animationKey, pos.x, pos.y, dt );
}

//****************************************************************//
//
//
//
//****************************************************************//
void DrawAnimation( std::string animationKey, uint32_t xDrawPos, uint32_t yDrawPos, float dt )
{
    animations[animationKey].DrawFrame( sprite, pos.x, pos.y );
}

//****************************************************************//
//
//
//
//****************************************************************//
void SetAnimationFrame( std::string animationKey, uint32_t frame )
{
    animations[key].setFrameNum( frame );
}
    
