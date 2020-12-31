
#ifndef __FIREWORKSDISPLAY_HPP__
#define __FIREWORKSDISPLAY_HPP__

#include <thread>
#include <chrono>

#include "olcPixelGameEngine.h"

#include "Firework.hpp"

class FireWorksDisplay : public olc::PixelGameEngine
{
public:
	FireWorksDisplay()
	{
		sAppName = "Happy New Year!";
		fw.initialize( olc::vd2d(ScreenWidth()/2, ScreenHeight()), olc::vd2d(0,-5) );
		currentTicks = 0;

	}

public:

	bool OnUserCreate() override
	{
		return true;
	}

	bool OnUserUpdate(float fElapsedTime) override
	{

		currentTicks++;
		std::this_thread::sleep_for(std::chrono::milliseconds(20));
		Clear( olc::Pixel( olc::BLACK ) );
		DrawFireWork( fw );
		return true;
	}

private:

    void DrawFireWork( FireWork& f )
    {

        FillCircle( f.pos.x, f.pos.y, 4 );
        
		// Move through time.
		f.tick( 0.1 );

		// 
		if( f.pos.y > ScreenHeight() )
		{
			fw.initialize( olc::vd2d(ScreenWidth()/2, ScreenHeight()), olc::vd2d(0,-5) );
		}

    
	}

	// Creates the text that will be displayed on the screen.
	// Populated with key, mouse, and screen information.
    FireWork fw;
	unsigned int currentTicks;
};

#endif // __FIREWORKSDISPLAY_HPP__
