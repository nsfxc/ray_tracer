#include <cmath>
#include <utility>
#include <set>
#include "Camera.h"
#include "Color.h"
#include "EasyBMP.h"
#include "Light.h"
#include "Ray.h"
#include "ray_tracer.h"
#include "Sphere.h"
#include "Vector3D.h"
#include "Scene.h"

using namespace std;
//determine the intersection of a ray and a sphere, return the first contact if exists.
pair<Vector3D, bool>  intersect(const Ray &r, const Sphere &s)
{
    double  s1 = r.src.get_x()-s.origin().get_x(), d1 = r.dir.get_x(),
            s2 = r.src.get_y()-s.origin().get_y(), d2 = r.dir.get_y(),
            s3 = r.src.get_z()-s.origin().get_z(), d3 = r.dir.get_z(),
            rr = s.radius(),
            a = d1*d1+d2*d2+d3*d3,
            b = 2*(d1*s1+d2*s2+d3*s3),
            c = s1*s1+s2*s2+s3*s3-rr*rr;
            // solve a*x*x + b*x +c = 0
            if(b*b<4*a*c)  //no solution -> no contact
                return pair<Vector3D, bool>(Vector3D::ZERO, false);
            else{           //solution -> possible contact
                double x = (-b-sqrt(b*b-4*a*c))/(2*a); //solution
                if(x<0)     //source of ray in the sphere or opposite direction
                    return pair<Vector3D, bool>(Vector3D::ZERO, false);
                else        //return first intersection
                    return pair<Vector3D, bool>(r.src+x*r.dir, true);
            }
}

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
    if(n*l<=0)  //no light shall come
        return camb*kamb*cobj;
    Vector3D r = normalize(2*(n*l)*n - l);
    if (r*v > 1)
    	cout << r * v <<' ';
    if(r*v<=0)  //power undefined for negative value
        return min(1.0,camb*kamb*cobj + katt*clgt*kdfs*cobj*(n*l));
    else        //normal
        return  min(1.0,camb*kamb*cobj + katt*clgt*(kdfs*cobj*( n*l ) + pow(kspc*cspc*(r*v), shn)));
}



//Phong reflection model : color of a point p of a sphere s
Color PRM_color_render(const Vector3D &p, const Sphere &s, const Light &l,const Vector3D &eye)
{
    double clgt[3],cobj[3],cres[3];     //RGB with range [0, 1]
    clgt[0] = color_red(l.color())/255.0;       //R
    clgt[1] = color_green(l.color())/255.0;     //G
    clgt[2] = color_blue(l.color())/255.0;      //B
    cobj[0] = color_red(s.color())/255.0;       //R
    cobj[1] = color_green(s.color())/255.0;     //G
    cobj[2] = color_blue(s.color())/255.0;      //B

    Vector3D vn = normalize(p-s.origin()),
             vl = normalize(l.source()-p),
             vv = normalize(eye-p);

    for(int i=0;i<3;i++){
        cres[i] = RPM_monochrome_render(clgt[i],camb_,cobj[i],cspc_,kamb_,kdfs_,kspc_,katt_,shn_,vn,vl,vv);
    }
    unsigned char c1 = (unsigned char)(int)(cres[0]*255);
    unsigned char c2 = (unsigned char)(int)(cres[1]*255);
    unsigned char c3 = (unsigned char)(int)(cres[2]*255);
    return color(c1,c2,c3);
}

Color sphereInScene(const Vector3D &p, const Sphere &s, const Light &l,const Vector3D &eye,const Scene &sc){
	set<Sphere>::iterator ss;
	bool f = false;
	pair<Vector3D, bool> i;
	for(ss = sc.getSpheres().begin();ss!=sc.getSpheres().end();ss++){
		i = intersect(Ray(l.source(),p-l.source()),*ss);
		if (i.second)
			if (norm(i.first - l.source()) < norm(l.source() - p))
				f = true;
	}
	if (f){
		kdfs_ = 0.1;
		return PRM_color_render(p,s,l,eye);
	}
	else{
		kdfs_ = 0.7;
		return PRM_color_render(p,s,l,eye);
	}
}
//photo : generate an image(BMP object) size w*h of a sphere s
bool photo_sphere(int w, int h, const Camera &c, const Sphere &s, const Light &l, BMP &b)
{
    if(!(w>0&&h>0))return false;
    if(!b.SetSize(w, h))return false;
    if(!b.SetBitDepth(24))return false;

    Vector3D px, c_left = left(c), c_up = c.up(), c_eye = c.eye(), c_target = c.target();   //pixel and left/up direction
    double dw = c.width()/w, dh = c.height()/h; //should be greater than std::numeric_limits<double>::min()
    pair<Vector3D, bool> p; //to store the result of intersection
    Color color;            //color for temporarily storage in the loop

    for(int i=0;i<w;i++)
        for(int j=0;j<h;j++)
    {
        px = c_target+((w/2-i)*dw)*c_left+((h/2-j)*dh)*c_up;  //set pixel
        p = intersect(Ray(c_eye,px-c_eye), s);              //get intersection result
        if(!p.second)
        {
            b(i,j)->Red = 0xff;
            b(i,j)->Green = 0xff;
            b(i,j)->Blue = 0xff;
        }
        else
        {
            color = PRM_color_render(p.first, s, l, c.eye());
            b(i,j)->Red = color_red(color);
            b(i,j)->Green = color_green(color);
            b(i,j)->Blue = color_blue(color);
        }
    }
    return true;
}

bool photo_scene(int w, int h, const Camera &c, const Scene &sc, const Light &l, BMP &b){
	if(!(w>0&&h>0))return false;
	if(!b.SetSize(w, h))return false;
	if(!b.SetBitDepth(24))return false;
	Vector3D px, c_left = left(c), c_up = c.up(), c_eye = c.eye(), c_target = c.target();   //pixel and left/up direction
	double dw = c.width()/w, dh = c.height()/h; //should be greater than std::numeric_limits<double>::min()
	pair<Vector3D, bool> p; //to store the result of intersection
	Color color;            //color for temporarily storage in the loop
	for(int i=0;i<w;i++)
		for(int j=0;j<h;j++)
		{
			px = c_target+((w/2-i)*dw)*c_left+((h/2-j)*dh)*c_up;  //set pixel
			bool f = true;
			Vector3D inter;
			set<Sphere>::iterator s;
			Sphere si(0,0,0,0,0);
			for(s = (sc.getSpheres()).begin();s!=(sc.getSpheres()).end();s++){
				p = intersect(Ray(c_eye,px-c_eye), *s);
				if (p.second)
					if (f || norm(p.first - c_eye)<norm(inter -  c_eye))
					{
						inter = p.first;
						si = *s;
						f = false;
					}

			}             //get intersection result
			if(f)
			{
				b(i,j)->Red = 0xff;
				b(i,j)->Green = 0xff;
				b(i,j)->Blue = 0xff;
			}
			else
			{
				color = sphereInScene(inter, si, l, c.eye(),sc);
				b(i,j)->Red = color_red(color);
				b(i,j)->Green = color_green(color);
				b(i,j)->Blue = color_blue(color);
			}
		}
	return true;
}
