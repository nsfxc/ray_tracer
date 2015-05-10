#include <cstddef>
#include "Camera.h"
#include "Vector3D.h"

//constructor
Camera::Camera(Vector3D e, Vector3D t, Vector3D u, double w, double h)
{
    this->e = e;
    this->t = t;
    this->u = normalize(u);
    this->w = w;
    this->h = h;
}

//gets
Vector3D Camera::eye() const
{
    return e;
}
Vector3D Camera::target() const
{
    return t;
}
Vector3D Camera::up() const
{
    return u;
}
double Camera::width() const
{
    return w;
}
double Camera::height() const
{
    return h;
}

//left : the other direction of the target plan of camera NORMALIZED and perpendicular to up
Vector3D left(const Camera &c)
{
    Vector3D nrm = c.target()-c.eye();//vector normal of target plan
    double u1 = c.up().get_x(), u2 = c.up().get_y(), u3 = c.up().get_z(),
           v1 = nrm.get_x(),    v2 = nrm.get_y(),    v3 = nrm.get_z();
    return normalize(Vector3D(u2*v3-u3*v2, u3*v1-u1*v3, u1*v2-u2*v1));
}
