#ifndef RAY_H
#define RAY_H

#include "Vector3D.h"
#include "Sphere.h"

struct Ray
{
	//constructor
	Ray(Vector3D s, Vector3D d);
	//intersection
	bool intersection(Sphere s);
    Vector3D src;   //source
    Vector3D dir;   //direction
    Vector3D inter1, inter2;
};

#endif // RAY_H
