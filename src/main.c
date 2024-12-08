/*==============*\
| Copyright 2024 |
| Tyler McGurrin |
\*==============*/

//include files
#include <stdio.h>
#include <stdint.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <string.h>

//Definitions and Vars
#define true 1;
#define false 0;
int GLPolyMode = GL_POLYGON;

GLfloat	RT = 0;

void Spin() {
	RT = RT + 0.005;
	if(RT > 360) RT = 0;
	glutPostRedisplay();
}

void Init() { //this function sets the colours
	glClearColor(0,0,0,1);
	glColor3f(0,1,0);
	glEnable(GL_DEPTH_TEST);
}

void Face(GLfloat A[],GLfloat B[],GLfloat C[],GLfloat D[]) {
	glBegin(GLPolyMode);	//use GL_POLYGON for solid object, GL_LINE_LOOP for wireframe and GL_POINTS for points
		glVertex3fv(A);
		glVertex3fv(B);
		glVertex3fv(C);
		glVertex3fv(D);
	glEnd();
	}

void Cube(	GLfloat V0[],
			GLfloat V1[],
			GLfloat V2[],
			GLfloat V3[],
			GLfloat V4[],
			GLfloat V5[],
			GLfloat V6[],
			GLfloat V7[]
			)
{ //Void Cube begins
	glColor3f(1,0,0); //set colour to red
	Face(V0,V1,V2,V3);
	
	glColor3f(0,0,1); //set colour to Blue
	Face(V0,V3,V7,V4);
	
	glColor3f(0,1,0); //set colour to green
	Face(V4,V5,V6,V7);

	glColor3f(1,0,1); //set colour to purple
	Face(V1,V2,V6,V5);

	glColor3f(1,1,0); //set colour to yellow
	Face(V0,V1,V5,V4);

	glColor3f(0,1,1); //set colour to teal
	Face(V3,V2,V6,V7);
}



void Draw() {
	GLfloat Vertices[8][3] = {
								{-0.5,0.5,0.5},	
								{0.5,0.5,0.5},	
								{0.5,-0.5,0.5},	
								{-0.5,-0.5,0.5}
								,
								{-0.5,0.5,-0.5},	
								{0.5,0.5,-0.5},	
								{0.5,-0.5,-0.5},	
								{-0.5,-0.5,-0.5},	
							 };
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	Cube(	Vertices[0],
			Vertices[1],
			Vertices[2],
			Vertices[3],
			Vertices[4],
			Vertices[5],
			Vertices[6],
			Vertices[7]
			);

	glRotatef(RT,1,.5,.5);
	glutSwapBuffers();
}

int main(int argC, char *argV[])
{

    glutInit(&argC,argV);
	if (argC > 1) {
	    for (int i = 1; i < argC; i++) {
	        if (strcmp(argV[i], "-v") == 0) {
	            printf("OpenGL Spinning Cube Demo Version: 1.1\n");
	            return true;
	        } else if (strcmp(argV[i], "-h") == 0) {
	            printf("Usage: cube [-v] [-h] [-w]\n");
	            return true;
	            } else if (strcmp(argV[i], "-w") == 0) {
	                printf("Wireframe Mode Enabled\n");
	                GLPolyMode = GL_LINE_LOOP;
	        } else {
	            printf("Unknown option: %s\n", argV[i]);
	            return false;
	        }
	    }
	}
	//glutInitWindowPosition(0,0); //Readd this later (TM)
	glutInitWindowSize(512,512); //window size
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); //display mode
	glutCreateWindow("OpenGL Spinning Cube"); //make window
	Init();	
	glutDisplayFunc(Draw);
	glutIdleFunc(Spin); //calls spin when idle
	glutMainLoop();
    return true;
}
