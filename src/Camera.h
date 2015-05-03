#ifndef CAMERA_H
#define CAMERA_H

#include "Vector3D.h"

class Camera
{
    public:
        //constructor
        Camera(Vector3D e, Vector3D t, Vector3D u, double w, double h);
    private:
        double w,h;     //width, height
        Vector3D e,t,u; //eye, target, up
};

#endif // CAMERA_H
