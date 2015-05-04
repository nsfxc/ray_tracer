#include "Light.h"

Light::Light(Vector3D s, Color c)
{
    this->s = s;
    this->c = c;
}

Color Light::color()const{
	return c;
}
Vector3D Light::source()const{
	return s;
}
