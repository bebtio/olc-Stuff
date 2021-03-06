#include "MmbnDisplay.hpp"



void MmbnDisplay::initialize()
{
    // gameMap      = new olc::Sprite("../../4_olcMMBNMap/images/SecretCave.png");

    gameMap = new olc::Sprite("../../4_olcMMBNMap/images/MMBNAcdcTown.png");
    SetPixelMode( olc::Pixel::MASK );

}
//***************************************************************//
// Checks keyboard input for all game buttons.
//***************************************************************//
void MmbnDisplay::updateUserInput()
{
    updateCurrentDirectionState();
    updateCurrentButtonStates();
}

//***************************************************************//
// Checks each of the directional 4 directional keys and records
// whether they are pressed. Then sets the directionState variable
// to one of eight directions: UP, LEFT, RIGHT, DOWN, UPLEFT, DOWNLEFT,
// DOWNRIGHT, or UPRIGHT.
//***************************************************************//
void MmbnDisplay::updateCurrentDirectionState()
{
    bool upPressed   ( GetKey( olc::UP   ).bHeld );
    bool downPressed ( GetKey( olc::DOWN ).bHeld );
    bool leftPressed ( GetKey( olc::LEFT ).bHeld );
    bool rightPressed( GetKey( olc::RIGHT).bHeld );

    // Four primary directions: UP, DOWN, LEFT, RIGHT.
    if(  upPressed && !leftPressed && !downPressed && !rightPressed ) { currDirection = UPSTATE;        }
    if( !upPressed &&  leftPressed && !downPressed && !rightPressed ) { currDirection = LEFTSTATE;      }
    if( !upPressed && !leftPressed &&  downPressed && !rightPressed ) { currDirection = DOWNSTATE;      }
    if( !upPressed && !leftPressed && !downPressed &&  rightPressed ) { currDirection = RIGHTSTATE;     }

    // Four diagonals: UPLEFT, UPRIGHT, DOWNLEFT, DOWNRIGHT
    if(  upPressed &&  leftPressed && !downPressed && !rightPressed ) { currDirection = UPLEFTSTATE;    }
    if(  upPressed && !leftPressed && !downPressed &&  rightPressed ) { currDirection = UPRIGHTSTATE;   }
    if( !upPressed &&  leftPressed &&  downPressed && !rightPressed ) { currDirection = DOWNLEFTSTATE;  }
    if( !upPressed && !leftPressed &&  downPressed &&  rightPressed ) { currDirection = DOWNRIGHTSTATE; }
}

//***************************************************************//
// Checks each of they keys available to this game not related to
// direction input. Buttons are:
// TBD...
//***************************************************************//
void MmbnDisplay::updateCurrentButtonStates()
{
    bool bPressed( GetKey( olc::B ).bHeld );

    if( bPressed ) currSpeed = FASTSTATE;

}

//******************************************************************//
// Controls the game paremeters such as player positions and speed.
// That's all the controls for now.
// Probably gonna move these switch statements to a State class
// that has a function for each switch statement.
// Give each function the State type and have it change the player 
// parameters. Gonna probably need to encapsulate the position and velocity
// as a struct or something. Kind of like the entity2d class.
//******************************************************************//
void MmbnDisplay::updateGameState()
{
    // Set player movement to the the default game movement speed.
    olc::vd2d movementSpeed(playerSpeed);
    
    // Change the speed to FAST if the b button is held.
    switch (currSpeed)
    {
        case FASTSTATE:
            movementSpeed = playerSpeed * 2;
            currSpeed     = NORMALSTATE;
            break;

        case NORMALSTATE:
            movementSpeed = playerSpeed;

        default:
            movementSpeed = playerSpeed;
            break;

    }

    // Check the direction the player wants to move in.
    // Add the velocity to the position to move in that direction.
    switch (currDirection)
    {
        case UPSTATE:
            pos.y += 1.5 * movementSpeed.y * GetElapsedTime();
            break;
        
        case DOWNSTATE:
            pos.y -= 1.5 * movementSpeed.y * GetElapsedTime();
            break;
        
        case LEFTSTATE:
            pos.x += movementSpeed.x * GetElapsedTime();
            break;

        case RIGHTSTATE:
            pos.x -= movementSpeed.x * GetElapsedTime();
            break;

        case UPLEFTSTATE:
            pos += .707* movementSpeed * GetElapsedTime();
        break;

        case DOWNLEFTSTATE:
            pos.x += .707* movementSpeed.x * GetElapsedTime();
            pos.y -= .707* movementSpeed.y * GetElapsedTime();
        break;

        case UPRIGHTSTATE:
            pos.x -= .707* movementSpeed.x * GetElapsedTime();
            pos.y += .707* movementSpeed.y * GetElapsedTime();
        break;

        case DOWNRIGHTSTATE:
            pos -= .707* movementSpeed * GetElapsedTime();
        break;
    
    default:
        currDirection = STANDSTATE;
        break;
    }
    // Always change to the STANDSTATE.
    currDirection = STANDSTATE;
}

//******************************************************************//
// Updates the games graphics.
//******************************************************************//
void MmbnDisplay::updateGraphics( float dt )
{
    // Clear the screen first.
	Clear( olc::Pixel( olc::BLACK ) );

    // Draw the map.
	DrawSprite( ( ScreenWidth()  - gameMap->width  ) /2 + pos.x,
		        ( ScreenHeight() - gameMap->height ) /2 + pos.y,
                gameMap);

    // Draw the player. Currently just a dot.
    uint32_t xScreenCenter( ScreenWidth()/  2.0 );
    uint32_t yScreenCenter( ScreenHeight()/ 2.0 );

    lan.DrawAnimation( "walkLeft", olc::vi2d(xScreenCenter, yScreenCenter), dt);

}
