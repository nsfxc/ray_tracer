#include <iostream>
#include "Ray.h"
#include "Vector3D.h"

Ray::Ray(Vector3D s, Vector3D d)
{
    src = s;
    dir = d;
}

//overload << for ostream
std::ostream& operator<<(std::ostream &out, const Ray &r)
{
    return out << r.src << " >>> " << r.dir;
}
