/*==============*\
| Copyright 2024 |
| Tyler McGurrin |
\*==============*/

//include files
#include <stdio.h>
#include <stdint.h>
#include <GL/glu.h>
#include <GL/glut.h>

//Definitions and Vars
#define true 1;
#define false 0;

void ColourInit() {
	glClearColor(0,0,0,1);
	glColor3f(0,1,0);
}

void Draw()
{
	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_LINE_LOOP);	//use GL_POLYGON for solid object, GL_LINE_LOOP for wireframe and GL_POINTS for points
		glVertex2f(-0.5,0.5);
		glVertex2f(0.5,0.5);
		glVertex2f(0.5,-0.5);
		glVertex2f(-0.5,-0.5);
	glEnd();

	glFlush();
}

int main(int argC, char *argV[])
{
    glutInit(&argC,argV);

	//glutInitWindowPosition(0,0); //Readd this later (TM)
	glutInitWindowSize(800,600);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutCreateWindow("OpenGL Test");
	ColourInit();	
	glutDisplayFunc(Draw);
	glutMainLoop();
    return true;
}
