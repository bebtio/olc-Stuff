
#ifndef __MMBNDISPLAY_HPP__
#define __MMBNDISPLAY_HPP__

#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"

class MmbnDisplay : public olc::PixelGameEngine
{
public:
	MmbnDisplay()
	{
		sAppName = "ACDC Town!";
		pos.x = 0; 
		pos.y = 0;
	}

public:

	bool OnUserCreate() override
	{

		sprite = new olc::Sprite("../../4_olcMMBNMap/images/SecretCave.png");

		return true;
	}

	bool OnUserUpdate(float fElapsedTime) override
	{


		Clear( olc::Pixel( olc::BLACK ) );
		
		readInput();

		DrawSprite((ScreenWidth() - sprite->width)/2 + pos.x,
		           (ScreenHeight() - sprite->height)/2 + pos.y,sprite);

		return true;
	}

	bool OnUserDestroy()
	{
		delete sprite;
		return( true );
	}

private:
    void readInput()
	{
		int additionalVel(2);
		int vel(2);
		if( GetKey( olc::B ).bHeld )
		{
			vel = 2 + additionalVel;
		}
		if( GetKey( olc::UP ).bHeld )
		{
			pos.y += vel;
		}
		else if( GetKey( olc::DOWN ).bHeld )
		{
			pos.y -= vel;
		}

		if( GetKey( olc::LEFT ).bHeld)
		{
			pos.x += vel;
		}
		else if( GetKey( olc::RIGHT ).bHeld )
		{
			pos.x -= vel;
		}
		
	}
	olc::vi2d pos;
	olc::Sprite* sprite;
};

#endif // __MMBNDISPLAY_HPP__
