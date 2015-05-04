#include <cmath>
#include <utility>
#include <GL/glut.h>
#include <SOIL/SOIL.h>
#include <vector>
#include <sstream>
#include "Vector3D.h"
#include "Sphere.h"
#include "Color.h"
#include "Ray.h"

using namespace std;
Sphere *s = new Sphere(0.,3.,4.,5.,RED);
Vector3D v;
GLfloat xRotated, yRotated, zRotated;
bool save = false;
int count;

void drawSphere(void){
	glMatrixMode(GL_MODELVIEW);
	    // clear the drawing buffer.
	    glClear(GL_COLOR_BUFFER_BIT);
	    // clear the identity matrix.
	    glLoadIdentity();
	    // traslate the draw by z = -4.0
	    // Note this when you decrease z like -8.0 the drawing will looks far , or smaller.
	    glTranslatef(0.0,0.0,-4.5);
	    // Red color used to draw.
	    glColor3f(0.8, 0.2, 0.1);
	    // changing in transformation matrix.
	    // rotation about X axis
	    glRotatef(xRotated,1.0,0.0,0.0);
	    // rotation about Y axis
	    glRotatef(yRotated,0.0,1.0,0.0);
	    // rotation about Z axis
	    glRotatef(zRotated,0.0,0.0,1.0);
	    // scaling transfomation
	    glScalef(1.0,1.0,1.0);
	    // built-in (glut library) function , draw you a sphere.
	    glutSolidSphere((*s).radius(),20,20);
	    // Flush buffers to screen

	    glFlush();
	    if(save){
	    	int w = glutGet(GLUT_WINDOW_WIDTH);
	    	int h = glutGet(GLUT_WINDOW_HEIGHT);
	    	vector<unsigned char> buf(w*h*3);
	    	glPixelStorei(GL_PACK_ALIGNMENT,1);
	    	glReadPixels(0,0,w,h,GL_RGB,GL_UNSIGNED_BYTE,&buf[0]);
	    	stringstream s;
	    	s << count;
	    	string ss = s.str();
	    	int err = SOIL_save_image(ss.c_str(), SOIL_SAVE_TYPE_BMP,w, h, 3,&buf[0]);
	    	cout << err;
	    	count++;
	    	save = false;
	    }
}
void setSphere(Sphere* k){
	s = k;
}

void reshapeFunc(int x, int y)
{
    if (y == 0 || x == 0) return;  //Nothing is visible then, so return
    //Set a new projection matrix
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //Angle of view:40 degrees
    //Near clipping plane distance: 0.5
    //Far clipping plane distance: 20.0

    gluPerspective(40.0,(GLdouble)x/(GLdouble)y,0.5,20.0);
    glMatrixMode(GL_MODELVIEW);
    glViewport(0,0,x,y);  //Use the whole window for rendering
}

void idleFunc(void)
{

    yRotated += 0.01;
    drawSphere();
}

void keyboard( unsigned char key, int x, int y )
{
    if( key == 's' )
    {
        save = true;
        glutPostRedisplay();
    }
}

void displaySphere(){
	    //double buffering used to avoid flickering problem in animation
	    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	    // window size
	    glutInitWindowSize(1000,3500);
	    // create the window
	    glutCreateWindow("Sphere Rotating Animation");
	    glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
	    glClearColor(0.0,0.0,0.0,0.0);
	    //Assign  the function used in events
	    glutDisplayFunc(drawSphere);
	    glutReshapeFunc(reshapeFunc);
	    glutIdleFunc(idleFunc);
	    glutKeyboardFunc(keyboard);
	    //Let start glut loop
	    glutMainLoop();
}

