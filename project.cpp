#include "GL/freeglut.h"
#include<iostream>
const double G=9.8;
const double k=101.9;//define una expresin para los valores de la gravedad y la constante eslastica;
int contador=0;

struct Ball{// La estructura de la pelota
  double x;
  double y;//posicion centro de la bola

  float masa ;
  double radio;

	double vy; //velocidad inicial
  double fy;
};

Ball pelota{0,6,2,0.22,0,0};





//declara las funciones
void drawbol();// intruccion de o que se dibuja  en pantalla
void timer(int value);//timer que actualza la pantalla cada cierto tiempo
void reshape(int w,int h);//redimensiona la pantalla

int main(int argc, char **argv)
{


    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);// instrucciones generar la ventana visualizar
    glutInitWindowSize(700, 700);//tamaño ventana visualizar
    glutInitWindowPosition(0, 0);//posiciien de esta
    glutCreateWindow("OpenGL - bola cayendo");//titulo ventana



    glutDisplayFunc(drawbol);//funcion saca por pantalla desea dibujar
    glutReshapeFunc(reshape);//llama e la funcion que redimensiona y aplica las dimensiones deseadas
    glutTimerFunc(1000, timer,0);//funcion vuelve a llamarse  a si misma en un tiempo de  1s
    glutMainLoop();
    return 0;
}



//intrucciones funciones


void drawbol()
{
glClear(GL_COLOR_BUFFER_BIT); //limpia pantalla
glLoadIdentity();
glColor3f(1.0,2.0,0.0);//modela el piso como una linea(color de la linea)
glBegin(GL_LINES);//instruccion dibuja lineas

  glVertex2f(-10.0,0.0); //Vertices de las lineas
  glVertex2f(10.0,0.0);//vertices en - 8 unidades para que se pueda visualizar bien

  glVertex2f(-10.0,9.0); //Vertices de las lineas
  glVertex2f(10.0,9.0);//vertices en - 8 unidades para que se pueda visualizar bien

  glVertex2f(-10.0,10.0); //Vertices de las lineas
  glVertex2f(10.0,10.0);//vertices en - 8 unidades para que se pueda visualizar bien




glEnd();

    glColor3f(2.0, 1.0, 5.0); //color de la bola
    glTranslated(pelota.x,pelota.y,0);//posicion de la bola
    glutSolidSphere(pelota.radio, 60, 60);//instruccion radio de la bola y lo redonda que es



glFlush();
glutSwapBuffers();

}


void timer(int value) //for
{
	glutPostRedisplay();//dibuja en pantalla
	glutTimerFunc(1,timer,0);// en un segundo esta funcion se llama cada milisengundo(llama a si misma 1000 veces)

  // esta funcion  timer modifica parametros estructura modela la posicion pelota
double dt=0.001;
  //metodo de euler
  if(pelota.radio-pelota.y>0){


  pelota.fy = -pelota.masa*G+k*(pelota.radio-pelota.y);//la fuerza piso actua radio de interpeneracion es mayor a cero

  }
  else{
    pelota.fy = -pelota.masa*G;
  }

  pelota.y=pelota.y+dt*pelota.vy;//actualiza posicion de la pelota
  pelota.vy = pelota.vy + dt*pelota.fy/pelota.masa;//actualiza la velocidad
  double tiempo=contador*dt;
  contador=contador+1;


  std::cout<<tiempo<< "\t"
               <<pelota.y<< pelota.vy<<std::endl;
               pelota.fy = 0.0;// resetea la fuerza;

}





//redimensiona de manera adecuada lo dibujado en  pantalla;
void reshape(int w,int h){
	glViewport(0,0,(GLsizei)w,(GLsizei)h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(-14,14,-2,26);//sistema carteciano  28x28 unidades
  glMatrixMode(GL_MODELVIEW);

}
