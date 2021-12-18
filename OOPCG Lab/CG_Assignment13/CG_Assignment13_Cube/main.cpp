#define GLUT_DISABLE_ATEXIT_HACK
#include<windows.h>
#include <math.h>
#include <GL\glut.h>
#include <iostream>
using namespace std;

GLfloat xTranslate =0.0, yTranslate = 0.0, zTranslate = -10.5;
GLfloat xRotated =0.0, yRotated=0.0, zRotated=0.0;
GLfloat xScale = 2.0, yScale=2.0, zScale=2.0;

void init(void)
{
glClearColor(0,0,0,0);
}

void DrawCube(void)
{
glMatrixMode(GL_MODELVIEW);
// clear the drawing buffer.
glClear(GL_COLOR_BUFFER_BIT);
glLoadIdentity();

// to translate
//glTranslatef(0.0,0.0,-10.5); // default values

glTranslatef(xTranslate, yTranslate, zTranslate);

glRotatef(xRotated,1.0,0.0,0.0);
// rotation about Y axis
glRotatef(yRotated,0.0,1.0,0.0);
// rotation about Z axis
glRotatef(zRotated,0.0,0.0,1.0);

// to scale
// glScalef(2.0,2.0,2.0);  // default values
glScalef(xScale, yScale, zScale);


glBegin(GL_QUADS); // Draw The Cube Using quads

glColor3f(0.0f,1.0f,0.0f); // Color Blue
glVertex3f( 1.0f, 1.0f,-1.0f); // Top Right Of The Quad (Top)
glVertex3f(-1.0f, 1.0f,-1.0f); // Top Left Of The Quad (Top)
glVertex3f(-1.0f, 1.0f, 1.0f); // Bottom Left Of The Quad (Top)
glVertex3f( 1.0f, 1.0f, 1.0f); // Bottom Right Of The Quad (Top)
glColor3f(1.0f,0.5f,0.0f); // Color Orange
glVertex3f( 1.0f,-1.0f, -1.0f); // Top Right Of The Quad (Bottom)
glVertex3f(-1.0f,-1.0f, -1.0f); // Top Left Of The Quad (Bottom)
glVertex3f(-1.0f,-1.0f,1.0f); // Bottom Left Of The Quad (Bottom)
glVertex3f( 1.0f,-1.0f,1.0f); // Bottom Right Of The Quad (Bottom)
glColor3f(1.0f,0.0f,0.0f); // Color Red
glVertex3f( 1.0f, 1.0f, 1.0f); // Top Right Of The Quad (Front)
glVertex3f(-1.0f, 1.0f, 1.0f); // Top Left Of The Quad (Front)
glVertex3f(-1.0f,-1.0f, 1.0f); // Bottom Left Of The Quad (Front)
glVertex3f( 1.0f,-1.0f, 1.0f); // Bottom Right Of The Quad (Front)
glColor3f(1.0f,1.0f,0.0f); // Color Yellow
glVertex3f( 1.0f,1.0f,-1.0f); // Top Right Of The Quad (Back)
glVertex3f(-1.0f,1.0f,-1.0f); // Top Left Of The Quad (Back)
glVertex3f(-1.0f, -1.0f,-1.0f); // Bottom Left Of The Quad (Back)
glVertex3f( 1.0f, -1.0f,-1.0f); // Bottom Right Of The Quad (Back)
glColor3f(0.0f,0.0f,1.0f); // Color Blue
glVertex3f(-1.0f, 1.0f, 1.0f); // Top Right Of The Quad (Left)
glVertex3f(-1.0f, 1.0f,-1.0f); // Top Left Of The Quad (Left)
glVertex3f(-1.0f,-1.0f,-1.0f); // Bottom Left Of The Quad (Left)
glVertex3f(-1.0f,-1.0f, 1.0f); // Bottom Right Of The Quad (Left)
glColor3f(1.0f,0.0f,1.0f); // Color Violet
glVertex3f( 1.0f, 1.0f,-1.0f); // Top Right Of The Quad (Right)
glVertex3f( 1.0f, 1.0f, 1.0f); // Top Left Of The Quad (Right)
glVertex3f( 1.0f,-1.0f, 1.0f); // Bottom Left Of The Quad (Right)
glVertex3f( 1.0f,-1.0f,-1.0f); // Bottom Right Of The Quad (Right)



glEnd(); // End Drawing The Cube
glFlush();
}


void animation(void)
{
yRotated += 0.01;
xRotated += 0.02;
DrawCube();
}


void reshape(int x, int y)
{
if (y == 0 || x == 0) return; //Nothing is visible then, so return
//Set a new projection matrix
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
//Angle of view:40 degrees
//Aspect ratio
//Near clipping plane distance: 0.5
//Far clipping plane distance: 20.0

gluPerspective(40.0,(GLdouble)x/(GLdouble)y,0.5,20.0);
glMatrixMode(GL_MODELVIEW);
glViewport(0,0,x,y); //Use the whole window for rendering
}



int main(int argc, char** argv){



glutInit(&argc, argv);
//we initizlilze the glut. functions
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
glutInitWindowPosition(100, 100);
glutCreateWindow("3D CUBE");
init();
glutDisplayFunc(DrawCube);

string choiceScale;
cout<< "Want to scale? (y/n): ";
cin>>choiceScale;
if (choiceScale == "y") {
    cout << "\nEnter Scaling factor (Sx, Sy, Sz): ";
    cin >> xScale >> yScale >> zScale;
    cout << "\nScaling factor input successful." << endl;
} else {
    cout << "\nScaling factor not inputed." << endl;
}

string choiceTranslate;
cout << "Want to translate? (y/n): ";
cin>>choiceTranslate;
if (choiceTranslate == "y") {
    cout<< "\nEnter Translate co-ordinates: ";
    cin >> xTranslate >> yTranslate >> zTranslate;
    cout << "\nScaling factor input successful." << endl;
} else {
    cout << "\nTranslate co-ordinates not inputed." <<endl;
}



glutReshapeFunc(reshape);
//Set the function for the animation.
glutIdleFunc(animation);
glutMainLoop();
return 0;
}
