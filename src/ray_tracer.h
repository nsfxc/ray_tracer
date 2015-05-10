#ifndef RAY_TRACER_H
#define RAY_TRACER_H

#include <utility>
#include "Camera.h"
#include "Color.h"
#include "EasyBMP.h"
#include "Light.h"
#include "Ray.h"
#include "Sphere.h"
#include "Vector3D.h"
#include "Scene.h"

//determine the intersection of a ray and a sphere, return the first contact if exists.
std::pair<Vector3D, bool>  intersect(const Ray &r, const Sphere &s);

//Phong reflection model : color of a point p of a sphere s
Color PRM_color_render(const Vector3D &p, const Sphere &s, const Light &l,const Vector3D &eye);

//photo : generate an image(BMP object) size w*h of a sphere s
bool photo_sphere(int w, int h, const Camera &c, const Sphere &s, const Light &l, BMP& b);
bool photo_scene(int w, int h, const Camera &c, const Scene &s, const Light &l, BMP& b);
#endif // RAY_TRACER_H
