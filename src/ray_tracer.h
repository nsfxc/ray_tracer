#ifndef RAY_TRACER_H
#define RAY_TRACER_H

#include <utility>
#include "Vector3D.h"
#include "Sphere.h"
#include "Ray.h"

//determine the intersection of a ray and a sphere, return the first contact if exists.
std::pair<std::pair<Vector3D,Vector3D>, bool>  intersect(const Ray &r, const Sphere &s);

#endif // RAY_TRACER_H
