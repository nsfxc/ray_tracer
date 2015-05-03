#ifndef VECTOR3D_H
#define VECTOR3D_H


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

    //set coordinate x y z
    void set_x(double x);
    void set_y(double y);
    void set_z(double z);
    void set(double x,double y,double z);

    //copy the coordinates of a vector
    void copy(const Vector3D& v);

    //linear multiplication overload *= : vector*=number
    void operator*=(double l);

    double distance(Vector3D v);
    double length();

    //constants
static const Vector3D ZERO;
static const Vector3D ONE;
static const Vector3D EX;
static const Vector3D EY;
static const Vector3D EZ;

private:
    double x,y,z;
};

//overload operator + -
Vector3D operator+(const Vector3D& lv, const Vector3D& rv);
Vector3D operator-(const Vector3D& lv, const Vector3D& rv);
double operator*(const Vector3D& lv, const Vector3D& rv);
Vector3D operator^(const Vector3D& lv, double k);

//overload operator == < to overload < for sphere
bool operator==(const Vector3D& lv, const Vector3D& rv);
bool operator<(const Vector3D& lv, const Vector3D& rv);

//constants
static const Vector3D V3_ZERO = Vector3D(0, 0, 0);
static const Vector3D V3_ONE = Vector3D(1, 1, 1);
static const Vector3D V3_EX = Vector3D(1, 0, 0);
static const Vector3D V3_EY = Vector3D(0, 1, 0);
static const Vector3D V3_EZ = Vector3D(0, 0, 1);


#endif // VECTOR3D_H
