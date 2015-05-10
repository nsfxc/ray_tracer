#include <utility>
#include <iostream>
#include <iomanip>
#include <cassert>
#include "EasyBMP.h"
#include "Light.h"
#include "ray_tracer.h"
#include "Ray.h"
#include "Sphere.h"
#include "Scene.h"
#include "Vector3D.h"
#include "Color.h"

using namespace std;

void display(const Vector3D &v)
{
    cout<<"vector3D : "<<v<<endl;
}

void display(const Sphere &s)
{
    cout<<"sphere : "<<s<<endl;
}

int main()
{
//    //test color
    Color clr = 0xff4280;
    clr = color(color_red(clr), color_green(clr) , color_blue(clr));
    cout<<hex
        <<(int)color_red(clr)<<" "
        <<(int)color_green(clr)<<" "
        <<(int)color_blue(clr)<<"\n"
        <<color(color_red(clr), color_green(clr) , color_blue(clr))
        <<dec<<endl;

//    //test of Vector3D
//    Vector3D u, v(2,3,4.5), w;
//    w.copy(v);
//    v*=2;
//    u.set(3,4,0);
//    display(u);
//    cout<<norm(u)<<endl;
//    display(normalize(u));
//    cout<<norm(normalize(u))<<endl;
//    display(v);
//    display(u+2*v);
//    cout<<u*v<<endl;
//    display(w);
//    display(u+v);
//    display(u-w);
//    display(u);
//    display(Vector3D::EY);

//    //test of sphere scene
//    Scene sc;
//    Sphere s1(v,3.5, BLACK);
//    assert(sc.add(s1));
//    cout<<"s1 added\n";
//    display(s1);
//    Sphere s2(1, 2, 3.7, 4.2, RED);
//    assert(sc.add(s2));
//    cout<<"s2 added\n";
//    display(s2);
//    Sphere s3(4, 6, 9, 3.5, BLACK);
//    assert(!sc.add(s3));
//    cout<<"s3 can\'t be added\n";
//    display(s3);

//    //test intersect
//    Sphere s4(1, 1, 1, 2, GREEN);
//    Ray r1(Vector3D(6, 1, 1), Vector3D(-1, 0, 0));
//    pair<Vector3D, bool> p1 = intersect(r1, s4);
//    assert(p1.second);
//    cout<<"\nsphere : \n"<<s4<<"\nand ray : \n"<<r1<<"\nhas intersection : \n";
//    display(p1.first);
//
//    Ray r2(Vector3D(6, 3, 1), Vector3D(-1, 0, 0));
//    pair<Vector3D, bool> p2 = intersect(r2, s4);
//    assert(p2.second);
//    cout<<"\nsphere : \n"<<s4<<"\nand ray : \n"<<r2<<"\nhas intersection : \n";
//    display(p2.first);
//
//    Ray r3(Vector3D(6, 4, 1), Vector3D(-1, 0, 0));
//    pair<Vector3D, bool> p3 = intersect(r3, s4);
//    assert(!p3.second);
//    cout<<"\nsphere : \n"<<s4<<"\nand ray : \n"<<r3<<"\nhas no intersection.\n";

    //test photo PRM_color_render
    BMP bmp;
    Camera c(Vector3D(0, 0, 0), Vector3D(1, 0, 0), Vector3D(0, 0, 1), 2, 2);
    Sphere s1(3, 0, 0, 1, BLUE),s2(6,2,0,3,GREEN);
    Scene sc;
    sc.add(s1);
    sc.add(s2);
    Light l(Vector3D(0, -2, 0), 0xffffff);

    //if(!photo_sphere(600, 600, c, ss, l, bmp))
        //cout<<"Error!";
    if (!photo_scene(700,700,c,sc,l,bmp))
    	cout << "Error!";
    bmp.WriteToFile("output1.bmp");
    cout<<"done.";
    return 0;
}
