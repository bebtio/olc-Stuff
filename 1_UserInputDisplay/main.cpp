#include <iostream>
#include "UserInputDisplay.hpp"

int main( int argc, char** argv )
{

  UserInputDisplay demo;
  if (demo.Construct(256, 240, 10, 10))
  {
    demo.Start();
  }
  
  return(0);
  
}
