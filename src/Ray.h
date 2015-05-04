#ifndef RAY_H
#define RAY_H

#include <iostream>
#include "Vector3D.h"

struct Ray
{
        Vector3D src;   //source
        Vector3D dir;   //direction
        //constructor
        Ray(Vector3D s, Vector3D d);
};

//overload << for ostream
std::ostream& operator<<(std::ostream &out, const Ray &r);

#endif // RAY_H
