#include "MmbnDisplay.hpp"


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

void MmbnDisplay::updateGameState()
{
    
}

