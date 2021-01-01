#ifndef __ENTITY2D_HPP__
#define __ENTITY2D_HPP__

#include "olcPixelGameEngine.h"

template <class T>
class Entity2D
{

public:
    Entity2D() {}
    ~Entity2D() {}

    void reset()
    {
        pos = olc::v2d_generic<T>(0,0);
        vel = olc::v2d_generic<T>(0,0);
        acc = olc::v2d_generic<T>(0,0);
    }

    void setPos( olc::v2d_generic<T> pos ) { this->pos = pos; }
    void setVel( olc::v2d_generic<T> vel ) { this->vel = vel; }
    void setAcc( olc::v2d_generic<T> acc ) { this->acc = acc; }

    olc::v2d_generic<T> getPos() { return( this->pos ); }
    olc::v2d_generic<T> getVel() { return( this->vel ); }
    olc::v2d_generic<T> getAcc() { return( this->acc ); }

    void update()
    {
        pos += vel;
        vel += acc;
    }

protected:
    olc::v2d_generic<T> pos;
    olc::v2d_generic<T> vel;
    olc::v2d_generic<T> acc;
};

#endif // __ENTITY2D_HPP__
