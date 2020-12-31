
#ifndef __FIREWORKSDISPLAY_HPP__
#define __FIREWORKSDISPLAY_HPP__

#include "olcPixelGameEngine.h"

#include "Firework.hpp"

class FireWorksDisplay : public olc::PixelGameEngine
{
public:
	FireWorksDisplay()
	{
		sAppName = "Happy New Year!";
        fw.pos.x = ScreenWidth()/2;
        fw.pos.y = ScreenHeight();
        fw.vel.y = -2;
	}

public:

	bool OnUserCreate() override
	{
		return true;
	}

	bool OnUserUpdate(float fElapsedTime) override
	{

		Clear( olc::Pixel( olc::BLACK ) );
		DrawFireWork( fw );

		return true;
	}

private:

    void DrawFireWork( FireWork& f )
    {

        FillCircle( f.pos.x, f.pos.y, 4, f.color );
        f.tick();

    }
	// Creates the text that will be displayed on the screen.
	// Populated with key, mouse, and screen information.
    FireWork fw;

};

#endif // __FIREWORKSDISPLAY_HPP__
