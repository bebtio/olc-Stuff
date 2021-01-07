
#ifndef __MMBNDISPLAY_HPP__
#define __MMBNDISPLAY_HPP__

#include "olcPixelGameEngine.h"

enum DirectionState
{
	UPSTATE,
	UPLEFTSTATE,
	LEFTSTATE,
	DOWNLEFTSTATE,
	DOWNSTATE,
	DOWNRIGHTSTATE,
	RIGHTSTATE,
	UPRIGHTSTATE

};

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
		// Get User Input.
		updateCurrentDirectionState();

		// Update game state.
        updateGameState();
		// Render graphics.
		Clear( olc::Pixel( olc::BLACK ) );

		


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

	void updateCurrentDirectionState();
	void updateGameState();

	olc::vi2d pos;
	olc::Sprite* sprite;
	DirectionState currDirection;
};

#endif // __MMBNDISPLAY_HPP__
