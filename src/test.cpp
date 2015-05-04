#include <utility>
#include <iostream>
#include <cassert>
#include "ray_tracer.h"
#include "Ray.h"
#include "Vector3D.h"
#include "Sphere.h"
#include "Scene.h"

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
    //test of Vector3D
    Vector3D u, v(2,3,4.5), w;
    w.copy(v);
    v*=2;
    u.set(1,2,3);
    display(u);
    display(v);
    display(u+2*v);
    cout<<u*v<<endl;
    display(w);
    display(u+v);
    display(u-w);
//    u.set_y(42.42);
    display(u);
    display(Vector3D::EY);
    //cout<<sizeof(Scene);

    //test of sphere scene
    Scene sc;
    Sphere s1(v,3.5, BLACK);
    assert(sc.add(s1));
    cout<<"s1 added\n";
    display(s1);
    Sphere s2(1, 2, 3.7, 4.2, RED);
    assert(sc.add(s2));
    cout<<"s2 added\n";
    display(s2);
    Sphere s3(4, 6, 9, 3.5, BLACK);
    assert(!sc.add(s3));
    cout<<"s3 can\'t be added\n";
    display(s3);

    //test intersect
    Sphere s4(1, 1, 1, 2, GREEN);
    Ray r1(Vector3D(6, 1, 1), Vector3D(-1, 0, 0));
    pair<Vector3D, bool> p1 = intersect(r1, s4);
    assert(p1.second);
    cout<<"\nsphere : \n"<<s4<<"\nand ray : \n"<<r1<<"\nhas intersection : \n";
    display(p1.first);

    Ray r2(Vector3D(6, 3, 1), Vector3D(-1, 0, 0));
    pair<Vector3D, bool> p2 = intersect(r2, s4);
    assert(p2.second);
    cout<<"\nsphere : \n"<<s4<<"\nand ray : \n"<<r2<<"\nhas intersection : \n";
    display(p2.first);

    Ray r3(Vector3D(6, 4, 1), Vector3D(-1, 0, 0));
    pair<Vector3D, bool> p3 = intersect(r3, s4);
    assert(!p3.second);
    cout<<"\nsphere : \n"<<s4<<"\nand ray : \n"<<r3<<"\nhas no intersection.\n";

    return 0;
}
