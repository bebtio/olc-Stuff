#ifndef __FIREWORK_HPP__
#define __FIREWORK_HPP__

#define OLC_PGE_APPLICATION
#include <random>
#include <vector>
#include <complex>

#include "olcPixelGameEngine.h"
#include "Entity2D.hpp"

struct FireWork : public Entity2D<double>
{

    FireWork()
    {

    }

    void initialize(olc::vd2d initialPos, 
                    olc::vd2d initialVel, 
                    olc::vd2d initialAcc,
                    int delayTicks, 
                    int explodeTicks )
    {
        
        setPos(initialPos);
        setVel(initialVel);
        setAcc(initialAcc);
        fuseDelayTicks = delayTicks;
        explosionTicks = explodeTicks;
        createFlares(5,20);
    }

    void tick( ) 
    {
        update();
        fuseDelayTicks--;

        handleFlares(acc.y);
  
    }

    bool timeToExplode( )
    {
        if( fuseDelayTicks > 0)
        {
            return(false);
        }
        else
        {
            return( true );
        }
    }

    bool ExplosionFinished()
    {
        if( explosionTicks < 0 )
        {
            return( true );
        }
        else
        {
            return( false );
        }
    }

    void createFlares( double velMag, int numFlares )
    {
        std::complex<double> flareVelocities;

        double angle( 2*M_PI / numFlares );
        flarePos.resize(numFlares);
        flareVel.resize(numFlares);

        for( int i = 0; i < numFlares; ++i )
        {
            flareVelocities = std::polar( velMag, angle*i );
            flareVel.at(i) = olc::vd2d( flareVelocities.real(), flareVelocities.imag() );
            flarePos.at(i) = olc::vd2d(0,0);
        }

    }

    void handleFlares(double vAcc)
    {
        if( fuseDelayTicks <= 0 )
        {
            vel = olc::vd2d(0,0);
            
            for( unsigned int i = 0; i < flarePos.size(); ++i )
            {
                if(flarePos.at(i).x == 0 && flarePos.at(i).y == 0)
                {
                    flarePos.at(i) = getPos();
                }
                else
                {
                    flarePos.at(i)   += flareVel.at(i);
                    flareVel.at(i).y += vAcc;
                }
            }
            explosionTicks--;
        }
    }
    
    int fuseDelayTicks;
    int explosionTicks;

    std::vector<olc::vd2d> flareVel;
    std::vector<olc::vd2d> flarePos;
};


template <class T>
T getRandomNumberInRange( T start, T end)
{
    T number;
    std::random_device rd; // obtain a random number from hardware
    std::mt19937 gen(rd()); // seed the generator
    std::uniform_real_distribution<> distr(start, end);
    number = distr(gen);

    return(number);
}

#endif // __FIREWORK_HPP__