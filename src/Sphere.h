#ifndef SPHERE_H
#define SPHERE_H

#include "Vector3D.h"
#include "Color.h"

class Sphere
{
    public:
        //constructors
        Sphere(Vector3D o, double r, Color c);
        Sphere(double x, double y, double z, double r, Color c);

        //get elements
        Vector3D origin() const;
        double radius() const;
        Color color() const;

    private:
        double r;       //radius
        Vector3D o;     //origin
        Color c;        //color
};

//overload < == for Sphere to use set
bool operator<(const Sphere &ls, const Sphere &rs);
//bool operator==(const Sphere &ls, const Sphere &rs);

#endif // SPHERE_H
