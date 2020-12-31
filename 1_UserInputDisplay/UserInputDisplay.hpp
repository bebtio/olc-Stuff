
#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"

class UserInputDisplay : public olc::PixelGameEngine
{
public:
	UserInputDisplay()
	{
		sAppName = "Displaying";
	}

public:
	bool OnUserCreate() override
	{
		displayString = "DisplayString";
		// Called once at the start, so create things here
		return true;
	}

	bool OnUserUpdate(float fElapsedTime) override
	{

		Clear( olc::Pixel( olc::BLACK) );
		CreateDisplayString();
		DrawString( 0, 0 , displayString );
		
		return true;
	}

private:
    void CreateDisplayString()
	{
		displayString  = "IsFocused:    " + std::to_string( IsFocused() )     + "\n";
		displayString += "MouseX:       " + std::to_string( GetMouseX() )     + "\n";
		displayString += "MouseY:       " + std::to_string( GetMouseY() )     + "\n";
		displayString += "ScreenHeight: " + std::to_string( ScreenHeight() )  + "\n";
		displayString += "ScreenWidth:  " + std::to_string( ScreenWidth() )   + "\n";

	}
    std::string displayString;

};
