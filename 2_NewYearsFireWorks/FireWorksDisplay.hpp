
#ifndef __FIREWORKSDISPLAY_HPP__
#define __FIREWORKSDISPLAY_HPP__

#include <thread>
#include <chrono>

#include "olcPixelGameEngine.h"

#include "Firework.hpp"

#define FUSETIME 100
#define GRAVITY  0.15
class FireWorksDisplay : public olc::PixelGameEngine
{
public:
	FireWorksDisplay()
	{
		sAppName = "Happy New Year!";

	}

public:

	bool OnUserCreate() override
	{
		fw.initialize( olc::vd2d(ScreenWidth()/2, ScreenHeight()), olc::vd2d(0,-5), FUSETIME );

		return true;
	}

	bool OnUserUpdate(float fElapsedTime) override
	{

		Clear( olc::Pixel( olc::BLACK ) );
		RunFireWork( fw );

		return true;
	}

private:
    
	void RunFireWork( FireWork& f)
	{
		if( !f.timeToExplode() )
		{
			DrawFireWork( f );
		}
		else
		{
			DrawExplosion( f );
			ResetFireWork( f );
		}

		// Move through time.
		f.tick( GRAVITY );  

	}

    void DrawFireWork( FireWork& f )
    {
		FillCircle( f.pos.x, f.pos.y, 4 );
          
	}

	void DrawExplosion( FireWork& f )
	{
		DrawString( f.pos, "BOOM", olc::WHITE, 5U );
		std::this_thread::sleep_for( std::chrono::milliseconds(1000) );
	}

	void ResetFireWork( FireWork& f )
	{
		// Reset the position velocity parameters.
		int xVel = getRandomNumberInRange<int>(-2,2);
		int yVel = getRandomNumberInRange<int>(-12,-8);
		fw.initialize( olc::vd2d(ScreenWidth()/2, ScreenHeight()), olc::vd2d(xVel,yVel), FUSETIME );
	}

	// Creates the text that will be displayed on the screen.
	// Populated with key, mouse, and screen information.
    FireWork fw;
};

#endif // __FIREWORKSDISPLAY_HPP__
