#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>
void disply(void)
{
	glClear (GL_COLOR_BUFFER_BIT);
	glPointSize (5);
	glColor3f(1.0, 0.647, 0.0);
	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f (0.0f,0.7f,0.0f);
	glVertex3f (-0.32f,0.32f,0.0f);
	glVertex3f (0.32f,0.32f,0.0f);
glEnd();
	glColor3f(0.0, 1.0, 0.0);
	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f (-0.32f,0.32f,0.0f);
	glVertex3f (-0.7f,0.0f,0.0f);
		glVertex3f (-0.32f,-0.32f,0.0f);
glEnd();
	glBegin(GL_TRIANGLE_STRIP);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f (0.32f,-0.32f,0.0f);
	glVertex3f (0.0f,-0.7f,0.0f);
	glVertex3f (-0.32f,-0.32f,0.0f);
glEnd();
	glColor3f(0.0, 1.0, 0.0);
	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f (0.32f,0.32f,0.0f);
	glVertex3f (0.32f,-0.32f,0.0f);
	glVertex3f (0.7f,0.0f,0.0f);
glEnd();
	glColor3f(0.0, 0.0, 1.0);
	glBegin(GL_QUADS);
	glVertex3f (0.32f,0.32f,0.0f);
	glVertex3f (-0.32f,0.32f,0.0f);
	glVertex3f (-0.32f,-0.32f,0.0f);
	glVertex3f (0.32f,-0.32f,0.0f);
glEnd();
	glFlush();
}
void fondo()
{
	glClearColor(0.1,0.2,0.2,0.0);
}



void init(void)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity ();
	glOrtho (0.0,0.0,0.0,0.0,0.0,0.0);	
}	
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(480,320);
	glutInitWindowPosition(400,150);
	glutCreateWindow("Ejercicio 2");
	fondo();
	init();
	glutDisplayFunc(disply);
	glutMainLoop();
	return 0;
}



