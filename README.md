
Uses javidx9's [olc::PixelGameEngine](https://github.com/OneLoneCoder/olcPixelGameEngine) to do a bunch of stuff. This repository will be used to house projects I did in order to learn how to use the olc::PixelGameEngine.

# Running and compiling on Linux:
## 1. Install dependencies:
    1. sudo apt update
    2. sudo apt install build-essential libglu1-mesa-dev libpng-dev git cmake

## 2. To compile:
    1. mkdir build
    2. cd build
    3. cmake .. && make

## 3. Executables will be located in the build directory. Inside the build directory there will be a parallel directory for each project directory in olc_Stuff.
    1. For example, from build: ./1_UserInputDisplay/UserInputDisplay