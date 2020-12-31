
#ifndef __FIREWORKSDISPLAY_HPP__
#define __FIREWORKSDISPLAY_HPP__

#include <thread>
#include <chrono>
#include <string>

#include "olcPixelGameEngine.h"

#include "Firework.hpp"

#define FUSETIME 100
#define EXPLODETIME 100
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
		fw.initialize( olc::vd2d(ScreenWidth()/2, ScreenHeight()), 
		               olc::vd2d(0,-1), 
					   olc::vd2d(0,GRAVITY),
					   FUSETIME, 
					   EXPLODETIME );

		return true;
	}

	bool OnUserUpdate(float fElapsedTime) override
	{

		Clear( olc::Pixel( olc::BLACK ) );
		RunFireWork( fw );
		DrawString(0,0, std::to_string( fw.getPos().x ) + std::to_string( fw.getPos().y) );

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
			if( f.ExplosionFinished() )
			{
				ResetFireWork( f );
			}
		}

		// Move through time.
		f.tick();  

	}

    void DrawFireWork( FireWork& f )
    {
		FillCircle( f.getPos(), 4 );
	}

	void DrawExplosion( FireWork& f )
	{
		for( const olc::vd2d &flare : f.flarePos)
		{
			
			FillCircle(flare, 2);

		}
	}

	void ResetFireWork( FireWork& f )
	{
		// Reset the position velocity parameters.
		double xVel = getRandomNumberInRange<double>(-3,3);
		double yVel = getRandomNumberInRange<double>(-12,-8);

		fw.initialize( olc::vd2d(ScreenWidth()/2, ScreenHeight()), 
					   olc::vd2d(xVel,yVel), 
					   olc::vd2d(0, GRAVITY),
					   FUSETIME, 
					   EXPLODETIME );
	}

	// Creates the text that will be displayed on the screen.
	// Populated with key, mouse, and screen information.
    FireWork fw;
};

#endif // __FIREWORKSDISPLAY_HPP__
