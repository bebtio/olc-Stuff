
#ifndef __FIREWORKSDISPLAY_HPP__
#define __FIREWORKSDISPLAY_HPP__

#include <thread>
#include <chrono>
#include <string>

#include "olcPixelGameEngine.h"

#include "Firework.hpp"

#define NUMFIREWORKS 25
#define NUMFLARES 50
#define FUSETIME 100
#define EXPLODEDURATION 300
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
		fw.resize(NUMFIREWORKS);


		for( FireWork& f : fw )
		{
			double xVel = getRandomNumberInRange<double>(-3,3);
			double yVel = getRandomNumberInRange<double>(-18,-12);

			f.initialize( olc::vd2d(ScreenWidth()/2, ScreenHeight()), 
			              olc::vd2d(xVel,yVel), 
						  olc::vd2d(0,GRAVITY),
						  FUSETIME, 
						  EXPLODEDURATION,
						  5,
						  NUMFLARES );
		}

		sprite = new olc::Sprite("../../2_NewYearsFireWorks/images/happyNewYear.png");

		return true;
	}

	bool OnUserUpdate(float fElapsedTime) override
	{


		Clear( olc::Pixel( olc::BLACK ) );
		DrawSprite((ScreenWidth() - sprite->width)/2,10, sprite, 0.25);

		for( FireWork& f: fw)
		{
			RunFireWork( f );
		}

		return true;
	}

	bool OnUserDestroy()
	{
		delete sprite;
		return( true );
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
		olc::Pixel color(getRandomNumberInRange<int>(155,255),
		 				 getRandomNumberInRange<int>(155,255),
						 getRandomNumberInRange<int>(155,255));

		FillCircle( f.getPos(), getRandomNumberInRange<int>(3,20),color );
	}

	void DrawExplosion( FireWork& f )
	{
		for( FireWork &flare : f.flares)
		{
			
			olc::Pixel color(getRandomNumberInRange<int>(155,255),
		 				     getRandomNumberInRange<int>(155,255),
						     getRandomNumberInRange<int>(155,255));
			int size( getRandomNumberInRange<int>(10,15));
			FillCircle( flare.getPos(), size, color);


		}
	}

	void ResetFireWork( FireWork& f )
	{
		// Reset the position velocity parameters.
		double xVel = getRandomNumberInRange<double>(-3,3);
		double yVel = getRandomNumberInRange<double>(-18,-12);

		f.initialize( olc::vd2d(ScreenWidth()/2, ScreenHeight()+20), 
					   olc::vd2d(xVel,yVel), 
					   olc::vd2d(0, GRAVITY),
					   FUSETIME, 
					   EXPLODEDURATION,
					   5,
					   NUMFLARES );
	}

	// Creates the text that will be displayed on the screen.
	// Populated with key, mouse, and screen information.
    std::vector<FireWork> fw;
	olc::Sprite* sprite;
};

#endif // __FIREWORKSDISPLAY_HPP__
