#include "LanSheet.hpp"


//******************************************************//
//
//
//******************************************************//
LanSheet::LanSheet()
: SpriteSheet( "../../4_olcMMBNMap/images/MMBN2Lan.png" )
{
    loadAnimations();
}


//******************************************************//
//
//
//******************************************************//
LanSheet::~LanSheet()
{

}
 

//******************************************************//
//
//
//******************************************************//
bool LanSheet::loadAnimations()
{

    for( int i = 0; i < spriteSheet->width; i++ )
    {
        for( int j = 0; j < spriteSheet->height; j++ )
        {
            if( spriteSheet->GetPixel(i,j) == olc::Pixel( 0,128,128,255 ) )
            {
                spriteSheet->SetPixel(i,j, olc::Pixel(0,128,128,254) );
            }
        }
    }

    animations["walkLeft"].addFrameCornerCoords( {53,  126},{68,  165});
    animations["walkLeft"].addFrameCornerCoords( {70,  126},{100, 165});
    animations["walkLeft"].addFrameCornerCoords( {102, 126},{129, 165});
    animations["walkLeft"].addFrameCornerCoords( {131, 126},{146, 165});
    animations["walkLeft"].addFrameCornerCoords( {148, 126},{178, 165});
    animations["walkLeft"].addFrameCornerCoords( {180, 126},{206, 165});

    return(true);
}