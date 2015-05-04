#ifndef CAMERA_H
#define CAMERA_H

#include <cstddef>
#include "Vector3D.h"

class Camera
{
    public:
        //constructor
        Camera(Vector3D e, Vector3D t, Vector3D u, size_t w, size_t h);
    private:
        size_t w,h;     //width, height
        Vector3D e,t,u; //eye, target, up
};

#endif // CAMERA_H
