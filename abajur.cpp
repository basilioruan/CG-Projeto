#include <GL/glut.h>
#include <stdlib.h>
#include <SOIL/SOIL.h>
#include <iostream>

using namespace std;

static int tampa = 0, rotacao = 100;
int xGlobal = 0;
bool apagado = false;

GLfloat R = 1;
GLfloat G = 1;
GLfloat B = 0;

#define BRANCO    1, 1, 1
#define CINZA 0.2, 0.2, 0.2

static GLuint texName;

void init(void) 
{
   glClearColor (0.0, 0.0, 0.0, 0.0);

   glShadeModel (GL_FLAT);
   glEnable(GL_LIGHTING);
   glEnable(GL_LIGHT0);
   glEnable(GL_COLOR_MATERIAL);
   glEnable(GL_DEPTH_TEST);
   
   glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

   glGenTextures(1, &texName);
   glBindTexture(GL_TEXTURE_2D, texName);

   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

   //luz global
   float luzAmbienteGlobal[] = {0.5f, 0.5f, 0.5f, 1.0f};
   glLightModelfv(GL_LIGHT_MODEL_AMBIENT, luzAmbienteGlobal);

   //parametros segunda luz
   float light0[4][4] = {
      {0.4f, 0.4f, 0.0f, 1.0f}, //ambiente
      {0.8f, 0.8f, 0.8f, 1.0f}, // difusa
      {1.0f, 1.0, 1.0f, 1.0f}, // specular
      {0.0, -0.45, -3.5, 1.0} // posição
   };

   // segunda luz
   glLightfv(GL_LIGHT0, GL_AMBIENT, &light0[0][0]);
   glLightfv(GL_LIGHT0, GL_DIFFUSE, &light0[1][0]);
   glLightfv(GL_LIGHT0, GL_SPECULAR, &light0[2][0]);
   glLightfv(GL_LIGHT0, GL_POSITION, &light0[3][0]);

}

void display(void)
{
   glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   glColor3f(BRANCO);

   int width, height;

   unsigned char* image = SOIL_load_image("img2.jpg", &width, &height, 0, SOIL_LOAD_RGB);

   glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);   

   SOIL_free_image_data(image);

   glEnable(GL_TEXTURE_2D);

   glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
   glBindTexture(GL_TEXTURE_2D, texName);

   glBegin(GL_QUADS);
   glTexCoord2f(0.0, 0.0); glVertex3f(-4.0, 1.0, -2.0);
   glTexCoord2f(0.0, 1.0); glVertex3f(-4.0, 3.0, -2.0);
   glTexCoord2f(1.0, 1.0); glVertex3f(-1.0, 3.0, -2.0);
   glTexCoord2f(1.0, 0.0); glVertex3f(-1.0, 1.0, -2.0);
   glEnd();


   image = SOIL_load_image("img.jpeg", &width, &height, 0, SOIL_LOAD_RGB);
   glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image); 
   SOIL_free_image_data(image);

   glBegin(GL_QUADS);
   glTexCoord2f(0.0, 0.0); glVertex3f(0.0, 1.0, -2.0);
   glTexCoord2f(0.0, 1.0); glVertex3f(0.0, 3.0, -2.0);
   glTexCoord2f(1.0, 1.0); glVertex3f(2.0, 3.0, -2.0);
   glTexCoord2f(1.0, 0.0); glVertex3f(2.0, 1.0, -2.0);
   glEnd();

   glDisable(GL_TEXTURE_2D);
   
   glPushMatrix();
   glRotatef(10.0f,1.0f,0.0f,0.0f);
   glRotatef((GLfloat)rotacao, 0, 1, 0);


   //FACE 1
   glColor3f(CINZA);
   glPushMatrix();
   glScalef(2.0, 2, 0.3);
   glutSolidCube(1.0);
   glPopMatrix();

   //FACE 2
   glColor3f(CINZA);
   glPushMatrix();
   glTranslatef(1.17, 0, 0);
   glRotatef(90, 0.0, 1.0, 0.0);
   glTranslatef(1.02, 0.0, 0.0);
   glPushMatrix();
   glScalef(2.34, 2, 0.3);
   glutSolidCube(1.0);
   glPopMatrix();

   //FACE 4
   glColor3f(CINZA);
   glPushMatrix();
   glTranslatef(1.02, 0, 0);
   glRotatef(90, 0.0, 1.0, 0.0);
   glTranslatef(1.16, 0.0, 0.0);
   glPushMatrix();
   glScalef(2.05, 2, 0.3);
   glutSolidCube(1.0);
   glPopMatrix();

   //FACE cima
   glColor3f(CINZA);
   glPushMatrix();
   glTranslatef(-1.1, 1.14, 0);
   glRotatef(90, 1.0, 0, 0.0);
   glTranslatef(1.1, -1.02, 0.0);
   glPushMatrix();
   glScalef(2.62, 2.33, 0.3);
   glutSolidCube(1.0);
   glPopMatrix();
   glPopMatrix();

   //FACE baixo
   glColor3f(CINZA);
   glPushMatrix();
   glTranslatef(-1.1, -1.14, 0);
   glRotatef(90, 1.0, 0, 0.0);
   glTranslatef(1.1, -1.02, 0.0);
   glPushMatrix();
   glScalef(2.62, 2.33, 0.3);
   glutSolidCube(1.0);
   glPopMatrix();
   glPopMatrix();

   //lampada
   glPushMatrix();
   glTranslatef(0.0, -0.45, -1.0);
   glColor3f(R, G, B);
   glutSolidSphere(0.3, 50.0, 50); 
   glPopMatrix();

   //Base lampada
   glPushMatrix();
   glColor3f(CINZA);
   glTranslatef(0.0, -0.8, -1.0);
   glScalef(0.2, 0.2, 0.2);
   glutSolidCube(1); 
   glPopMatrix();

   //FACE 3 porta
   glColor3f(CINZA);
   glPushMatrix();
   glTranslatef(1.17, 0.77, 0);
   glRotatef(90, 0.0, 1.0, 0.0);
   glRotatef((GLfloat)tampa, 1.0, 0.0, 0.0);
   glTranslatef(1.02, 0.0, 0.0);
   glPushMatrix();
   glScalef(2.35, 0.46, 0.3);
   glutSolidCube(1.0);
   glPopMatrix();

   glColor3f(CINZA);
   glPushMatrix();
   glTranslatef(0, -1.54, 0);
   glPushMatrix();
   glScalef(2.35, 0.46, 0.3);
   glutSolidCube(1.0);
   glPopMatrix();

   glColor3f(CINZA);
   glPushMatrix();
   glTranslatef(-0.85, 0.75, 0);
   glPushMatrix();
   glScalef(0.65, 1.12, 0.3);
   glutSolidCube(1.0);
   glPopMatrix();

   glColor3f(CINZA);
   glPushMatrix();
   glTranslatef(1.7, 0, 0);
   glPushMatrix();
   glScalef(0.65, 1.12, 0.3);
   glutSolidCube(1.0);
   glPopMatrix();
   
   glPopMatrix();
   glPopMatrix();
   glPopMatrix();   
   glPopMatrix();   
   glPopMatrix();   
   glPopMatrix();
   
   glPopMatrix();

   glutSwapBuffers();
}

void reshape (int w, int h)
{
   glViewport (0, 0, (GLsizei) w, (GLsizei) h); 
   glMatrixMode (GL_PROJECTION);
   glLoadIdentity ();
   gluPerspective(65.0, (GLfloat) w/(GLfloat) h, 1.0, 20.0);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   glTranslatef (0.0, 0.0, -5.0);
}

void keyboard (unsigned char key, int x, int y)
{
   switch (key) {
      //Acende e apaga a luz
      case 'a':
         if(apagado){
            apagado = false;
            R = 1;
            G = 1;
            B = 0;
            glEnable(GL_LIGHT0);         
         }
         else{
            apagado = true;
            R = 0.7;
            G = 0.7;
            B = 0.7;
            glDisable(GL_LIGHT0);
         }
         glutPostRedisplay();
         break;
      //Volta a localização para o início
      case 'q':
         rotacao = 100;
         tampa = 0;
         glutPostRedisplay();
         break;
      //Rotaciona o abajur
      case 'r':
         rotacao = (rotacao + 5) % 360;
         glutPostRedisplay();
         break;
      //Rotaciona o abajur
      case 'R':
         rotacao = (rotacao - 5) % 360;
         glutPostRedisplay();
         break;
      //Abre a tampa
      case 's':
         if(tampa != -105){
            tampa = (tampa - 5) % 360;
         }
         glutPostRedisplay();
         break;
      //Fecha a tampa
      case 'S':
         if(tampa != 0){
            tampa = (tampa + 5) % 360;
         }
         glutPostRedisplay();
         break;
      //Fecha a janela (ESC)
      case 27:
         exit(0);
         break;
      default:
         break;
   }
}

void MotionMouse(int x, int y) {
  if(x < xGlobal)
    rotacao -= 2.0f;

  else
    rotacao += 2.0f;
  
  xGlobal = x;
  glutPostRedisplay();
}

void MouseClick(int button, int state, int x, int y)
{
    if (button == GLUT_RIGHT_BUTTON)
      if (state == GLUT_DOWN) {
         if(apagado){
            apagado = false;
            R = 1;
            G = 1;
            B = 0;
            glEnable(GL_LIGHT0);         
         }
         else{
            apagado = true;
            R = 0.7;
            G = 0.7;
            B = 0.7;
            glDisable(GL_LIGHT0);
         }
         glutPostRedisplay();
      }
}

int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGB);
   glutInitWindowSize (1200, 900); 
   glutInitWindowPosition (100, 100);
   glutCreateWindow ("CG - Projeto pratico");
   init ();
   glutDisplayFunc(display); 
   glutReshapeFunc(reshape);
   glutKeyboardFunc(keyboard);
   glutMotionFunc(MotionMouse);
   glutMouseFunc(MouseClick);
   glutMainLoop();
   return 0;
}