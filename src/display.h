#ifndef DISPLAY_H
#define DISPLAY_H

#include <cmath>
#include <utility>
#include <GL/glut.h>
#include <SOIL/SOIL.h>
#include "Vector3D.h"
#include "Sphere.h"
#include "Color.h"
#include "Ray.h"

using namespace std;
//determine the intersection of a ray and a sphere, return the first contact if exists.
void drawSphere(void);
void setSphere(Sphere* k);
void reshapeFunc(int x, int y);
void idleFunc(void);
void keyboard( unsigned char key, int x, int y );
void displaySphere();


#endif // RAY_TRACER_H
