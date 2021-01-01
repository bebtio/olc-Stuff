#include <iostream>
#include "FireWorksDisplay.hpp"
#include "Entity2D.hpp"
int main( int argc, char** argv )
{
    Entity2D<int> e;
    FireWorksDisplay fwd;

    if( fwd.Construct(1024,1024,4,4) )
    {
        fwd.Start();
    }
    
    std::cout << "HAPPY NEW YEAR" << std::endl;

    return(0);
    
}