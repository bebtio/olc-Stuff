#include <iostream>
#include "FireWorksDisplay.hpp"

int main( int argc, char** argv )
{
    FireWork fw;

    FireWorksDisplay fwd;

    if( fwd.Construct(256,256,4,4) )
    {
        fwd.Start();
    }
    
    std::cout << "HAPPY NEW YEAR" << std::endl;

    return(0);
    
}