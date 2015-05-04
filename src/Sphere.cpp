#include <iomanip>
#include <iostream>
#include "Sphere.h"
#include "Color.h"
#include "Vector3D.h"
#include <GL/glut.h>
#include <SOIL/SOIL.h>

//constructors
Sphere::Sphere(Vector3D o, double r, Color c)
{
    this->o = o;
    this->r = r;
    this->c = c;
}
Sphere::Sphere(double x, double y, double z, double r, Color c)
{
    this->o.set(x, y, z);
    this->r = r;
    this->c = c;
}

//get elements
Vector3D Sphere::origin() const
{
    return o;
}
double Sphere::radius() const
{
    return r;
}
Color Sphere::color() const
{
    return c;
}

//overload < == for Sphere to use set
bool operator<(const Sphere &ls, const Sphere &rs)
{
    if(ls.origin()==rs.origin())
        if(ls.radius()==rs.radius())
            if(ls.color()==rs.color())
                return false;
            else return ls.color()<rs.color();
        else return ls.radius()<rs.radius();
    else return ls.origin()<rs.origin();
}
//bool operator==(const Sphere &ls, const Sphere &rs)
//{
//    return (ls.origin()==rs.origin()
//            && ls.radius()==rs.radius()
//            && ls.color()==rs.color());
//}

//overload operator << for ostream

void Sphere::display(){
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	// window size
	glutInitWindowSize(400,350);
	// create the window
	glutCreateWindow("Sphere Rotating Animation");
	glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
	glClearColor(0.0,0.0,0.0,0.0);
	//Assign  the function used in events
	glMatrixMode(GL_MODELVIEW);
	// clear the drawing buffer.
	glClear(GL_COLOR_BUFFER_BIT);
	// clear the identity matrix.
	glLoadIdentity();
	// Red color used to draw.
	glColor3f(0.8, 0.2, 0.1);
	// scaling transfomation
	glScalef(1.0,1.0,1.0);
	// built-in (glut library) function , draw you a sphere.
	glutSolidSphere(r,o.get_x(),o.get_y());
	// Flush buffers to screen
	glFlush();
}

std::ostream& operator<<(std::ostream &out, const Sphere &s)
{
    return out << s.origin() << " [r = " << s.radius() << "] " << std::hex << s.color() << std::dec;
}
