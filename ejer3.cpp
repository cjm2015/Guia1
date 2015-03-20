#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>
void disply(void)
{
	glClear (GL_COLOR_BUFFER_BIT);
	glPointSize (5);
	glColor3f(0.5, 0.7, 0.98);
	glBegin(GL_QUADS);//cuerpo del avion
	glVertex3f (-0.8f,0.15f,0.0f);
	glVertex3f (-0.8f,-0.15f,0.0f);
	glVertex3f (0.7f,-0.15f,0.0f);
	glVertex3f (0.7f,0.15f,0.0f);
glEnd();
	glColor3f(0.847,0.749,0.8471);//parte frontal del avion
	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f (0.7f,0.2f,0.0f);
	glVertex3f (0.7f,-0.2f,0.0f);
	glVertex3f (1.0f,0.0f,0.0f);
glEnd();
	glColor3f(0.5,0.184313,0.609804);
	glBegin(GL_QUADS);//propulsor superior trasero
	glVertex3f (-0.9f,0.025f,0.0f);
	glVertex3f (-0.9f,0.1f,0.0f);
	glVertex3f (-0.8f,0.1f,0.0f);
	glVertex3f (-0.8f,0.025f,0.0f);
glEnd();
	glColor3f(0.5,0.184313,0.609804);
	glBegin(GL_QUADS);//propulsor inferio trasero
	glVertex3f (-0.9f,-0.025f,0.0f);
	glVertex3f (-0.9f,-0.1f,0.0f);
	glVertex3f (-0.8f,-0.1f,0.0f);
	glVertex3f (-0.8f,-0.025f,0.0f);
glEnd();
	//ALA SUPERIOR
	glColor3f(0.4, 0.8039, 0.6666);
	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f (0.0f,0.45f,0.0f);
	glVertex3f (-0.4f,0.15f,0.0f);
	glVertex3f (0.5f,0.15f,0.0f);
glEnd();
	glColor3f(0.30196, 0.8196, 0.8);
	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f (0.0f,0.45f,0.0f);
	glVertex3f (-0.8f,0.45f,0.0f);
	glVertex3f (-0.4f,0.15f,0.0f);
glEnd();
	//ALA INFERIOR
	glColor3f(0.4, 0.8039, 0.6666);
	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f (0.0f,-0.45f,0.0f);
	glVertex3f (0.5f,-0.15f,0.0f);
	glVertex3f (-0.4f,-0.15f,0.0f);
glEnd();
	glColor3f(0.30196, 0.8196, 0.8);
	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f (0.0f,-0.45f,0.0f);
	glVertex3f (-0.8f,-0.45f,0.0f);
	glVertex3f (-0.4f,-0.15f,0.0f);
glEnd();
	glFlush();
}
void init(void)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity ();
	glOrtho (0.0,0.0,0.0,0.0,0.0,0.0);	
}	
void fondo()
{
	glClearColor(0.1,0.2,0.2,0.0);
}
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(480,320);
	glutInitWindowPosition(400,150);
	glutCreateWindow("Ejercicio 3");
	init();
	fondo();
	glutDisplayFunc(disply);
	glutMainLoop();
	return 0;
}



