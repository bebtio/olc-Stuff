
#define OLC_PGE_APPLICATION
#include <map>
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
		initializeKeyMap();

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

	// Creates the text that will be displayed on the screen.
	// Populated with key, mouse, and screen information.
    void CreateDisplayString()
	{
		displayString  = "IsFocused:    " + std::to_string( IsFocused() )     + "\n";
		displayString += "MouseX:       " + std::to_string( GetMouseX() )     + "\n";
		displayString += "MouseY:       " + std::to_string( GetMouseY() )     + "\n";
		displayString += "ScreenHeight: " + std::to_string( ScreenHeight() )  + "\n";
		displayString += "ScreenWidth:  " + std::to_string( ScreenWidth() )   + "\n";
		displayString += GetCurrentlyPressedKeys()                            + "\n";
		displayString += GetCurrentlyPressedMousedButtons()                    + "\n";
	}

	// Loops through each of the buttons in the keyMap and checks whether the button
	// is held or pressed. If it is, then push the string to the currentlyPressedKey string.
	// Return the string once looping is finished.
	std::string GetCurrentlyPressedKeys()
	{
	
		olc::HWButton button;
		std::string currentlyPressedKeys = "Key Pressed: ";

		// Loop through each key.
		for( auto const& k : keyMap)
		{
			// Get the state of that key.
			button = GetKey(k.first);

			// Check if that key is pressed or being held.
			// Add it to the currentlyPressedKeys string if it is.
			if( button.bPressed || button.bHeld )
			{
				currentlyPressedKeys += k.second + " ";
			}
		}

		// Return the string once looping is complete.
		return( currentlyPressedKeys );

	}

	std::string GetCurrentlyPressedMousedButtons()
	{
		
		std::string currentlyPressedMousedButtons;

		return( currentlyPressedMousedButtons );

	}

	// Initialize the map that contains the mapping between olc define key enumerations
	// and their string representations for easy printing.
	void initializeKeyMap()
	{
      keyMap[olc::NONE] = "NONE";
      keyMap[olc::A] = "A";
      keyMap[olc::B] = "B";
      keyMap[olc::C] = "C";
      keyMap[olc::D] = "D";
      keyMap[olc::E] = "E";
      keyMap[olc::F] = "F";
      keyMap[olc::G] = "G";
      keyMap[olc::H] = "H";
      keyMap[olc::I] = "I";
      keyMap[olc::J] = "J";
      keyMap[olc::K] = "K";
      keyMap[olc::L] = "L";
      keyMap[olc::M] = "M";
      keyMap[olc::N] = "N";
      keyMap[olc::O] = "O";
      keyMap[olc::P] = "P";
      keyMap[olc::Q] = "Q";
      keyMap[olc::R] = "R";
      keyMap[olc::S] = "S";
      keyMap[olc::T] = "T";
      keyMap[olc::U] = "U";
      keyMap[olc::V] = "V";
      keyMap[olc::W] = "W";
      keyMap[olc::X] = "X";
      keyMap[olc::Y] = "Y";
      keyMap[olc::Z] = "Z";
      keyMap[olc::K0] = "K0";
      keyMap[olc::K1] = "K1";
      keyMap[olc::K2] = "K2";
      keyMap[olc::K3] = "K3";
      keyMap[olc::K4] = "K4";
      keyMap[olc::K5] = "K5";
      keyMap[olc::K6] = "K6";
      keyMap[olc::K7] = "K7";
      keyMap[olc::K8] = "K8";
      keyMap[olc::K9] = "K9";
      keyMap[olc::F1] = "F1";
      keyMap[olc::F2] = "F2";
      keyMap[olc::F3] = "F3";
      keyMap[olc::F4] = "F4";
      keyMap[olc::F5] = "F5";
      keyMap[olc::F6] = "F6";
      keyMap[olc::F7] = "F7";
      keyMap[olc::F8] = "F8";
      keyMap[olc::F9] = "F9";
      keyMap[olc::F10] = "F10";
      keyMap[olc::F11] = "F11";
      keyMap[olc::F12] = "F12";
      keyMap[olc::UP] = "UP";
      keyMap[olc::DOWN] = "DOWN";
      keyMap[olc::LEFT] = "LEFT";
      keyMap[olc::RIGHT] = "RIGHT";
      keyMap[olc::SPACE] = "SPACE";
      keyMap[olc::TAB] = "TAB";
      keyMap[olc::SHIFT] = "SHIFT";
      keyMap[olc::CTRL] = "CTRL";
      keyMap[olc::INS] = "INS";
      keyMap[olc::DEL] = "DEL";
      keyMap[olc::HOME] = "HOME";
      keyMap[olc::END] = "END";
      keyMap[olc::PGUP] = "PGUP";
      keyMap[olc::PGDN] = "PGDN";
      keyMap[olc::BACK] = "BACK";
      keyMap[olc::ESCAPE] = "ESCAPE";
      keyMap[olc::RETURN] = "RETURN";
      keyMap[olc::ENTER] = "ENTER";
      keyMap[olc::PAUSE] = "PAUSE";
      keyMap[olc::SCROLL] = "SCROLL";
      keyMap[olc::NP0] = "NP0";
      keyMap[olc::NP1] = "NP1";
      keyMap[olc::NP2] = "NP2";
      keyMap[olc::NP3] = "NP3";
      keyMap[olc::NP4] = "NP4";
      keyMap[olc::NP5] = "NP5";
      keyMap[olc::NP6] = "NP6";
      keyMap[olc::NP7] = "NP7";
      keyMap[olc::NP8] = "NP8";
      keyMap[olc::NP9] = "NP9";
      keyMap[olc::NP_MUL] = "NP_MUL";
      keyMap[olc::NP_DIV] = "NP_DIV";
      keyMap[olc::NP_ADD] = "NP_ADD";
      keyMap[olc::NP_SUB] = "NP_SUB";
      keyMap[olc::NP_DECIMAL] = "NP_DECIMAL";
      keyMap[olc::PERIOD] = "PERIOD";
      keyMap[olc::EQUALS] = "EQUALS";
      keyMap[olc::COMMA] = "COMMA";
      keyMap[olc::MINUS] = "MINUS";
      keyMap[olc::OEM_1] = "OEM_1";
      keyMap[olc::OEM_2] = "OEM_2";
      keyMap[olc::OEM_3] = "OEM_3";
      keyMap[olc::OEM_4] = "OEM_4";
      keyMap[olc::OEM_5] = "OEM_5";
      keyMap[olc::OEM_6] = "OEM_6";
      keyMap[olc::OEM_7] = "OEM_7";
      keyMap[olc::OEM_8] = "OEM_8";
      keyMap[olc::CAPS_LOCK] = "CAPS_LOCK";
      keyMap[olc::ENUM_END] = "ENUM_END";
	}

    std::string displayString;
	std::string currentlyPressedMousedButtons;

	std::map<olc::Key,std::string> keyMap;

};
