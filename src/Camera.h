#ifndef CAMERA_H
#define CAMERA_H

#include <cstddef>
#include "Vector3D.h"


class Camera
{
    public:
        //constructor
        Camera(Vector3D e, Vector3D t, Vector3D u, double w, double h);

        //gets
        Vector3D eye() const;
        Vector3D target() const;
        Vector3D up() const;
        double width() const;
        double height() const;

    private:
        double w,h;     //width, height of real size thus in double
        Vector3D e,t,u; //eye, target, up : up NORMALIZED
};

//left : the other direction of the target plan of camera normalized and perpendicular to up
Vector3D left(const Camera &c);

#endif // CAMERA_H
