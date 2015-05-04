#include <cmath>
#include <utility>
#include "Vector3D.h"
#include "Sphere.h"
#include "Ray.h"

using namespace std;
//determine the intersection of a ray and a sphere, return the first contact if exists.
pair<pair<Vector3D,Vector3D>, bool>  intersect(const Ray &r, const Sphere &s)
		{
	double  s1 = r.src.get_x()-s.origin().get_x(), d1 = r.dir.get_x(),
			s2 = r.src.get_y()-s.origin().get_y(), d2 = r.dir.get_y(),
			s3 = r.src.get_z()-s.origin().get_z(), d3 = r.dir.get_z(),
			rr = s.radius(),
			a = d1*d1+d2*d2+d3*d3,
			b = 2*(d1*s1+d2*s2+d3*s3),
			c = s1*s1+s2*s2+s3*s3-rr*rr;
	pair<Vector3D,Vector3D> intsecs;
	// solve a*x*x + b*x +c = 0
			if(b*b<4*a*c)  //no solution -> no contact
				return pair<pair<Vector3D,Vector3D>,bool>(intsecs, false);
			else{           //solution -> possible contact
				double x = (-b-sqrt(b*b-4*a*c))/(2*a); //first solution
				if(x > 0)
					intsecs.first = r.src + x * r.dir;
				intsecs.second = intsecs.first;
				x = (-b + sqrt(b*b - 4*a*c))/(2*a); // second solution
				if(x > 0)
					intsecs.second = r.src + x*r.dir;
				return 	pair<pair<Vector3D,Vector3D>,bool>(intsecs,true);
			}
		}

//Phong reflection model
