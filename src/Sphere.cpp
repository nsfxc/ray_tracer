#include "Sphere.h"
#include "Color.h"
#include "Vector3D.h"

//constructors
Sphere::Sphere(Vector3D o, double r, Color c)
{
    this->o = o;
    this->r = r;
    this->c = c;
}
Sphere::Sphere(double x, double y, double z, double r, Color c)
{
    this->o.set(x, y, z);
    this->r = r;
    this->c = c;
}

//get elements
Vector3D Sphere::origin() const
{
    return o;
}
double Sphere::radius() const
{
    return r;
}
Color Sphere::color() const
{
    return c;
}

//overload < == for Sphere to use set
bool operator<(const Sphere &ls, const Sphere &rs)
{
    if(ls.origin()==rs.origin())
        if(ls.radius()==rs.radius())
            if(ls.color()==rs.color())
                return false;
            else return ls.color()<rs.color();
        else return ls.radius()<rs.radius();
    else return ls.origin()<rs.origin();
}
bool operator==(const Sphere &ls, const Sphere &rs)
{
    return (ls.origin()==rs.origin()
            && ls.radius()==rs.radius()
          && ls.color()==rs.color());
}

