#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>
void disply(void)
{
	glClear (GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);
	glPointSize (8);
	glBegin(GL_POINTS);
	float a=0,b=0;	float n=50;float x=0;float y=0; float r=0.5;//variables
	a=360/n;
	float t=0;
for (float i = 1.0 ; i <= n ; i++)
	{
		//glVertex3f (0.0f,0.0f,0.0f);
		y=r*(cos((t*3.141592654)/180));
		x=r*(sin((t*3.141592654)/180));
		glVertex3f (x,y,0.0);
		t=t+a;
		//glVertex3f (x,y,0.0);
	}
glEnd();
	glFlush();
}
void init(void)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity ();
	glOrtho (1.0,-1.0, 1.0,-1.0,1.0,-1.0);	
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
	glutCreateWindow("Ejercicio 1");
	init();
	fondo();
	glutDisplayFunc(disply);
	glutMainLoop();
	return 0;
}



