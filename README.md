Author: Alberto Heras
Date Created: 31 December 2020
Date Updated: 31 December 2020

Uses javidx9's [olc::PixelGameEngine](https://github.com/OneLoneCoder/olcPixelGameEngine) to do a bunch of stuff. This repository will be used to house projects I did in order to learn how to use the olc::PixelGameEngine.

Running and compiling on Linux:
1. Install dependencies:
* sudo apt update
* sudo apt install build-essential libglu1-mesa-dev libpng-dev git cmake

2. To compile:
* mkdir build
* cd build
* cmake .. && make

3. Executables will be located in the build directory. Inside the build directory there will be a parallel directory for each project directory in olc_Stuff.
* For example, from build: ./1_UserInputDisplay/UserInputDisplay