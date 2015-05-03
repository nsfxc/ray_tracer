#include "Camera.h"

//constructor
Camera::Camera(Vector3D e, Vector3D t, Vector3D u, double w, double h)
{
    this->e = e;
    this->t = t;
    this->u = u;
    this->w = w;
    this->h = h;
}
