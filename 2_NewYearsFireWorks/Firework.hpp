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
                    int explodeTicks,
                    int numFlares,
                    double flareVel )
    {
        
        setPos(initialPos);
        setVel(initialVel);
        setAcc(initialAcc);
        fuseDelayTicks = delayTicks;
        explosionTicks = explodeTicks;
        createFlares( numFlares,flareVel );
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
        flares.resize(numFlares);

        for( int i = 0; i < numFlares; ++i )
        {
            flareVelocities = std::polar( velMag, angle*i );
            flares.at(i).setVel( olc::vd2d( flareVelocities.real(), flareVelocities.imag() ) );
            flares.at(i).setPos( olc::vd2d( 0,0 ) );
        }

    }

    void handleFlares(double vAcc)
    {
        if( fuseDelayTicks <= 0 )
        {
            vel = olc::vd2d(0,0);
            
            for( unsigned int i = 0; i < flares.size(); ++i )
            {
                if(flares.at(i).getPos().x == 0 && flares.at(i).getPos().y == 0)
                {
                    flares.at(i).setPos( getPos() );
                    flares.at(i).setAcc( getAcc() );
                }
                else
                {
                    flares.at(i).update();
                }
            }
            explosionTicks--;
        }
    }
    
    int fuseDelayTicks;
    int explosionTicks;

    std::vector<FireWork> flares;

};


template <class T>
T getRandomNumberInRange( T start, T end)
{
    double f = (double)rand() / RAND_MAX;
    T number = start + f*(end-start);

    return(number);
}

#endif // __FIREWORK_HPP__