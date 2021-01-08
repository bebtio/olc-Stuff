
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
	UPRIGHTSTATE,
	STANDSTATE

};

enum MovementSpeedState
{
	NORMALSTATE,
	FASTSTATE
};

class MmbnDisplay : public olc::PixelGameEngine
{
public:
	MmbnDisplay()
	: playerSpeed( olc::vd2d(100,50) )
	{
		sAppName = "ACDC Town!";
		pos.x = 0.0; 
		pos.y = 0.0;
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
		updateUserInput();

		// Update game state.
        updateGameState();

		// Render the game.
		updateGraphics();

		return true;
	}

	bool OnUserDestroy()
	{
		delete sprite;
		return( true );
	}

private:

	void updateUserInput();
	void updateCurrentDirectionState();
	void updateCurrentButtonStates();

	void updateGameState();
	void updateGraphics();

	olc::vd2d          pos;
	const olc::vd2d    playerSpeed;
	olc::Sprite*       sprite;

	DirectionState     currDirection;
	MovementSpeedState currSpeed;
};

#endif // __MMBNDISPLAY_HPP__
