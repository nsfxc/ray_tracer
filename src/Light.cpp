#include "Light.h"

//constructor
Light::Light(Vector3D s, Color c)
{
    this->s = s;
    this->c = c;
}

//gets
Color Light::color() const
{
    return c;
}
Vector3D Light::source() const
{
    return s;
}
