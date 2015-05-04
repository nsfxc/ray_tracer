#include "Vector3D.h"

//constructors
Vector3D::Vector3D()
{
    x=0;
    y=0;
    z=0;
}
Vector3D::Vector3D(double x, double y, double z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

//get coordinate x y z
double Vector3D::get_x() const
{
    return x;
}
double Vector3D::get_y() const
{
    return y;
}
double Vector3D::get_z() const
{
    return z;
}

//set coordinate x y z
//void Vector3D::set_x(double x)
//{
//    this->x = x;
//}
//void Vector3D::set_y(double y)
//{
//    this->y = y;
//}
//void Vector3D::set_z(double z)
//{
//    this->z = z;
//}
void Vector3D::set(double x,double y,double z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

//copy the coordinates of a vector
void Vector3D::copy(const Vector3D& v)
{
    x = v.get_x();
    y = v.get_y();
    z = v.get_z();
}

//linear multiplication overload *= : vector*=number
void Vector3D::operator*=(double l)
{
    set(x*l, y*l, z*l);
}

//constants
const Vector3D Vector3D::ZERO = Vector3D(0, 0, 0);
const Vector3D Vector3D::ONE = Vector3D(1, 1, 1);
const Vector3D Vector3D::EX = Vector3D(1, 0, 0);
const Vector3D Vector3D::EY = Vector3D(0, 1, 0);
const Vector3D Vector3D::EZ = Vector3D(0, 0, 1);

//overload operator + - *
Vector3D operator+(const Vector3D& lv, const Vector3D& rv)
{
    return Vector3D(lv.get_x()+rv.get_x(),
                    lv.get_y()+rv.get_y(),
                    lv.get_z()+rv.get_z());
}
Vector3D operator-(const Vector3D& lv, const Vector3D& rv)
{
    return Vector3D(lv.get_x()-rv.get_x(),
                    lv.get_y()-rv.get_y(),
                    lv.get_z()-rv.get_z());
}
Vector3D operator*(const double &d, const Vector3D &v)
{
    return Vector3D(d*v.get_x(), d*v.get_y(), d*v.get_z());
}
double operator*( const Vector3D &v1, const Vector3D &v2)
{
    return(v1.get_x()*v2.get_x()+
           v1.get_y()*v2.get_y()+
           v1.get_z()*v2.get_z());
}
//overload operator == < to overload < for sphere
bool operator==(const Vector3D& lv, const Vector3D& rv)
{
    return (lv.get_x() == rv.get_x() &&
            lv.get_y() == rv.get_y() &&
            lv.get_z() == rv.get_z());
}
bool operator<(const Vector3D& lv, const Vector3D& rv)
{
    if(lv.get_x()==rv.get_x())
        if(lv.get_y()==rv.get_y())
            if(lv.get_z()==rv.get_z())
                return false;
            else return lv.get_z()<rv.get_z();
        else return lv.get_y()<rv.get_y();
    else return lv.get_x()<rv.get_x();
}

//overload operator << for ostream
std::ostream& operator<<(std::ostream &out, const Vector3D &v)
{
    return out << "(" << v.get_x() << ", " << v.get_y() << ", " << v.get_z() << ")";
}
