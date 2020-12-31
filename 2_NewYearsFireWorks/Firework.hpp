#ifndef __FIREWORK_HPP__
#define __FIREWORK_HPP__

#define OLC_PGE_APPLICATION
#include <random>

#include "olcPixelGameEngine.h"

struct FireWork
{

    FireWork()
    {

    }

    void initialize(olc::vi2d initialPos = olc::vi2d(0,0), olc::vi2d initialVel = olc::vi2d(0,0) )
    {
        pos = initialPos;
        vel = initialVel;
    }

    void tick( double vAcc ) 
    {
        pos   += vel;
        vel.y += vAcc;
    }

    bool timeToExplode( int currTicks )
    {
        return( false );
    }

    olc::vd2d pos;
    olc::vd2d vel;
};

FireWork createFireWork();

template <class T>
T getRandomNumberInRange( T start, T end)
{
    T number;
    std::random_device rd; // obtain a random number from hardware
    std::mt19937 gen(rd()); // seed the generator
    std::uniform_int_distribution<> distr(start, end);

    number = distr(gen);

    return(number);
}

#endif // __FIREWORK_HPP__