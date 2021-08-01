#include <iostream>
#include "RecursiveDisplay.hpp"

int main( int argc, char* argv[] )
{

    RecursiveDisplay display;

    display.Construct(240,160,2,2);
    display.Start();
    
    std::cout << "Hello world" << std::endl;

    return(0);
}