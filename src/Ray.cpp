#include "Ray.h"
#include <math.h>

Ray::Ray(Vector3D s, Vector3D d){
	this -> src = s;
	this -> dir = d;
}

bool Ray::intersection(Sphere s){
	double a, b, c;
	a = dir.length();
	b = dir * (s.origin() - src);
	c = (s.origin() - src).length() - s.radius()*s.radius();
	if (b * b - 4 * a * c <  0)
		return false;
	else{
		double delta = sqrt(b * b - 4 * a * c);
		double k1 = (-b + delta)/(2*a);
		double k2 = (-b - delta)/(2*a);
		inter1 = src + (dir ^ k1);
		inter2 = src + (dir ^ k2);
		return true;
	}
}
