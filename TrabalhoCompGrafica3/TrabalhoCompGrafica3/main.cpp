#include <stdio.h>
#include <stdarg.h>
#include <math.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include "SOIL.h"
#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <string>

using namespace std;

// Declarações de Funções

void display();
void specialKeys();
void timer();
void desenhaCubo();
void init();
void initTextures();

// Variáveis Globais

GLfloat tamanhoJanela = 0.5f;
double rotate_y = 0;
double rotate_x = 0;
GLfloat move_y = 0;
GLfloat move_x = 0;
GLfloat xstep = 0.02f;
GLfloat ystep = 0.05f;
GLuint texture[6];
float tamanho = 0.5f;

// função display()

void display() {
    
    //  Limpa a tela e o Z-Buffer
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    // Reinicia transformações
    glLoadIdentity();
    
    // Move quando o usuário muda move_x e move_y
    glTranslatef(move_x, move_y, 0.0); // Não está incluído
    
    // Rotaciona quando o usuário muda rotate_x e rotate_y
    glRotatef(rotate_x, 1.0, 0.0, 0.0);
    glRotatef(rotate_y, 0.0, 1.0, 0.0);
    
    // Typical Texture Generation Using Data From The Bitmap
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    
    //                     CUBO
    desenhaCubo();
    glutSwapBuffers();
}

// função desenhaCubo() desenha e define onde aparece cada textura

void desenhaCubo() {
    
    // Frente
    glBindTexture(GL_TEXTURE_2D, texture[3]);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-tamanho, -tamanho, tamanho);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(tamanho, -tamanho, tamanho);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(tamanho, tamanho, tamanho);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-tamanho, tamanho, tamanho);
    glEnd();
    
    // Trás
    glBindTexture(GL_TEXTURE_2D, texture[2]);
    glBegin(GL_QUADS);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-tamanho, -tamanho, -tamanho);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-tamanho, tamanho, -tamanho);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(tamanho, tamanho, -tamanho);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(tamanho, -tamanho, -tamanho);
    glEnd();
    
    // Cima
    glBindTexture(GL_TEXTURE_2D, texture[0]);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-tamanho, tamanho, -tamanho);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-tamanho, tamanho, tamanho);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(tamanho, tamanho, tamanho);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(tamanho, tamanho, -tamanho);
    glEnd();
    
    // Baixo
    glBindTexture(GL_TEXTURE_2D, texture[1]);
    glBegin(GL_QUADS);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(tamanho, -tamanho, -tamanho);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-tamanho, -tamanho, -tamanho);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-tamanho, -tamanho, tamanho);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(tamanho, -tamanho, tamanho);
    glEnd();
    
    // Right face
    glBindTexture(GL_TEXTURE_2D, texture[4]);
    glBegin(GL_QUADS);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(tamanho, -tamanho, -tamanho);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(tamanho, tamanho, -tamanho);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(tamanho, tamanho, tamanho);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(tamanho, -tamanho, tamanho);
    glEnd();
    
    // Left Face
    glBindTexture(GL_TEXTURE_2D, texture[5]);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-tamanho, -tamanho, -tamanho);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-tamanho, -tamanho, tamanho);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-tamanho, tamanho, tamanho);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-tamanho, tamanho, -tamanho);
    glEnd();
    
}



// Função timer() que faz o timer do giro()


void timer(int value) {
    
    if (move_x > tamanhoJanela || move_x < -tamanhoJanela)
        xstep = -xstep;
    
    if (move_y > tamanhoJanela || move_y < -tamanhoJanela)
        ystep = -ystep;
    
    move_x += xstep;
    move_y += ystep;
    
    glutPostRedisplay();
    glutTimerFunc(33, timer, 1);
}


// Função specialKeys()  Movimenta o cubo com o teclado()


void specialKeys(int key, int x, int y) {
    
    if (key == GLUT_KEY_RIGHT)
        rotate_y += 5;
    
    else if (key == GLUT_KEY_LEFT)
        rotate_y -= 5;
    
    else if (key == GLUT_KEY_UP)
        rotate_x += 5;
    
    else if (key == GLUT_KEY_DOWN)
        rotate_x -= 5;
    
    else if (key == GLUT_KEY_F5)
        glutTimerFunc(33, timer, 5);
    
    //  Requisitar atualização do display
    glutPostRedisplay();
    
}


// Função init() Inicializa as texturas

void initTextures() {
    //cima
    texture[0] = SOIL_load_OGL_texture("/Users/jonasgomes/Desktop/Projetos/ComputacaoGrafica/TrabalhoCompGrafica3/TrabalhoCompGrafica3/images/dede.jpg", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
    
    //baixo
    texture[1] = SOIL_load_OGL_texture("/Users/jonasgomes/Desktop/Projetos/ComputacaoGrafica/TrabalhoCompGrafica3/TrabalhoCompGrafica3/images/img3.jpg", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
    
    //frente
    texture[2] = SOIL_load_OGL_texture("/Users/jonasgomes/Desktop/Projetos/ComputacaoGrafica/TrabalhoCompGrafica3/TrabalhoCompGrafica3/images/img4.jpg", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
    
    //costa
    texture[3] = SOIL_load_OGL_texture("/Users/jonasgomes/Desktop/Projetos/ComputacaoGrafica/TrabalhoCompGrafica3/TrabalhoCompGrafica3/images/thanos.jpg", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
    
    //direito
    texture[4] = SOIL_load_OGL_texture("/Users/jonasgomes/Desktop/Projetos/ComputacaoGrafica/TrabalhoCompGrafica3/TrabalhoCompGrafica3/images/img2.jpg", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
    
    //esquerdo
    texture[5] = SOIL_load_OGL_texture("/Users/jonasgomes/Desktop/Projetos/ComputacaoGrafica/TrabalhoCompGrafica3/TrabalhoCompGrafica3/images/img1.jpg", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
}

// Função init() Inicializa parâmetros de rendering


void init() {
    glEnable(GL_TEXTURE_2D);
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    glShadeModel(GL_SMOOTH); // Enable Smooth Shading
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Black Background
    glClearDepth(1.0f); // Depth Buffer Setup
    glEnable(GL_DEPTH_TEST); // Enables Depth Testing
    glDepthFunc(GL_LEQUAL); // The Type Of Depth Testing To Do
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST); // Really Nice Perspective Calculations
}


// Função main()


int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(150, 120);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Trabalho - Cubo Movimento com F5");
    
    init();
    initTextures();
    
    // Funções
    glutDisplayFunc(display);
    glutSpecialFunc(specialKeys);
    
    //  Passa o controle dos eventos para o GLUT
    glutMainLoop();
    
    return 0;
    
}

