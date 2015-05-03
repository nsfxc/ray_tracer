#include <iostream>
#include <cassert>
#include "Vector3D.h"
#include "Sphere.h"
#include "Scene.h"

using namespace std;

void display(const Vector3D &v)
{
    cout<<v.get_x()<<" "
        <<v.get_y()<<" "
        <<v.get_z()<<endl;
}

void display(const Sphere &s)
{
    display(s.origin());
    cout<<" "<<s.radius()
        <<" "<<s.color()<<endl;
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
    display(w);
    display(u+v);
    display(u-w);
    u.set_y(42.42);
    display(u);
    display(V3_EY);
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
//    Sphere s3(4, 6, 9, 3.5, BLACK);
//    assert(sc.add(s3));     //should fail
//    cout<<"s3 added\n";
//    display(s3);

    return 0;
}
