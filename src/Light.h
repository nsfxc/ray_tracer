#ifndef LIGHT_H
#define LIGHT_H

#include "Vector3D.h"
#include "Color.h"
class Light
{
    public:
        //constructor
        Light(Vector3D s,Color c);
        //return color and source
        Color color()const;
        Vector3D source()const;
    private:
        Vector3D s; //source
        Color c;    //color
};

#endif // LIGHT_H
