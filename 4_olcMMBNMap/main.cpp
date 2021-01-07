#include <iostream>
#define OLC_PGE_APPLICATION

#include "MmbnDisplay.hpp"

int main( int argc, char** argv )
{

    MmbnDisplay display;

    display.Construct(240,160,1,1);
    display.Start();
    std::cout << "HELLO WORLD" << std::endl;

    return(0);
}
