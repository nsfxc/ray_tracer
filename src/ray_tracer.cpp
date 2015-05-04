#include <cmath>
#include <utility>
#include "Vector3D.h"
#include "Sphere.h"
#include "Ray.h"
#include "Color.h"
#include "Light.h"

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
//parameters to be configured later
    double kamb_ = 0.2, kdfs_ = 0.7, kspc_ = 1, katt_ = 1, shn_ = 200,   //coeffs
           camb_ = 1, cspc_ = 1;                                      //ambient and specular light : white

//for R G B
//light, ambient ,object, specular color between [0, 1]
//ambient, diffusion, specular, attenuation coefficient between [0, 1]
//shininess coefficient | normal, to-light-source, view vector, suppose already normalized
//reference : http://www.cpp-home.com/tutorials/211_1.htm
double RPM_monochrome_render(double clgt, double camb, double cobj, double cspc,
                            double kamb, double kdfs, double kspc, double katt,
                            double shn, Vector3D n, Vector3D l, Vector3D v)
{
    Vector3D r = 2*(n*l)*n - l;
    return  camb*kamb*cobj + katt*clgt*(kdfs*cobj*( n*l ) + pow( kspc*cspc*(r*v), shn));
}

//Phong reflection model : color of a point p of a sphere s
Color PRM_color_render(const Vector3D &p, const Sphere &s, const Light &l,const Vector3D &eye)
{
    double clgt[3],cobj[3],cres[3];     //RGB with range [0, 1]
    clgt[0] = (l.color()/0x10000)/255.0;        //R
    clgt[1] = ((l.color()/0x100)%0x100)/255.0;  //G
    clgt[2] = (l.color()%0x100)/255.0;          //B
    cobj[0] = (s.color()/0x10000)/255.0;        //R
    cobj[1] = ((s.color()/0x100)%0x100)/255.0;  //G
    cobj[2] = (s.color()%0x100)/255.0;          //B

    Vector3D vn = normalize(p-s.origin()),
             vl = normalize(l.source()-p),
             vv = normalize(eye-p);

    for(int i=0;i<3;i++)
        cres[i] = RPM_monochrome_render(clgt[i],camb_,cobj[i],cspc_,kamb_,kdfs_,kspc_,katt_,shn_,vn,vl,vv);
    return (Color)(((unsigned long)round(cres[0]*255))*0x10000+((unsigned long)round(cres[1]*255))*0x100+((unsigned long)round(cres[1]*255)));
}



