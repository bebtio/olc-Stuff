#include "MmbnDisplay.hpp"


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

void MmbnDisplay::updateGameState()
{
    olc::vd2d movementSpeed(playerSpeed);

    switch (currSpeed)
    {

        case FASTSTATE:
            movementSpeed = playerSpeed * 2;
            break;

        case NORMALSTATE:
            movementSpeed = playerSpeed;

        default:
            movementSpeed = playerSpeed;
            break;

    }
    currSpeed = NORMALSTATE;

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

    currDirection = STANDSTATE;
}

void MmbnDisplay::updateGraphics()
{
    		// Render graphics.
	Clear( olc::Pixel( olc::BLACK ) );
	DrawSprite((ScreenWidth() - sprite->width)/2 + pos.x,
		        (ScreenHeight() - sprite->height)/2 + pos.y,sprite);
    DrawCircle( ScreenWidth()/2.0, ScreenHeight()/2.0,1.0);
    
}
