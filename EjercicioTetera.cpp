#include <GL/glu.h>
#include <GL/glut.h>
//declacion de variables de tipo OpenGL 
GLfloat X = 0.0f;
GLfloat Y = 0.0f;
GLfloat Z = 0.2f;
GLfloat scale = 1.0f;
void init(void)
{
/* selecciona el color de borrado */
glClearColor (0.0, 0.0, 0.0, 0.0);
glShadeModel (GL_FLAT);
}
void display(void)
{
/* borra la pantalla */
glClear (GL_COLOR_BUFFER_BIT);
/* seleccionamos la matriz modelo/vista */
glMatrixMode(GL_MODELVIEW);
/* color */
glColor3f(0.0, 0.1, 0.0);
glLoadIdentity();
//Escalas
glScalef(scale, scale, scale);
//traslacion en xyz
glTranslatef(0.0, 0.0, 0.0);
glRotatef(25.0,0.3,0.0,0.2);
/* transformación modelo/vista */
gluLookAt(X,Y,Z, //punto de vista en el eje X,Y,Z
0.0,0.0,0.0, //Centro del Objeto en el eje X,Y,Z
0.0,1.0,0.0); //Orientación de la cámara (vector UP el eje X,Y,Z)
/* Dibujamos una tetera */
glutWireTeapot(0.5);
/* Vacia el buffer de dibujo */
glFlush ();
}
void fondo(){
	glClearColor(0.1,0.2,0.3,0.0);
	}
void keyboard(unsigned char key, int x, int y)
{
switch (key)
{
case '+':
scale +=0.2;
break;
case '-':
scale -=0.2;
break;
case 'x' :
X = 0.2f;
Y = 0.0f;
Z = 0.0f;
break;
case 'X' :
X = -0.2f;
Y = 0.0f;
Z = 0.0f;
break;
case 'y' :
X = 0.0f;
Y = 0.2f;
Z = 0.001f;
break;
case 'Y' :
X = 0.0f;
Y = -0.2f;
Z = 0.001f;
break;
case 'z':
X = 0.0f;
Y = 0.0f;
Z = 0.2f;
break;
case 'Z':
X = 0.0f;
Y = 0.0f;
Z = -0.2f;
break;
case 27:
exit(0); // exit
}
glutPostRedisplay(); // actualización de visualización
}
int main(int argc, char** argv)
{
// Inicializa la librería auxiliar GLUT
glutInit(&argc, argv);
// Inicializa el modo de visualización
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
// Indica el tamaño de la ventana (ancho,alto)
glutInitWindowSize(500, 500);
// Indica la posición inicial (xmin,ymin)
glutInitWindowPosition(100, 100);// Abre la ventana con el título indicado
glutCreateWindow("Tetera 3D Actividad");
// Inicializar valores
init();
// Indica cual es la función de dibujo
glutDisplayFunc(display);
fondo();
glutKeyboardFunc(keyboard); //invoca funcion de teclado
// Indica cual es la función para el cambio de tamaño de la ventana
//glutReshapeFunc(reshape);
// Comienza el bucle de dibujo y proceso de eventos.
glutMainLoop();
}
