#ifndef VECTOR3D_H
#define VECTOR3D_H

#include <iostream>

class Vector3D
{
public:
    //constructors
    Vector3D();     //construct (0,0,0)
    Vector3D(double x, double y, double z);

    //get coordinate x y z
    double get_x() const;
    double get_y() const;
    double get_z() const;

//    //set coordinate x y z
//    void set_x(double x);
//    void set_y(double y);
//    void set_z(double z);
    void set(double x,double y,double z);

    //copy the coordinates of a vector
    void copy(const Vector3D& v);

    //linear multiplication overload *= : vector*=number
    void operator*=(double l);

    //constants
static const Vector3D ZERO;
static const Vector3D ONE;
static const Vector3D EX;
static const Vector3D EY;
static const Vector3D EZ;

private:
    double x,y,z;
};

//overload operator + - * /
Vector3D operator+(const Vector3D& lv, const Vector3D& rv);
Vector3D operator-(const Vector3D& lv, const Vector3D& rv);
Vector3D operator*(const double &d, const Vector3D &v);     //scalar multiplication
Vector3D operator/(const Vector3D &v, const double &d);     //scalar division
double operator*( const Vector3D &v1, const Vector3D &v2);  //scalar product

//norm normalize
double norm(const Vector3D &v);
Vector3D normalize(const Vector3D &v);

//overload operator == < to overload < for sphere
bool operator==(const Vector3D& lv, const Vector3D& rv);
bool operator<(const Vector3D& lv, const Vector3D& rv);

//overload operator << for ostream
std::ostream& operator<<(std::ostream &out, const Vector3D &v);


#endif // VECTOR3D_H
