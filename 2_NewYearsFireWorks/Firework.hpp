#ifndef __FIREWORK_HPP__
#define __FIREWORK_HPP__

#define OLC_PGE_APPLICATION

#include "olcPixelGameEngine.h"

struct FireWork
{

    FireWork( olc::vi2d initialPos = olc::vi2d(0,0), olc::vi2d initialVel = olc::vi2d(0,0) ): 
    color( olc::WHITE ),
    numExplode(5)
    {
        pos = initialPos;
        vel = initialVel;
    }

    olc::Pixel color;
    unsigned int numExplode;

    olc::vi2d pos;
    olc::vi2d vel;

    void tick() { pos += vel; }
};

FireWork createFireWork();

#endif // __FIREWORK_HPP__