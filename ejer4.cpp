#include <math.h>
#include <GL/glut.h>
#include <GL/gl.h> 
void display();
void specialKeys();
double rotate_y=0; //declaraciones de variables
double rotate_x=0;
double rotate_z =0; 
GLfloat X = 0.0f;
GLfloat Y = 0.0f;
GLfloat Z = 0.0f;
GLfloat scale = 1.0f; 
void display(){
  //  Borrar pantalla y Z-buffer
  glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glTranslatef(X, Y, Z); 	// traslaciones izquierda, derecha y alto

    // Otras transformaciones
    glScalef(scale, scale, scale);
  glRotatef( rotate_x, 1.0, 0.0, 0.0 );
  glRotatef( rotate_y, 0.0, 1.0, 0.0 );
  glRotatef(rotate_z, 0.0, 0.0, 1.0 ); 
  glBegin(GL_QUADS);
  glColor3f( 0.0, 0.0, 1.0 );
  glVertex3f(  0.5, -0.5, -0.5 );      //azul
  glColor3f( 1.0, 0.0, 0.0 );
  glVertex3f(  0.5,  0.5, -0.5 );      //rojo
  glColor3f( 1.0, 1.0, 1.0 ); 
  glVertex3f( -0.5,  0.5, -0.5 );      //blanco
  glColor3f( 1.0, 1.0, 0.0 );  
  glVertex3f( -0.5, -0.5, -0.5 );      // amarillo
 
  glEnd();
 
  //lado trasero color blanco
  glBegin(GL_QUADS);
  glColor3f(   1.0,  1.0, 1.0 );
  glVertex3f(  0.5, -0.5, 0.5 );
  glVertex3f(  0.5,  0.5, 0.5 );
  glVertex3f( -0.5,  0.5, 0.5 );
  glVertex3f( -0.5, -0.5, 0.5 );
  glEnd();
 
  // lado derecho color amarillo
  glBegin(GL_QUADS);
  glColor3f(  0.0,  1.0,  0.0 );
  glVertex3f( 0.5, -0.5, -0.5 );
  glVertex3f( 0.5,  0.5, -0.5 );
  glVertex3f( 0.5,  0.5,  0.5 );
  glVertex3f( 0.5, -0.5,  0.5 );
  glEnd();
 
  //lado izquierdo color verde
  glBegin(GL_QUADS);
  glColor3f(   1.0,  1.0,  0.0 );
  glVertex3f( -0.5, -0.5,  0.5 );
  glVertex3f( -0.5,  0.5,  0.5 );
  glVertex3f( -0.5,  0.5, -0.5 );
  glVertex3f( -0.5, -0.5, -0.5 );
  glEnd();
 
  //lado superior color vazul
  glBegin(GL_QUADS);
  glColor3f(   0.0,  0.0,  1.0 );
  glVertex3f(  0.5,  0.5,  0.5 );
  glVertex3f(  0.5,  0.5, -0.5 );
  glVertex3f( -0.5,  0.5, -0.5 );
  glVertex3f( -0.5,  0.5,  0.5 );
  glEnd();
 
  //lado inferior color rojo
  glBegin(GL_QUADS);
  glColor3f(   1.0,  0.0,  0.0 );
  glVertex3f(  0.5, -0.5, -0.5 );
  glVertex3f(  0.5, -0.5,  0.5 );
  glVertex3f( -0.5, -0.5,  0.5 );
  glVertex3f( -0.5, -0.5, -0.5 );
  glEnd();
 
  glFlush();
  glutSwapBuffers();
 
}
void specialKeys( int key, int x, int y ) {
 
  //  Flecha derecha: aumentar en grados
	if (key == GLUT_KEY_RIGHT)
    rotate_y += 1;
	else if (key == GLUT_KEY_LEFT)
    rotate_y -= 1; 
	else if (key == GLUT_KEY_UP)
    rotate_x += 1;
    else if (key == GLUT_KEY_DOWN)
    rotate_x -= 1;
	else if (key == GLUT_KEY_F2)
    rotate_z += 1;
	else if (key == GLUT_KEY_F2)
    rotate_z -= 1;
  glutPostRedisplay();
 
}
void fondo()
{
	glClearColor(0.1,0.2,0.2,0.0);
}
void keyboard(unsigned char key, int x, int y)
{
	
    switch (key)
    {
		
    case 115:
        scale -=0.2;
        break;
    case 83:
        scale +=0.2;
        break;
    case 120:
        X -= 0.1f;
        break;
    case 88:
        X += 0.1f;
        break;
    case 121:
        Y -= 0.1f;
        break;
    case 89:
        Y += 0.1f;
        break;
    case 'z':
        Z += 0.1f;
        break;
    case 'Z':
        Z -= 0.1f;
        break;
    case 27:
        exit(0);// exit
    }
    glutPostRedisplay(); // actualización de visualización
}
// Función “main()”
int main(int argc, char* argv[]){
  glutInit(&argc,argv);
		//  Solicitar ventana con color real y doble buffer con Z-buffer 
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(480,320);
	glutInitWindowPosition(400,150);
		// Crear ventana
	glutCreateWindow("Ejercicio 4");
		//  Habilitar la prueba de profundidad de Z-buffer
	glEnable(GL_DEPTH_TEST);
	fondo();
		// Funciones de retrollamada
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(specialKeys);
	glutMainLoop();
	return 0;
 
}
